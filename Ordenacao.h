#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "Vector.h"
#include "Lista.h"

typedef double (*Mat)(Item);
typedef int (*Compare)(Vector vet, int i, int j);

Vector ltov(Lista list, Mat matx, Mat maty);
void heapsort(Vector vet, Compare cmp);

#endif