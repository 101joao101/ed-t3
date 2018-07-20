#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"
#include "Elemento.h"

Vector ltov(Lista list, Mat matx, Mat maty){
    int i;
    Posic p;
    Item i;
    Elemento e;
    Vector vet;
    vet = createVector(length(list));
    p = getFirst(list);
    for (i = 1; i <= length(list); i++){
        e = createElemento(matx(getObjt(p)), maty(getObjt(p)));
        addVector(vet, e, i);
        p = getNext(p);
    }
    return vet;
}

void principal(Lista list, Mat matx){

}

void heapsort(Vector vet, Compare cmp){
    
}