/*
=============== UNIVERSIDAD DE LAS AMÉRICAS ===============
        FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
                INGENIERÍA DE SOFTWARE
                    PROGRAMACIÓN I
Autores:
    -David Cañizares
    -Sebastián Orbe
    -Jean Pierre Rosas
    -Derek Yépez

================= CATÁLOGO DE SUPERHÉROES =================

*/

//Inclusión de librerías.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones_procedimientos.h"
#include "funciones_procedimientos.c"

//si esta bien

void registrarSuper(struct super supers[], int *ptrSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);

int main(){
    int numeroPoderes=0;
    int *ptrNumeroPoderes;
    ptrNumeroPoderes=&numeroPoderes;

    int numeroDebilidades=0;
    int *ptrNumeroDebilidades;
    ptrNumeroDebilidades=&numeroDebilidades;

    
    int numeroSupers=0;
    int *ptrnumSupers;
    ptrnumSupers=&numeroSupers;    
    

    


    printf("Ingrese el numero de Superheroes: ");
    scanf("%d", ptrnumSupers);
    getchar();
    struct super supers[*ptrnumSupers];

    registrarSuper(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
    mostrarDatos(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);

    
    

    return 0;
}