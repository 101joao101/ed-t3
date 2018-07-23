#include <stdio.h>
#include <stdlib.h>
#include "Elemento.h"

typedef struct reg{
    double x;
    double y;
}elemento;

Elemento createElemento(double x, double y){
    elemento *new;
    new = (elemento*)malloc(sizeof(elemento));
    new->x = x;
    new->y = y;
    return new;
}

double getElementoX(Elemento c){
    elemento *new = (elemento*)c;
    return new->x;
}

double getElementoY(Elemento c){
    elemento *new = (elemento*)c;
    return new->y;
}

int cmp(Vector vet, int i, int j, char p){
    elemento *e1, *e2;
    e1 = (elemento*)getObjVector(vet, i);
    e2 = (elemento*)getObjVector(vet, j);
    if (p == 'x'){
        if (e1->x > e2->x)
            return -1;
        else if (e1->x == e2->x)
            return 0;
        else if (e1->x < e2->x)
            return 1;
    } else {
        if (e1->y > e2->y)
            return -1;
        else if (e1->y == e2->y)
            return 0;
        else if (e1->y < e2->y)
            return 1;
    }
}