#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
  int valor;
  struct Node *origem;
  struct Node *destino;
} Node;


Node *inicio = NULL;
Node *fim = NULL;

void insereInicio(int valor);
void insereFim(int valor);
void tamanho(int valor);
void buscar(int valor);


/**
 * Main
 */
int main(int argc, char **argv) {


  return EXIT_SUCCESS;
}

void insereInicio(int valor) {
  Node *novo = (Node *) malloc(sizeof(Node));

  novo->origem = NULL;
  novo->valor  = valor;

  if(inicio == NULL) {
    novo->destino = NULL;

    inicio = novo;
    fim = inicio;
  }
  else {
    novo->destino  = inicio;

    inicio->destino = NULL;
    inicio->origem  = novo;
    fim = inicio;
  }

}
