#ifndef Vector_H
#define Vector_H
#include "Lista.h"

	typedef void *Vector;

Vector createVector(int n);
int getSizeVector(Vector vet);
int getQntd(Vector vet);
Item getObjVector(Vector vet, int n);
Posic addVector(Vector vet, Item i, int n);
void swap(Vector vet, int i, int j);
void freeVector(Vector vet);

#endif