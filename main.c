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
#include "funciones_procedimientos.c" /////////borrar para la version final


/* ── Prototipos de funciones (definidas en funciones_procedimientos.c) ── */
void registrarSuper(struct super supers[], int *ptrSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void truncar(char *destino, const char *cadena, int maxAncho);
void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades);
void etiquetaInicial();
int menuPrincipal(int *ptrOpcionmenuPrincipal);
int busquedaSuper(struct super supers[], int *ptrnumSupers);
void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades, int *ptrIndiceEncontrado);
void actualizarEstado (struct super supers[], int *ptrnumSupers);
void eliminarRegistro(struct super supers[], int *ptrnumSupers);

/*
 * main
 * Punto de entrada del programa.
 * Inicializa las variables de control, solicita la cantidad de superhéroes,
 * llama al registro inicial y luego ejecuta el menú principal en bucle
 * hasta que el usuario seleccione la opción de salir (5).
 */

int main(){
    /* ── Variables para el conteo de poderes y debilidades ──
     * Se usan punteros porque las funciones de registro los modifican. */
    int numeroPoderes=0;
    int *ptrNumeroPoderes;
    ptrNumeroPoderes=&numeroPoderes;
    
    int numeroDebilidades=0;
    int *ptrNumeroDebilidades;
    ptrNumeroDebilidades=&numeroDebilidades;

    
    /* ── Variable para el total de superhéroes registrados ── */
    int numeroSupers=0;
    int *ptrnumSupers;
    ptrnumSupers=&numeroSupers;    

    /* ── Variable para la opción elegida en el menú principal ── */
    int opcionMenuPrincipal=0;
    int *ptrOpcionmenuPrincipal;
    ptrOpcionmenuPrincipal=&opcionMenuPrincipal;

    /* ── Índice del superhéroe encontrado en una búsqueda ── */
    int indiceEncontrado=0;
    int *ptrIndiceEncontrado;
    ptrIndiceEncontrado=&indiceEncontrado;
    

    
    /* ── Encabezado del programa ── */
    etiquetaInicial();

    /* ── Solicita la cantidad de superhéroes a registrar (máximo 10) ── */
    printf("\nIngrese el numero de Superheroes a registrar: ");
    while((scanf("%d", ptrnumSupers) !=1) || (*ptrnumSupers)<=0 || (*ptrnumSupers) > 10){
        printf("[ERROR]: DATO INVALIDO. INGRESE NUEVAMENTE.\n");
        while(getchar()!='\n'); /* Limpia el buffer de entrada */
        printf("\nIngrese el numero de Superheroes a registrar: ");

    }
    getchar(); /* Consume el '\n' residual del scanf */
    

    /* ── Declara el arreglo de superhéroes con el tamaño indicado por el usuario ── */
    struct super supers[*ptrnumSupers];

    /* ── Fase de registro: captura los datos de cada superhéroe ── */
    registrarSuper(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
    

    /* ── Bucle principal del menú: se repite hasta que el usuario elija "Salir" ── */
    do{
        opcionMenuPrincipal=menuPrincipal(ptrOpcionmenuPrincipal);
        switch(opcionMenuPrincipal){
            case 1:  /* Mostrar todos los superhéroes en tabla */
                mostrarDatos(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades);
                break;
            case 2: /* Buscar un superhéroe y mostrar su ficha completa */
                (*ptrIndiceEncontrado)= busquedaSuper(supers, ptrnumSupers);
                mostrarDatosIndividuales(supers, ptrnumSupers, ptrNumeroPoderes, ptrNumeroDebilidades, ptrIndiceEncontrado);
                break;
            case 3: /* Cambiar el estado de vigencia de un superhéroe */
                actualizarEstado (supers, ptrnumSupers);
                break;
            case 4: /* Eliminar el registro de un superhéroe */
                eliminarRegistro(supers, ptrnumSupers);
                break;
            case 5: /*Salir del programa*/
                printf("\n======================\n");
                printf("  SALISTE DEL PROGRAMA\n");
                printf("=========================\n");
                break;
        }

    }while(opcionMenuPrincipal!=5); /* Continúa hasta que se elija salir */
    
    return 0;
}