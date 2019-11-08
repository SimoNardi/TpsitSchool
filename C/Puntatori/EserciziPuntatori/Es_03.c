#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void aCapo();

void main() {
  int dim, max= 0;
  printf("inserire dimensione Stringa: ");
  scanf("%d", &dim);
  aCapo;
  char *vett= malloc((dim+1)*sizeof(char));
  for (int k = 0; k < dim; k++) {
    printf("inserire il la Stringa: ");
    scanf("%d", (vett+k));
    aCapo;
  }
  for (int k = 1; k < dim; k++) {
    if (!(*vett > *(vett+k))) {
      *vett = *(vett+k);
    }
  }
  printf("max: ");
  printf("%d: ", vett);
  printf("%d\n", *vett);
}

void aCapo(){
  printf("\n");
}
