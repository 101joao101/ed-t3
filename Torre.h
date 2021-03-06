#ifndef TORRE_H
#define TORRE_H
#include "Retangulo.h"
#include "Circulo.h"

	typedef void *Torre;

Torre createTorre(double x, double y, char *id);
double getTorreX(Torre t);
double getTorreY(Torre t);
char *getTorreId(Torre t);
char *getTorreCorPreenchimento(Torre t);
char *getTorreCorContorno(Torre t);
void setTorreCorPreenchimento(Torre t, char *cor);
void setTorreCorContorno(Torre t, char *cor);
int torreInternaRetangulo(FILE **txt, Torre t, Retangulo r);
int torreInternaCirculo(FILE **txt, Torre t, Circulo c);
void freeTorre(Torre t);

#endif