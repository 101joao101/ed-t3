#include <stdio.h>
#include "Torre.h"
#include <stdlib.h>
#include "CalculoCirculoRetangulo.h"

typedef struct{
	double x;
	double y;
	char *id;
	char *corPreenchimento;
	char *corContorno;
}torre;

Torre createTorre(double x, double y, char *id){
	torre *newTorre;
	newTorre = (torre*)malloc(sizeof(torre));
	newTorre->x = x;
	newTorre->y = y;
	newTorre->id = id;
	newTorre->corContorno = NULL;
	newTorre->corPreenchimento = NULL;
	return (Torre)newTorre;
}

double getTorreX(Torre t){
	torre *newTorre = (torre*)t;
	return newTorre->x;
}

double getTorreY(Torre t){
	torre *newTorre = (torre*)t;
	return newTorre->y;
}

char *getTorreId(Torre t){
	torre *newTorre = (torre*)t;
	return newTorre->id;
}

char *getTorreCorPreenchimento(Torre t){
	torre *newTorre = (torre*)t;
	return newTorre->corPreenchimento;
}

char *getTorreCorContorno(Torre t){
	torre *newTorre = (torre*)t;
	return newTorre->corContorno;
}

void setTorreCorPreenchimento(Torre t, char *cor){
	torre *newTorre = (torre*)t;
	if (newTorre->corPreenchimento != NULL)
		free(newTorre->corPreenchimento);
	newTorre->corPreenchimento = cor;
}

void setTorreCorContorno(Torre t, char *cor){
	torre *newTorre = (torre*)t;
	if (newTorre->corContorno != NULL)
		free(newTorre->corContorno);
	newTorre->corContorno = cor;
}

int torreInternaRetangulo(FILE **txt, Torre t, Retangulo r){
	if (pontoInternoRetangulo(r, getTorreX(t), getTorreY(t)) == 1){
		if (*txt != NULL)
			fprintf(*txt, "%s %f %f %s %s\n", getTorreId(t), getTorreX(t), getTorreY(t), getTorreCorPreenchimento(t), getTorreCorContorno(t));
		return 1;
	}
	return 0;
}

int torreInternaCirculo(FILE **txt, Torre t, Circulo c){
	if (pontoInternoCirculo(c, getTorreX(t), getTorreY(t)) == 1){
		if (*txt != NULL)
			fprintf(*txt, "%s %f %f %s %s\n", getTorreId(t), getTorreX(t), getTorreY(t), getTorreCorPreenchimento(t), getTorreCorContorno(t));
		return 1;
	}
	return 0;
}

void freeTorre(Torre t){
	torre *newTorre = (torre*)t;
	if(newTorre->corContorno != NULL)
		free(newTorre->corContorno);
	if (newTorre->corPreenchimento != NULL)
		free(newTorre->corPreenchimento);
	if (newTorre->id != NULL)
		free(newTorre->id);
}