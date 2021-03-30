#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Tipo_Lista{
    int cod;
    struct Tipo_Lista *Prox;
}

struct Tipo_Lista *Primeiro;
struct Tipo_Lista *Ultimo;

void FLVazia(){
    struct Tipo_Lista *aux;
    aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
    Primeiro = aux;
    Ultimo = Primeiro;
}

void Insere(int x){
    struct Tipo_Lista *aux;
    aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
    aux->cod = x;
    Ultimo->Prox = aux;
    Ultimo = Ultimo->Prox;
    aux->Prox = NULL;
}

void Imprime(){
    struct Tipo_Lista *aux;
    aux = Primeiro->Prox;
    while(aux != NULL){
        printf("Item = %d", aux->cod);
        aux = aux->Prox;
    }
}

void Pesquisa(int x) {
    struct Tipo_Lista *aux;
    int flag = 0;
    aux = Primeiro->Prox;
    while(aux != NULL){
        if(aux->cod == x){
            printf("Achou item %d", x);
            flag = 1;
            aux = NULL;
        }
        else
        aux = aux->Prox;
    }
    if (flag == 0)
        printf("Item %d Nao se encontra nessa lista!!!", x);
}


void Remove(int x) {
    struct Tipo_Lista *aux;
    struct Tipo_Lista *sentinela;
    int flag = 0;
    aux = Primeiro->Prox;
    sentinela = Primeiro;
    while(aux != NULL){
        if(aux->cod == x){
            printf("Removeu item %d", x);
            sentinela->Prox = aux->Prox;
            aux = NULL;
            flag = 1;
        }
        else
        aux = aux->Prox;
        sentinela = sentinela->Prox;


    }
    if (flag == 0)
        printf("Item %d Nao se encontra nessa lista!!!", x);
}

main ()
{
  char op = '2';
  int i, codigo;
  FLVazia();
  while(op != '0'){
      printf("Insira um codigo: ");
      scanf("%d", &codigo);
      Insere(codigo);
      printf("Continuar com o cadastro? 1 = sim, 0 = nao: \n\n");
      op = getch();
  }
  Imprime();
  printf("\n\n Insira um item para pesquisar: ");
  scanf("&d", &codigo);
  Pesquisa(codigo);
  printf("\n\nItem a ser removido: ");
  scanf("&d", &codigo);
  Remove(codigo);
  Imprime();
  getch();
}
