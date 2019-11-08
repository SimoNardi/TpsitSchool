/*
Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NRIGHE 17000
#define NCOLONNE 11
#define LUNG 500
#define SEP ","

typedef struct _tabella {
  int rank;
  char *Name;
  char *Platform;
  int Year;
  char *Genre;
  char *Publisher;
  float NA_Sales;
  float EU_Sales;
  float JP_Sales;
  float Other_Sales;
  float Global_Sales;
} tabella;

int CaricaDato (tabella Gioco[], int n, char nomeFile[]);
void RicercaGioco (tabella Gioco[], int n);

void main() {

  int nGiochi = 0;

  tabella *gioco = malloc(NRIGHE * sizeof(tabella));
  nGiochi = CaricaDato(gioco, NRIGHE, "vgsales.csv");

  if (nGiochi != -1) RicercaGioco(gioco, nGiochi);
  else printf("Errore nel caricamento dei dati");

  free(gioco);

  return;
}

int CaricaDato(tabella Gioco[], int n, char nomeFile[]){

  int num=0;
  int k=0;
  char Stringa[LUNG];
  FILE *Giochi = fopen(nomeFile, "r");

  if(Giochi == NULL){

    num = -1;

  } else {

    printf("DEBUG :: Loading data...\n");

    while(num < n && fgets(Stringa, LUNG, Giochi) != NULL){

      char *pch;
      pch = strtok (Stringa, SEP);

      Gioco[num].rank = atoi(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Name = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(Gioco[num].Name, pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Platform = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(Gioco[num].Platform, pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Year = atoi(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Genre = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(Gioco[num].Genre, pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Publisher = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(Gioco[num].Publisher, pch);

      pch = strtok (NULL, SEP);
      Gioco[num].NA_Sales = atof(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].EU_Sales = atof(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].JP_Sales = atof(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Other_Sales = atof(pch);

      pch = strtok (NULL, SEP);
      Gioco[num].Global_Sales = atof(pch);

      num += 1;

    }

    printf("DEBUG :: Data loaded\n");
    fclose(Giochi);

  }

  return num;
}

void RicercaGioco(tabella Gioco[], int n){
  int num;
  bool ver=false;
  char ricerca[LUNG];
  char risp[LUNG];

  do{
    printf("inserire il nome del gioco da cercare: ");
    gets(ricerca);
    for(num=0, ver=false; num<n && !ver; num++){
      if(strcmp(ricerca, Gioco[num].Name) == 0){
        printf("%s %s %d %s %s %.2f %.2f %.2f %.2f %.2f\n", Gioco[num].Name, Gioco[num].Platform,
        Gioco[num].Year, Gioco[num].Genre, Gioco[num].Publisher, Gioco[num].NA_Sales,
        Gioco[num].EU_Sales, Gioco[num].JP_Sales, Gioco[num].Other_Sales, Gioco[num].Global_Sales);
        ver=true;
      }
    }
    if(!ver){
      printf("il prodotto non c'e'.\n");
    }
    printf("\nvuoi cercare altri prodotti?[rispondi con si o no]: ");
    fflush(stdin);
    gets(risp);
  }while(strcmp(risp, "si") == 0);
}
