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



void registrarSuper(struct super supers[], int *ptrSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void truncar(char *destino, const char *cadena, int maxAncho);
void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void etiquetaInicial();
int menuPrincipal(int *ptrOpcionmenuPrincipal);
int busquedaSuper(struct super supers[], int *ptrnumSupers);
void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades, int *ptrIndiceEncontrado);
void actualizarEstado (struct super supers[], int *ptrnumSupers);
void eliminarRegistro(struct super supers[], int *ptrnumSupers);

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

    int indiceEncontrado=0;
    int *ptrIndiceEncontrado;
    ptrIndiceEncontrado=&indiceEncontrado;
    

    

    etiquetaInicial();
    printf("\nIngrese el numero de Superheroes a registrar: ");
    while((scanf("%d", ptrnumSupers) !=1) || (*ptrnumSupers)<=0 || (*ptrnumSupers) > 10){
        printf("[ERROR]: DATO INVALIDO. INGRESE NUEVAMENTE.\n");
        while(getchar()!='\n');
        printf("\nIngrese el numero de Superheroes a registrar: ");

    }
    getchar();
    
    struct super supers[*ptrnumSupers];
    registrarSuper(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
    
    do{
        opcionMenuPrincipal=menuPrincipal(ptrOpcionmenuPrincipal);
        switch(opcionMenuPrincipal){
            case 1:
                mostrarDatos(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
                break;
            case 2:
                (*ptrIndiceEncontrado)= busquedaSuper(supers, ptrnumSupers);
                mostrarDatosIndividuales(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades, ptrIndiceEncontrado);
                break;
            case 3:
                actualizarEstado (supers, ptrnumSupers);
                break;
            case 4:
                eliminarRegistro(supers, ptrnumSupers);
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