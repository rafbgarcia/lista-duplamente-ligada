#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
  int valor;
  struct Node *anterior;
  struct Node *proximo;

} Node;

/* objetivo de diminuir a complexidade do tamanho() para O(1) */
static int num_nodes = 0;

Node *inicio = NULL;
Node *fim = NULL;

void insereInicio(int valor);
void insereFim(int valor);
void removeInicio();
void removeFim();
void removeNumero(int valor);
int tamanho();
int buscar(int valor);


/**
 * Main
 */
int main(int argc, char **argv) {

  /**
   * Iniciar esta lista:
   * 2 <-> 4 <-> 6 <-> 10
   */
    insereInicio(4);
    insereInicio(2);
    insereFim(6);
    insereFim(10);


  /**
   * Teste do tamanho() da lista
   */
    assert(tamanho() == 4);


  /**
   * Testes da função buscar()
   */
    assert(buscar(2)  == 1);
    assert(buscar(4)  == 1);
    assert(buscar(10) == 1);
    assert(buscar(6)  == 1);

    assert(buscar(5)  == 0);
    assert(buscar(15) == 0);


  /**
   * Testes de remover
   */
     removeFim();
     removeInicio();
     assert(tamanho() == 2);

     /**
      * A lista deve estar assim:
      * 4 <-> 6
      */

     removeNumero(4);
     assert(tamanho() == 1);

     removeNumero(6);
     assert(tamanho() == 0);


  return EXIT_SUCCESS;
}


/**
 * Insere um nó no início da lista
 *
 * Complexidade O(1)
 */
void insereInicio(int valor) {
  Node *novo = (Node *) malloc(sizeof(Node));

  novo->valor    = valor;
  novo->anterior = NULL;

  if(inicio == NULL) {
    novo->proximo = NULL;
    inicio = novo;
    fim    = novo;
  }
  else {
    inicio->anterior = novo;
    novo->proximo    = inicio;
    inicio = novo;
  }

  num_nodes++;
}

/**
 * Insere um nó no fim da lista
 *
 * Complexidade O(1)
 */
void insereFim(int valor) {
  Node *novo = (Node *) malloc(sizeof(Node));

  novo->valor    = valor;
  novo->proximo = NULL;

  if(fim == NULL) {
    novo->proximo = NULL;
    inicio = novo;
    fim    = novo;
  }
  else {
    fim->proximo = novo;
    novo->anterior = fim;
    fim = novo;
  }

  num_nodes++;
}

/**
 * Remove um nó do início da lista
 *
 * Complexidade O(1)
 */
void removeInicio() {
  if(inicio != NULL) {
    inicio = inicio->proximo;
    free(inicio->anterior);
    inicio->anterior = NULL;

    num_nodes--;
  }
}

/**
 * Remove um nó do fim da lista
 *
 * Complexidade O(1)
 */
void removeFim() {
  if(fim != NULL) {
    fim = fim->anterior;
    free(fim->proximo);
    fim->proximo = NULL;

    num_nodes--;
  }
}

/**
 * Remove um nó que tem valor igual ao valor passado
 *
 * Complexidade O(n)
 */
void removeNumero(int valor) {
  Node *current = inicio;

  if(inicio != NULL) {
    while(current != NULL) {
      if(current->valor == valor) {

        if(current->anterior != NULL)
          current->anterior->proximo = current->proximo;

        if(current->proximo != NULL)
          current->proximo->anterior = current->anterior;

        free(current);

        num_nodes--;
        break;
      }

      current = current->proximo;
    }
  }
}

/**
 * Retorna o tamanho da lista
 *
 * Complexidade O(1)
 */
int tamanho() {
  return num_nodes;
}

/**
 * Retorna o 1 caso o valor exista na lista
 * 0 caso não exista
 *
 * Complexidade O(n)
 */
int buscar(int valor) {
  if(inicio == NULL) {
    return 0;
  }

  Node *current = inicio;
  while(current != NULL) {
    if(current->valor == valor) {
      return 1;
    }
    current = current->proximo;
  }
  return 0;
}
