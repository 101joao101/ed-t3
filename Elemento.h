#ifndef Elemento_H
#define Elemento_H

    typedef void *Elemento;

Elemento createElemento(double x, double y);
double getElementoX(Elemento c);
double getElementoY(Elemento c);

#endif