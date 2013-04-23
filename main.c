#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"

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
