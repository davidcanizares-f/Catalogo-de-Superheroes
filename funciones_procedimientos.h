#ifndef FUNCIONES_PROCEDIMIENTOS_H
#define FUNCIONES_PROCEDIMIENTOS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>




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
void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);

#endif