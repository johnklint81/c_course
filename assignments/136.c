#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float x;

float *func(float xmin, float xmax, float stepsize, int nsteps) {
  float* f = (float*) malloc(nsteps * sizeof(float));
  for (int i = 0; i < nsteps; ++i) {
    x = xmin + (float)i * stepsize;
    f[i] = 4 * pow(x, 3) + 3 * pow(sin(x), 2) - 5 * x - 7;
  }
  return f;
}

int main(void) {
  int nsteps15 = 31;
  int nsteps1 = 21;
  float *f15 = func(-15, 15, 1, nsteps15);
  float *f1 = func(-1, 1, 0.1, nsteps1);
  printf("\n");
  for (int i = 0; i < nsteps15; ++i) {
    printf("%.2f ", f15[i]);
    if ((i + 1) % 4 == 0 && i != 0) {
      printf("\n");
    }
  }
  printf("\n\n");
  for (int i = 0; i < nsteps1; ++i) {
    printf("%.2f ", f1[i]);
    if ((i + 1) % 4 == 0 && i != 0) {
      printf("\n");
    }
  }
  printf("\n");
}
