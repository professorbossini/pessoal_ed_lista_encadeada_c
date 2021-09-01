#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct no{
  int dado;
  struct no * prox;
}no;


typedef struct {
  struct no * primeiro;
  int qtde;
}lista_ligada_simples;

lista_ligada_simples * obter_lista (){
  lista_ligada_simples * l = malloc (sizeof(lista_ligada_simples));
  l->primeiro = NULL;
  l->qtde = 0;
  return l;
}

//mais fácil
void inserir_no_comeco (lista_ligada_simples * l, int dado){
  no * novo = malloc (sizeof(no));  
  novo->dado = dado;
  novo->prox = l->primeiro;
  l->primeiro = novo;
  l->qtde++;
}

void exibir_lista (lista_ligada_simples * l){
  no * aux = l->primeiro;
  while (aux != NULL){
    printf ("%d ", aux->dado);
    aux = aux->prox;
  }
}

int obter (lista_ligada_simples * l, int indice){
  if (indice >= l->qtde)return -1;
  no * aux = l->primeiro;
  for (int i = 0; i < indice; i++, aux = aux->prox);
  return aux->dado;
}

int esta_vazia (lista_ligada_simples * l){
  return l->qtde <= 0;
}
//inserir no final, mais dificil
void inserir_no_final (lista_ligada_simples * l, int dado){
  if (esta_vazia (l))
    inserir_no_comeco (l, dado);
  else{
    no * novo = malloc (sizeof(no));
    novo->dado = dado;
    novo->prox = NULL;
    no * aux = l->primeiro;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;
    l->qtde++;
  }
}

int main(void) {
  srand(time(NULL));

  lista_ligada_simples * l = obter_lista ();
  for (int i = 0; i < 100; i++){
    int dado = rand() % 20 + 1;
    //inserir_no_comeco (l, dado);
    inserir_no_final(l, dado);
    exibir_lista (l);
    printf ("\n");
    int posicao_desejada = rand() % l->qtde;
    printf ("lista[%d]: %d", posicao_desejada, obter(l, posicao_desejada));
    printf ("\n");
  }

  return 0;
}