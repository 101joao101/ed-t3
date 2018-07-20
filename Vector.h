#ifndef Vector_H
#define Vector_H
#include "Lista.h"

	typedef void *Vector;

Vector creatVector(int n);
int getSizeVector(Vector vet);
int getQntd(Vector vet);
Posic getObj(Vector vet, int n);
Posic addVector(Vector vet, Item i, int n);
void freeVector(Vector vet);

#endif