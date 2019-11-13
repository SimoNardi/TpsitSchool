#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void aCapo();

void main() {
  int dim, max;
  printf("inserire dimensione array: ");
  scanf("%d", &dim);
  aCapo;
  int *vett= malloc(dim*sizeof(int));   //alloco lo spazio di memoria per il puntatore
  for (int k = 0; k < dim; k++) {
    printf("inserire il num %d: ", k+1);
    scanf("%d", &vett[k]);
    aCapo;
  }
  max = vett[0];
  for (int k = 1; k < dim; k++) {
    if(max<vett[k])
    max = vett[k];
  }
  printf("il maggiore e' %d\n", max);
}

void aCapo(){
  printf("\n");
}
