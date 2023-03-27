#include <stdio.h>
#include "fic_wave.h"


FILE *abre_wave(const char *ficWave, float *fm, int *numchan, int *pcm, int *bits16) {
  FILE *fpWave; //puntero al fichero
  unsigned int fm_wave;
  unsigned int num_ch;
  unsigned int codifPCMlin;
  unsigned int codif16bits;


  if ((fpWave = fopen(ficWave, "r")) == NULL) {
    return NULL; //si el fichero no tiene nada, retornamos NULL
  }
   
  if (fseek(fpWave, 44, SEEK_SET) < 0) {
    return NULL; // en la posición 44 empiezan los datos
  }
   
  fseek(fpWave, 24, SEEK_SET); //apuntamos a la posición donde se encuentra la fm


  //fread(ubicación de almacenamiento de datos, tamaño en bytes, número de elementos que se van a leer, puntero a la estructura FILE)
  fread(&fm_wave, 4, 1, fpWave);
 
  *fm = fm_wave; //frecuencia de muestreo = leída en la función anterior


  fseek(fpWave, 22, SEEK_SET); //apuntamos a la posición donde se encuentra el número de canales


  fread(&num_ch, 2, 1, fpWave);


  *numchan = num_ch;


  fseek(fpWave, 20, SEEK_SET); //apuntamos a la posición donde se encuentra el formato (queremos comprobar que es ‘1’-> PCM)


  fread(&codifPCMlin, 2, 1, fpWave);


  *pcm = codifPCMlin;


  fseek(fpWave, 16, SEEK_SET); //apuntamos a la posición donde se encuentra el tamaño de los datos del formato (queremos comprobar que es 16)


  fread(&codif16bits, 4, 1, fpWave);


  *bits16 = codif16bits;


  fseek(fpWave, 44, SEEK_SET); //volvemos a apuntar a los datos
 
  return fpWave; //si no hay errores, se devuelve el fichero
}




size_t lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
  return fread(x, size, nmemb, fpWave);
}




void cierra_wave(FILE *fpWave) {
  fclose(fpWave);
}
