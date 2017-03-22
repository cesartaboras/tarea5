#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
using namespace std;

int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    return 0;
    int suma_total = raiz->num;
    suma_total += suma(raiz->hijo_der) + suma(raiz->hijo_izq);
    return suma_total;
}

int cantidadNodos(NodoArbolBinario* raiz)
{
    int contador =0;

    if(raiz==NULL)
    return 0;

    contador++;
    contador += cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq);
    return contador;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz)/cantidadNodos(raiz);
}
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
     int cont =1;
    if(raiz==NULL)
    return cont;

    if(raiz->num == num)
        return cont;


    if(num>raiz->num)
        cont += cuantosPasos(raiz->hijo_der,num);

    if(num<raiz->num)
        cont+= cuantosPasos(raiz->hijo_izq,num);

    return cont;
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{

   if (raiz==NULL)
        {
                return 0;
        }
        if ((raiz->hijo_der ==NULL)&&(raiz->hijo_izq ==NULL))
        {
                return 1;
        }
        else
        {
                return sumaHojas(raiz->hijo_izq) + sumaHojas(raiz->hijo_der);
        }
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
