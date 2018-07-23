#ifndef Elemento_H
#define Elemento_H
#include "Vector.h"

    typedef void *Elemento;

Elemento createElemento(double x, double y);
double getElementoX(Elemento c);
double getElementoY(Elemento c);
int cmp(Vector vet, int i, int j, char p);

#endif