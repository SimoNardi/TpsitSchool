#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DIM 50

typedef struct a{
  char Name[DIM];
  int Number;
  struct Contact* Next;
}Contact;

void aCapo();

int main() {
  Contact Giovanni;
  strcpy(Giovanni.Name, "Giovanni");
  Giovanni.Number = 11;
  Giovanni.Next = NULL;

  Contact Mamma;
  strcpy(Mamma.Name, "Mamma");
  Mamma.Number = 12;
  Mamma.Next = &Giovanni;

  Contact Io;
  strcpy(Io.Name, "Io");
  Io.Number = 13;
  Io.Next = &Giovanni;

  Mamma.Next = &Io;

  int i = 0;
  Contact* Support = &Mamma;

  do{
    printf("Name: %s \t Number: %d\n", Support->Name, Support->Number);
    Support = Support->Next;
  }while (Support->Next != NULL);


  getch();
  fflush(stdin);
  return 1;
}

void aCapo(){
  printf("\n");
}
