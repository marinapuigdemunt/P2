#include <math.h>
#include "pav_analysis.h"


float compute_power(const float *x, unsigned int N) {
  float pot = 1e-12;


  for (unsigned int n = 0; n < N; n++) {
    pot += x[n] * x[n];
  }
 
  return 10 * log10(pot / N); // devolvemos la potencia en dB
}


float compute_am(const float *x, unsigned int N) {
  float ampl = 0;


  for (unsigned int n = 0; n < N; n++) {
    ampl += fabsf(x[n]); //valor absoluto de x (float)
  }


  return ampl / N; // devolvemos la amplitud media
}


float compute_zcr(const float *x, unsigned int N, float fm) {
  float zcr = 0;
 
  for (unsigned int n = 1; n < N; n++) {
    if (x[n] * x[n - 1] < 0) { //si la multiplicación da resultado negativo es poque ambos valores tenían signo opuest
      zcr += 1;
    }
  }


  return (fm / (2 * (N - 1))) * zcr; // devolvemos la tasa de cruces por cero
}