#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"
#include "Elemento.h"

Estoque ltov(Lista list, Estoque e, int size){
    int tam, i;
    double *elemento;
    Lista aux;
    Posic p;
    aux = createList();
    p = getFirst(list);
    for(tam = length(list); tam > 0; tam--){
        elemento = (double*)malloc(sizeof(double));
        elemento = matx(p);
        insert(aux, elemento);
        p = getNext(p);
    }
    return aux;
}

void principal(Lista list, Mat matx){

}

void heapsort(Lista list, Mat matx){

}