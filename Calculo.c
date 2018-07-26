#include <stdio.h>
#include "Calculo.h"
#include "Ordenacao.h"
#include <math.h>
#include "Elemento.h"
#include "Comandos.h"

double min(double a, double b){
    if(a < b)
        return a;
    else
        return b;
}

void ver(Elemento *r1, Elemento *r2, Elemento e1, Elemento e2){
    double d1, d2;
    d1 = sqrt(pow((getElementoX(*r1) - getElementoX(*r2)), 2) + pow((getElementoY(*r1) - getElementoY(*r2)), 2));
    d2 = sqrt(pow((getElementoX(e1) - getElementoX(e2)), 2) + pow((getElementoY(e1) - getElementoY(e2)), 2));
    if (d1 < d2){
        *r1 = e1;
        *r2 = e2;
    }
}

double lessDistanceFront(Vector vet, int last, double minDist, Elemento *r1, Elemento *r2){
    int i, j;
    char *aux;
    Elemento e1, e2;
    double auxd;
    heapSort(vet, cmp, 'y');
    for(i = 1; i < last; i++){
        j = i+1;
        for (; j<=last; j++){
            if ((getElementoY(getObjVector(vet, i)) - getElementoY(getObjVector(vet, j))) < minDist){
                auxd = sqrt(pow((getElementoX(getObjVector(vet, i)) - getElementoX(getObjVector(vet, j))), 2) + pow((getElementoY(getObjVector(vet, i)) - getElementoY(getObjVector(vet, j))), 2));
                if (auxd < minDist){
                    minDist = auxd;
                    ver(r1, r2, getObjVector(vet, i), getObjVector(vet, j));
                }
            }
        }
    }
    return minDist;
}

double lessDistThree(Vector vet, int first, int last, Elemento *r1, Elemento *r2){
    double d1, d2, d3, daux;
    char *aux;
    int size, i, j;
    Elemento e1, e2, e3;
    e1 = getObjVector(vet, first);
    i = first + 1;
    e2 = getObjVector(vet, i);
    d1 = sqrt(pow((getElementoX(e1) - getElementoX(e2)), 2) + pow((getElementoY(e1) - getElementoY(e2)), 2));
    if (last - first == 2){
        if (*r1 == NULL && *r2 == NULL){
            *r1 = getObjVector(vet, first);
            *r2 = getObjVector(vet, i);
        }
        ver(r1, r2, e1, e2);
        return d1;
    }else{
        j = first + 2;
        e3 = getObjVector(vet, j);
        d2 = sqrt(pow((getElementoX(e1) - getElementoX(e3)), 2) + pow((getElementoY(e1) - getElementoY(e3)), 2));
        d3 = sqrt(pow((getElementoX(e3) - getElementoX(e2)), 2) + pow((getElementoY(e3) - getElementoY(e2)), 2));
        if (d1 < d2 && d1 < d3){
            if (*r1 == NULL && *r2 == NULL){
                *r1 = getObjVector(vet, first);
                *r2 = getObjVector(vet, i);                
            } else
                ver(r1, r2, e1, e2);
            return d1;
        } else if (d2 < d1 && d2 < d3){
            if (*r1 == NULL && *r2 == NULL){
                *r1 = getObjVector(vet, first);
                *r2 = getObjVector(vet, j);
            } else
                ver(r1, r2, e1, e3);
            return d2;
        } else{
            if (*r1 == NULL && *r2 == NULL){
                *r1 = getObjVector(vet, i);
                *r2 = getObjVector(vet, j);
            } else
                ver(r1, r2, e2, e3);
            return d3;
        }
    }
}

double lessDistance(Vector vet, int first, int last, Elemento *r1, Elemento *r2){
    Vector aux;
    double dl, dr, d, midx, mf, a, resp;
    int m, i, j;
    if (last <= 3){
        resp = lessDistThree(vet, first, last, r1, r2); 
        return resp;
    }
    m = last/2;
    dl = lessDistance(vet, first, m, r1, r2);
    
    dr = lessDistance(vet, first + m, last - m, r1, r2);
    d = min(dl, dr);
    aux = createVector(getSizeVector(vet));
    midx = getElementoX(getObjVector(vet, m));

    for (i = 1, j = 0; i <= last; i++){
        a = getElementoX(getObjVector(vet, i));
        if (a < 0)
            a *= -1;
        if (a < d){
            j++;
            addVector(aux, (Item)getObjVector(vet, i), j);
        }
    }
    setSizeVector(aux, j);
    mf = lessDistanceFront(aux, j, d, r1, r2);
    return min(mf, d);
}

