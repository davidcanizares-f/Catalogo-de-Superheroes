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
void etiquetaInicial();
int menuPrincipal(int *ptrOpcionmenuPrincipal);

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

    int opcionMenuPrincipal=0;
    int *ptrOpcionmenuPrincipal;
    ptrOpcionmenuPrincipal=&opcionMenuPrincipal;
    

    

    etiquetaInicial();
    printf("\nIngrese el numero de Superheroes a registrar: ");
    scanf("%d", ptrnumSupers);
    getchar();
    
    struct super supers[*ptrnumSupers];
    registrarSuper(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
    
    do{
        opcionMenuPrincipal=menuPrincipal(ptrOpcionmenuPrincipal);
        switch(opcionMenuPrincipal){
            case 1:
                mostrarDatos(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
                break;
            case 5:
                printf("\n======================\n");
                printf("  SALISTE DEL PROGRAMA\n");
                printf("=========================\n");
                break;
        }

    }while(opcionMenuPrincipal!=5);
    

    
    

    
    

    return 0;
}