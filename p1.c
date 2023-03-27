#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "pav_analysis.h"
#include "fic_wave.h"




int main(int argc, char *argv[]) {
   float durTrm = 0.010; //duración trama
   float fm;
   int numchan;
   int pcm;
   int bits16;
   int   N; //núm de muestras
   int   trm; //trama
   float *x;
   short *buffer;
   FILE  *fpWave; //fichero de audio de entrada
   FILE  *fpOut = stdout; //fichero de texto (donde se escribe el resultado del análisis)
 


   if (argc != 2 && argc != 3) {
       fprintf(stderr, "Empleo: %s inputfile [outputfile]\n", argv[0]);
       return -1;
   }




   if (argc == 3){
       fpOut = fopen(argv[2], "w");
   }




   if ((fpWave = abre_wave(argv[1], &fm, &numchan, &pcm, &bits16)) == NULL) {
       fprintf(stderr, "Error al abrir el fichero WAVE de entrada %s (%s)\n", argv[1], strerror(errno));
       return -1;
   }


    //Para poder ver el funcionamiento de la ampliación 1.1 se deben descomentar las 5 líneas siguientes


   /*
  if (numchan != 1) {
      //fprintf(stderr,"numchans: %d ", numchan);
      fprintf(stderr, "Error al abrir el fichero WAVE de entrada %s, la señal ha de ser de un solo canal (mono) (%s)\n", argv[1], strerror(errno));
      return -1;
  }
  */


   if (pcm != 1) {
      fprintf(stderr, "Error al abrir el fichero WAVE de entrada %s, la señal ha de de formato PCM (%s)\n", argv[1], strerror(errno));
      return -1;
  }




  if (bits16!= 16) {
      fprintf(stderr, "Error al abrir el fichero WAVE de entrada %s, la señal ha de tener un formato de 16 bits (%s)\n", argv[1], strerror(errno));
      return -1;
  }




   N = durTrm * fm; //numero de muestras es la duración * fm
   if ((buffer = malloc(N * sizeof(*buffer))) == 0 ||
       (x = malloc(N * sizeof(*x))) == 0) {
       fprintf(stderr, "Error al ubicar los vectores (%s)\n", strerror(errno));
       return -1;
   }




   trm = 0;




   float aux[numchan][N];




   while (lee_wave(buffer, sizeof(*buffer), N*numchan, fpWave) == N*numchan) {
       for (int n = 0; n < N*numchan; n++) {
           x[n] = buffer[n] / (float) (1 << 15); //dividimos por 32000 en amplitud, en potencia serian mil millones: 10^9
       }




       for (int i = 0; i < numchan; i++){
           for(int j = 0; j < N; j++){  
               aux[i][j]=x[j*numchan+i];
           }
        }


       fprintf(fpOut,"%d\t",trm);


       for(int i=0;i<numchan;i++){
            fprintf(fpOut, "%f\t%f\t%f\t-----\t", compute_power(aux[i], N),
                                               compute_am(aux[i], N),
                                               compute_zcr(aux[i], N, fm));
       }


       fprintf(fpOut,"\n");
       trm += 1;          
    }


   cierra_wave(fpWave);
   free(buffer);
   free(x);


   return 0;
}
