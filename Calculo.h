#ifndef CALCULO_H
#define CALCULO_H
#include "Vector.h"
#include "Elemento.h"

double lessDistance(Vector vet, int first, int last, Elemento *r1, Elemento *r2);
/* Esta função Recebe um vetor de Elementos e retorna a menor distância entre os elemetos, 
nela usa-se o heap sort, um metodo de ordenação de O(nlog(n)), 
ele foi escolhido pois praticamente em todos os casos ele tem o mesmo tempo, isto é, 
seja um vetor semiordenado ou um vetor todo desorganizado o tempo de execução é bem parecido*/
double lessDistThree(Vector vet, int first, int last, Elemento *r1, Elemento *r2);
double lessDistanceFront(Vector vet, int last, double minDist, Elemento *r1, Elemento *r2);

#endif
