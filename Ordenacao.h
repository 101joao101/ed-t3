#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "Vector.h"
#include "Lista.h"

typedef char *(*Str)(Item);
typedef double (*Mat)(Item);
typedef int (*Compare)(Vector vet, int i, int j, char p);

Vector ltov(Lista list, Mat matx, Mat maty, Str id);
/* Esta função passa de lista para vetor, mas dentro do vetor só vai o objeto com as coordenadas para a ordenação*/
void heapSort(Vector vet, Compare cmp, char coodn);
/*Esta função recebe um vetor de Elementos e os ordenada de acordo com o parametro Compare*/

#endif