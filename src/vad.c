#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "vad.h"
#include "pav_analysis.h"

const float FRAME_TIME = 10.0F; /* in ms. */
const int MAX_TRAMAS = 3;

/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */

const char *state_str[] = {
  "UNDEF", "S", "V", "INIT", "MV", "MS"
};

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float p;
  float am;
} Features;

/* 
 * TODO: Delete and use your own features!
 */

Features compute_features(const float *x, int N) {
  /*
   * Input: x[i] : i=0 .... N-1 
   * Ouput: computed features
   */
  /* 
   * DELETE and include a call to your own functions
   *
   * For the moment, compute random value between 0 and 1 
   */
  Features feat;
  //feat.zcr = feat.p = feat.am = (float) rand()/RAND_MAX;
  feat.p = compute_power(x,N);
  feat.zcr = compute_zcr(x,N,16000);
  feat.am = compute_am(x,N);
  return feat;

}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate,float alfa0, float alfa1) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
  vad_data->alfa0 = alfa0;
  vad_data->alfa1 = alfa1;
  vad_data->N_tramas = MAX_TRAMAS;
  /*
  vad_data->MAX_MAYBES_SIL = 5;
  vad_data->MAX_MAYBES_VOZ = 3;//PREFERIMOS ELIMINAR SILENCIO QUE VOZ: por lo que definimos una ventana maybe más pequeña
  vad_data->num_maybes_voz = 0;
  vad_data->num_maybes_sil = 0;
  */
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
  /* 
   * TODO: decide what to do with the last undecided frames
   */
  VAD_STATE state = vad_data->state;

  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  //f.p es la potencia!
  Features f = compute_features(x, vad_data->frame_length);
  vad_data->last_feature = f.p; /* save feature, in case you want to show */

  //el autómata: toma una decisión distinta depende de donde esté
  switch (vad_data->state) {
  
  case ST_INIT: //estado inicial
    vad_data->state = ST_SILENCE;
    vad_data->p0 = f.p + vad_data->alfa0;
    vad_data->p1 = f.p + vad_data->alfa1;
   /*
    vad_data->max_sil = vad_data->p0 + vad_data->alfa0-0.5; 
    vad_data->min_voz = vad_data->p0 + vad_data->alfa1+0;  
   */
    break;

  case ST_SILENCE:
    if(f.p > vad_data->p0){ //si nuestra potencia está por encima de la mínima para voz:
        vad_data->state = ST_MV; //pasamos a considerar MAYBE voice
        vad_data->N_tramas --;
     }
    /*
     if(f.p > vad_data->min_voz){ //si nuestra potencia está por encima de la mínima para voz:
        vad_data->state = ST_MV; //pasamos a considerar MAYBE voice
        
     }else{
      vad_data->num_maybes_voz=0;
      vad_data->state = ST_SILENCE;
    }
    */
    break;

  case ST_VOICE:

    if (f.p < vad_data->p1){
      vad_data->state = ST_MS;
      vad_data->N_tramas --;
    }
      /*
      if(f.p < vad_data->max_sil){ //si nuestra potencia está por debajo de la máxima para silencio:
        vad_data->state = ST_MS; //pasamos a considerar MAYBE silence
      }else{
      vad_data->num_maybes_sil=0;
      vad_data->state = ST_VOICE;
      }
      */
    break;

case ST_MV:
    /*
    vad_data->num_maybes_voz++;

    //miramos si dura lo suficiente como para pasar a segmento de voz

    if(vad_data->num_maybes_voz>=vad_data->MAX_MAYBES_VOZ){
      vad_data->num_maybes_voz=0;
       vad_data->state = ST_VOICE;
    }
      //si antes de llegar al maximo de maybes de voz obtengo una potencia dentro  
      //del rango de silencio --> segmento de voz demasiado corto --> considero silencio
     else if(f.p<vad_data->max_sil){
      vad_data->state = ST_SILENCE; 
    }
    */
    if(f.p > vad_data->p1){
      vad_data->N_tramas = MAX_TRAMAS;
      vad_data->state = ST_VOICE;
    }
    else if ((f.p < vad_data->p0) || (vad_data->N_tramas == 0)){
      vad_data->N_tramas = MAX_TRAMAS;
      vad_data->state = ST_SILENCE; 
    }
    else{
      vad_data->N_tramas --;
    }
    break;
  
  case ST_MS:
  /*
   vad_data->num_maybes_sil++;

   //miramos si dura lo suficiente como pasar a segmento de silencio

   if(vad_data->num_maybes_sil>=vad_data->MAX_MAYBES_SIL){
      vad_data->num_maybes_sil=0;
      vad_data->state = ST_SILENCE;
    }

    else if(f.p>vad_data->max_sil){
      //si antes de llegar al maximo de maybes de silencio obtengo una potencia fuera  
      //del rango de silencio --> segmento de silencio demasiado corto --> considero voz
      vad_data->num_maybes_sil=0;
      vad_data->state = ST_VOICE;
    }
    */
   if(f.p < vad_data->p0){
      vad_data->N_tramas = MAX_TRAMAS;
      vad_data->state = ST_SILENCE;
    }
    else if ((f.p > vad_data->p1) || (vad_data->N_tramas == 0)){
      vad_data->N_tramas = MAX_TRAMAS;
      vad_data->state = ST_VOICE; 
    }
    else{
      vad_data->N_tramas --;
    }
    break;

  case ST_UNDEF:
    break;
  }

  if (vad_data->state == ST_SILENCE || vad_data->state == ST_MV){
    return ST_SILENCE;
  }
  else if (vad_data->state == ST_VOICE || vad_data->state == ST_MS){
    return ST_VOICE;
  }
  else
    return ST_UNDEF;
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%d\t%f\n", vad_data->state, vad_data->last_feature);
}
