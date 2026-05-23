#ifndef FUNCIONES_PROCEDIMIENTOS_H
#define FUNCIONES_PROCEDIMIENTOS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


    #define W_ID      5
    #define W_NOMBRE  20
    #define W_PESO    8
    #define W_ALTURA  8
    #define W_CIUDAD  15
    #define W_PODERES 25
    #define W_DEBIL   25
    #define W_SAGA    15
    #define W_ESTADO  10


struct fichaTecnica{
        char ciudadOrigen[50];
        char poderes[10][100];
        char debilidades[10][100];
        char archienemigo[80];
};

struct super{
    int id;
    char nombre[80];
    float peso;
    float altura;
    struct fichaTecnica fichaTecnica1;
    char saga[50];
    char estado[4];
        
};



void registrarSuper(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void truncar(char *destino, const char *cadena, int maxAncho);
void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void etiquetaInicial();
int menuPrincipal(int *ptrOpcionmenuPrincipal);
int busquedaSuper(struct super supers[], int *ptrnumSupers);
void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades, int *ptrIndiceEncontrado);
void actualizarEstado (struct super supers[], int *ptrnumSupers);
void eliminarRegistro(struct super supers[], int *ptrnumSupers);

#endif