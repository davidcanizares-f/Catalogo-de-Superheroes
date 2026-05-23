/*
 * funciones_procedimientos.h
 * Archivo de cabecera que define las estructuras de datos y declara
 * los prototipos de todas las funciones del programa.
 */

#ifndef FUNCIONES_PROCEDIMIENTOS_H
#define FUNCIONES_PROCEDIMIENTOS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* ─── Anchos de columna para la tabla de visualización ─── */
#define W_ID      5   /* Ancho de la columna ID              */
#define W_NOMBRE  20  /* Ancho de la columna Nombre          */
#define W_PESO    8   /* Ancho de la columna Peso            */
#define W_ALTURA  8   /* Ancho de la columna Altura          */
#define W_CIUDAD  15  /* Ancho de la columna Ciudad de Origen*/
#define W_PODERES 25  /* Ancho de la columna Poderes         */
#define W_DEBIL   25  /* Ancho de la columna Debilidades     */
#define W_SAGA    15  /* Ancho de la columna Saga            */
#define W_ESTADO  10  /* Ancho de la columna Estado/Vigente  */


/*
 * Estructura fichaTecnica
 * Almacena los atributos técnicos de un superhéroe:
 * ciudad de origen, lista de poderes, lista de debilidades
 * y nombre del archienemigo.
 */
struct fichaTecnica {
    char ciudadOrigen[50];       /* Ciudad de origen del superhéroe          */
    char poderes[10][100];       /* Lista de hasta 10 poderes (100 chars c/u)*/
    char debilidades[10][100];   /* Lista de hasta 10 debilidades            */
    char archienemigo[80];       /* Nombre del archienemigo principal        */
};

/*
 * Estructura super
 * Representa a un superhéroe con todos sus datos:
 * identificador, nombre, medidas físicas, ficha técnica,
 * saga a la que pertenece y estado de vigencia.
 */
struct super {
    int id;                          /* Identificador único (máximo 5 dígitos) */
    char nombre[80];                 /* Nombre del superhéroe                  */
    float peso;                      /* Peso en kilogramos                     */
    float altura;                    /* Altura en metros                       */
    struct fichaTecnica fichaTecnica1; /* Ficha técnica con poderes y debilidades*/
    char saga[50];                   /* Saga o universo al que pertenece       */
    char estado[4];                  /* Estado de vigencia: "SI" o "NO"        */
};


/* ─── Prototipos de funciones ─── */

/* Muestra el encabezado inicial del programa */
void etiquetaInicial();

/* Registra los datos de todos los superhéroes ingresados por el usuario */
void registrarSuper(struct super supers[], int *ptrnumSupers,
                    int *ptrNumeroPoderes, int *ptrNumeroDebilidades);

/* Trunca una cadena al ancho máximo indicado, añadiendo "..." si se excede */
void truncar(char *destino, const char *cadena, int maxAncho);

/* Muestra todos los superhéroes registrados en formato de tabla */
void mostrarDatos(struct super supers[], int *ptrnumSupers,
                  int *ptrNumeroPoderes, int *ptrNumeroDebilidades);

/* Despliega el menú principal y retorna la opción elegida */
int menuPrincipal(int *ptrOpcionmenuPrincipal);

/* Busca un superhéroe por nombre o ID; retorna su índice o -1 si no existe */
int busquedaSuper(struct super supers[], int *ptrnumSupers);

/* Muestra los datos completos de un único superhéroe encontrado */
void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers,
                               int *ptrNumeroPoderes, int *ptrNumeroDebilidades,
                               int *ptrIndiceEncontrado);

/* Permite cambiar el estado de vigencia (SI/NO) de un superhéroe */
void actualizarEstado(struct super supers[], int *ptrnumSupers);

/* Elimina el registro de un superhéroe del arreglo */
void eliminarRegistro(struct super supers[], int *ptrnumSupers);

#endif /* FUNCIONES_PROCEDIMIENTOS_H */