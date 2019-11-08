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
  int *vett= malloc(dim*sizeof(int));
  for (int k = 0; k < dim; k++) {
    printf("inserire il num %d: ", k+1);
    scanf("%d", (vett+k));
    aCapo;
  }
  for (int k = 0; k < dim; k++) {
    printf("%d: ", k+1);
    printf("%d: ", vett+k);
    printf("%d\n", *(vett+k));

  }
}

void aCapo(){
  printf("\n");
}
