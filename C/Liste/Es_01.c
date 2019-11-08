/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
struct  El
{
    int  valore;
    struct  El* next;
};

void stampaNum(struct  El* l);

int  main()
{
    int n;
    struct  El* lista;  //puntatore primo elemento della lista
    struct  El* l;
    lista=NULL; /*  Inizializzazione puntatore a NULL  */

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  Verifico se il puntatore lista assume valore NULL  */
            {
                /*  Alloco in memoria pre una struttura  */
                lista = (struct  El*)  malloc(sizeof(struct  El));
                l = lista;
            }
            else /*  se il puntatore è diverso da NULL  */
            {
                /*  assegno al puntatore l dell'elemento corrente un puntatore che punta all'elemento successivo  */
                l->next = (struct  El*)  malloc(sizeof(struct  El));
                l = l->next;
            }
            l->valore = n; /*  Assegno n al campo valore della struttura  */
            l->next = NULL; /*  Assegno al campo next dell'elemento corrente il valore NULL  */
        }
    } while (n>=0);

    l=lista;  /*  assegnamento alla varibile di appoggio l il puntatore al primo elemento della lista  */
    printf("numeri  inseriti:\n");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; /*  il puntatore corrente è assegnato al puntatore all'elemento successivo  */
    }
    printf("\n");
    l=lista;
    stampaNum(l);
    return  0;
    }

    void stampaNum(struct  El* l){
      if(l!=NULL){
        printf("%d\n",l->valore);
        l=l->next;
        stampaNum(l);
        return 0;
      }else{
        return 0;
      }
    }
