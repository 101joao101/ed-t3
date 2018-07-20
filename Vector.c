#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

typedef struct {
	void *obj;
}vector;

typedef struct{
	int size;
	int qntd;
	vector *vet;
}head;


Vector creatVector(int n){
	int i;
	head *newHead;
	vector *newVet;
	newHead = (head*)malloc(sizeof(head));
	newVet = (vector*)calloc(n, sizeof(vector));

	(*newHead).size = n;
	(*newHead).qntd = 0;
	(*newHead).vet = newVet;
	for (i=0; i<n; i++) {
		newVet[i].obj = NULL;
	}
	return (Vector)newHead;
}

int getQntd(Vector vet){
	head *newVector;
	newVector = (head*)vet;
	return newVector->qntd;
}

int getSizeVector(Vector vet){
	head *newVector;
	newVector = (head*)vet;
	return newVector->size;
}

Posic getObjVector(Vector vet, int n){
	head *cabeca;
	vector *vetor;
	cabeca = (head*)vet;
	vet = cabeca->vet;
	if (vetor[n-1].obj == NULL)
		return NULL;
	else
		return vetor[n-1].obj;
}

Posic addVector(Vector vet,	Item obj, int n){
	head *cabeca;
	vector *vetor;
	cabeca = (head*)vet;
	vet = cabeca->vet;
	if (vetor[n-1].obj == NULL){
		vetor[n-1].obj = obj;
		return vetor[n-1].obj;
	} else {
		return NULL;
	}
}

void freeVector(Vector vet){
	head *cabeca;
	vector *vetor;
	int i;
	cabeca = (head*)vet;
	vetor = cabeca->vet;
	for (i = 0; i < cabeca->size; i++){
		if (vetor->obj != NULL)
			free(vetor[i].obj);
	}
	free(cabeca);
}