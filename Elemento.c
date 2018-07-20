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