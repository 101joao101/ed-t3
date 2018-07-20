#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "Estoque.h"
#include "Lista.h"

typedef double (*Mat)(Posic);

Estoque ltov(Lista list, Estoque e, int size);
void heapsort(Lista list, Mat matx);

#endif