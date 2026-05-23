/*
 * funciones_procedimientos.c
 * Implementación de todas las funciones del Catálogo de Superhéroes.
 * Incluye registro, visualización, búsqueda, actualización y eliminación
 * de registros en el arreglo de superhéroes.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funciones_procedimientos.h"


/*
 * etiquetaInicial
 * Imprime el encabezado decorativo del programa al inicio de la ejecución.
 */
void etiquetaInicial() {
    printf("\n===========================\n");
    printf("- REGISTRO DE SUPERHEROES -\n");
    printf("===========================\n");
}


/*
 * registrarSuper
 * Solicita y almacena los datos de cada superhéroe en el arreglo supers[].
 *
 * Parámetros:
 *   supers[]            – Arreglo de estructuras super donde se guardan los datos.
 *   ptrnumSupers        – Puntero al número total de superhéroes a registrar.
 *   ptrNumeroPoderes    – Puntero a la cantidad de poderes ingresada por el usuario.
 *   ptrNumeroDebilidades– Puntero a la cantidad de debilidades ingresada.
 *
 * Valida cada campo antes de almacenarlo, repitiendo la solicitud en caso de
 * entrada inválida. También verifica que el ID no esté duplicado.
 */
void registrarSuper(struct super supers[], int *ptrnumSupers,
                    int *ptrNumeroPoderes, int *ptrNumeroDebilidades) {

    for (int i = 0; i < *ptrnumSupers; i++) {

        /* Variables locales para capturar la entrada antes de copiarla a la estructura */
        char nombre[100];
        char ciudadOrigen[100];
        char poderes[*ptrNumeroPoderes][100];
        char debilidades[*ptrNumeroDebilidades][100];
        char archienemigo[100];
        char saga[100];
        char vigencia[2][4] = {"SI", "NO"}; /* Opciones de estado válidas */
        int  estado;
        float peso;
        float altura;
        int  id;

        printf("\n<<< SUPERHEROE %d >>>\n", i + 1);
        printf("------------------------------\n");

        /* ── ID ──
         * Se valida que sea un entero positivo de máximo 5 dígitos (1-99999).
         * Se repite la lectura hasta obtener un valor válido. */
        printf("> ID (MAXIMO 5 CARACTERES): ");
        while ((scanf("%d", &id) != 1) || id <= 0 || id >= 100000) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n'); /* Limpia el buffer de entrada */
            printf("> ID (MAXIMO 5 CARACTERES): ");
        }
        getchar(); /* Consume el '\n' que queda tras el scanf */

        /* ── Validación de ID duplicado ──
         * Recorre los superhéroes ya registrados para garantizar unicidad del ID. */
        for (int i = 0; i < *ptrnumSupers; i++) {
            while (supers[i].id == id) {
                printf("\n[INVALIDO] ID ya registrado.\n");
                printf("> ID (MAXIMO 5 CARACTERES): ");
                while ((scanf("%d", &id) != 1) || id <= 0 || id >= 100000) {
                    printf("\n[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
                    while (getchar() != '\n');
                    printf("> ID (MAXIMO 5 CARACTERES): ");
                }
                getchar();
            }
        }

        supers[i].id = id; /* Almacena el ID validado */

        /* ── Nombre ── */
        printf("> Nombre: ");
        fgets(nombre, 100, stdin);
        nombre[strcspn(nombre, "\n")] = '\0'; /* Elimina el salto de línea */
        strcpy(supers[i].nombre, nombre);

        /* ── Peso ── (debe ser positivo) */
        printf("> Peso (kg): ");
        while ((scanf("%f", &peso) != 1) || peso <= 0) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("> Peso (kg): ");
        }
        getchar();
        supers[i].peso = peso;

        /* ── Altura ── (debe ser positiva) */
        printf("> Altura (m): ");
        while ((scanf("%f", &altura) != 1) || altura <= 0) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("> Altura (m): ");
        }
        supers[i].altura = altura;

        /* ── Ciudad de Origen ── */
        while (getchar() != '\n'); /* Limpia el buffer antes de fgets */
        printf("> Ciudad de Origen: ");
        fgets(ciudadOrigen, 100, stdin);
        ciudadOrigen[strcspn(ciudadOrigen, "\n")] = '\0';
        strcpy(supers[i].fichaTecnica1.ciudadOrigen, ciudadOrigen);

        /* ── Poderes ──
         * Primero solicita la cantidad y luego cada poder individual. */
        printf("> Poderes: \n");
        printf("\tCantidad de poderes: ");
        while ((scanf("%d", ptrNumeroPoderes) != 1) || *ptrNumeroPoderes <= 0) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("\tCantidad de poderes: ");
        }
        getchar();

        for (int j = 0; j < *ptrNumeroPoderes; j++) {
            printf("\tPoder %d: ", j + 1);
            fgets(poderes[j], 80, stdin);
            poderes[j][strcspn(poderes[j], "\n")] = '\0';
            strcpy(supers[i].fichaTecnica1.poderes[j], poderes[j]);
        }

        /* ── Debilidades ──
         * Mismo patrón que los poderes: cantidad primero, luego cada debilidad. */
        printf("> Debilidades: \n");
        printf("\tCantidad de debilidades: ");
        while ((scanf("%d", ptrNumeroDebilidades) != 1) || *ptrNumeroDebilidades <= 0) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("\tCantidad de debilidades: ");
        }
        getchar();

        for (int j = 0; j < *ptrNumeroDebilidades; j++) {
            printf("\tDebilidad %d: ", j + 1);
            fgets(debilidades[j], 80, stdin);
            debilidades[j][strcspn(debilidades[j], "\n")] = '\0';
            strcpy(supers[i].fichaTecnica1.debilidades[j], debilidades[j]);
        }

        /* ── Archienemigo ── */
        printf("> Archienemigo: ");
        fgets(archienemigo, 100, stdin);
        archienemigo[strcspn(archienemigo, "\n")] = '\0';
        strcpy(supers[i].fichaTecnica1.archienemigo, archienemigo);

        /* ── Saga ── */
        printf("> Saga: ");
        fgets(saga, 100, stdin);
        saga[strcspn(saga, "\n")] = '\0';
        strcpy(supers[i].saga, saga);

        /* ── Estado de vigencia ──
         * 1 → "SI" (vigente), 0 → "NO" (no vigente). */
        printf("> Estado (Vigente): \n");
        printf("    [1]: Si.\n");
        printf("    [0]: No.\n");
        printf("    Vigente: ");
        while ((scanf("%d", &estado) != 1) || estado > 1 || estado < 0) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("> Estado (Vigente): \n");
            printf("    [1]: Si.\n");
            printf("    [0]: No.\n");
            printf("    Vigente: ");
        }

        /* Convierte el entero 0/1 a la cadena correspondiente */
        if (estado == 1) {
            strcpy(supers[i].estado, vigencia[0]); /* "SI" */
        } else {
            strcpy(supers[i].estado, vigencia[1]); /* "NO" */
        }
    }
}


/*
 * menuPrincipal
 * Muestra las opciones del menú y valida la selección del usuario.
 *
 * Parámetros:
 *   ptrOpcionmenuPrincipal – Puntero donde se guarda la opción elegida.
 *
 * Retorna:
 *   El número de opción válido seleccionado (1-5).
 */
int menuPrincipal(int *ptrOpcionmenuPrincipal) {

    printf("\n==============================\n");
    printf("<<<<<< MENU DE ACCIONES >>>>>");
    printf("\n==============================\n");
    printf("[1]: Mostrar lista de Superheroes.\n");
    printf("[2]: Buscar Superheroe.\n");
    printf("[3]: Actualizar estado de Superheroe.\n");
    printf("[4]: Eliminar registro de Superheroe.\n");
    printf("[5]: Salir.\n");
    printf("-----------------------------------\n");
    printf("Escoja una opcion: ");

    /* Repite la solicitud mientras la entrada sea inválida o fuera de rango */
    while (scanf("%d", ptrOpcionmenuPrincipal) != 1 ||
           *ptrOpcionmenuPrincipal > 5 ||
           *ptrOpcionmenuPrincipal < 1) {
        printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
        while (getchar() != '\n');
        printf("\n==============================\n");
        printf("<<<<<< MENU DE ACCIONES >>>>>");
        printf("\n==============================\n");
        printf("[1]: Mostrar lista de Superheroes.\n");
        printf("[2]: Buscar Superheroe.\n");
        printf("[3]: Actualizar estado de Superheroe.\n");
        printf("[4]: Eliminar registro de Superheroe.\n");
        printf("[5]: Salir.\n");
        printf("-----------------------------------\n");
        printf("Escoja una opcion: ");
    }

    return *ptrOpcionmenuPrincipal;
}


/*
 * truncar
 * Copia src en destino recortándolo a maxAncho caracteres.
 * Si la cadena excede el ancho, añade "..." al final.
 *
 * Parámetros:
 *   destino  – Buffer de salida (debe tener al menos maxAncho+1 bytes).
 *   cadena   – Cadena fuente a truncar.
 *   maxAncho – Número máximo de caracteres visibles en el resultado.
 */
void truncar(char *destino, const char *cadena, int maxAncho) {
    if ((int)strlen(cadena) > maxAncho) {
        /* Copia solo los primeros (maxAncho-3) caracteres y añade "..." */
        snprintf(destino, maxAncho - 2, "%s", cadena);
        strcat(destino, "...");
    } else {
        /* La cadena cabe sin recortar */
        snprintf(destino, maxAncho + 1, "%s", cadena);
    }
}


/*
 * mostrarDatos
 * Imprime en formato de tabla todos los superhéroes registrados.
 * Los campos largos se truncan con truncar() para mantener el alineado.
 * Poderes y debilidades se listan una por fila dentro de la misma entrada.
 *
 * Parámetros:
 *   supers[]             – Arreglo con los superhéroes registrados.
 *   ptrnumSupers         – Número actual de superhéroes.
 *   ptrNumeroPoderes     – Número de poderes por superhéroe.
 *   ptrNumeroDebilidades – Número de debilidades por superhéroe.
 */
void mostrarDatos(struct super supers[], int *ptrnumSupers,
                  int *ptrNumeroPoderes, int *ptrNumeroDebilidades) {

    /* Calcula el ancho total de la tabla sumando columnas y separadores */
    int totalAncho = W_ID + W_NOMBRE + W_PESO + W_ALTURA + W_CIUDAD +
                     W_PODERES + W_DEBIL + W_SAGA + W_ESTADO + 8;

    /* ── Línea superior ── */
    printf("\n");
    for (int k = 0; k < totalAncho; k++) printf("=");
    printf("\n");

    /* ── Encabezado de columnas ── */
    printf("%-*s %-*s %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",
           W_ID,      "ID",
           W_NOMBRE,  "NOMBRE",
           W_PESO,    "PESO",
           W_ALTURA,  "ALTURA",
           W_CIUDAD,  "CIUDAD",
           W_PODERES, "PODERES",
           W_DEBIL,   "DEBILIDADES",
           W_SAGA,    "SAGA",
           W_ESTADO,  "VIGENTE");

    for (int k = 0; k < totalAncho; k++) printf("=");
    printf("\n");

    /* ── Filas de datos ── */
    for (int i = 0; i < *ptrnumSupers; i++) {

        /* Buffers para campos que pueden exceder el ancho de columna */
        char nombreTrunc[W_NOMBRE + 1];
        char ciudadTrunc[W_CIUDAD + 1];
        char sagaTrunc[W_SAGA + 1];
        char estadoTrunc[W_ESTADO + 1];

        truncar(nombreTrunc, supers[i].nombre, W_NOMBRE);
        truncar(ciudadTrunc, supers[i].fichaTecnica1.ciudadOrigen, W_CIUDAD);
        truncar(sagaTrunc,   supers[i].saga, W_SAGA);
        truncar(estadoTrunc, supers[i].estado, W_ESTADO);

        /* Cuenta cuántos poderes y debilidades tiene este superhéroe */
        int numPoderes = 0, numDebil = 0;
        for (int j = 0; j < *ptrNumeroPoderes; j++)
            if (strlen(supers[i].fichaTecnica1.poderes[j]) > 0) numPoderes++;
        for (int j = 0; j < *ptrNumeroDebilidades; j++)
            if (strlen(supers[i].fichaTecnica1.debilidades[j]) > 0) numDebil++;

        /* El número de filas necesarias es el mayor entre poderes y debilidades */
        int filas = (numPoderes > numDebil) ? numPoderes : numDebil;
        if (filas == 0) filas = 1; /* Mínimo una fila aunque no haya lista */

        /* Imprime una fila por cada poder/debilidad */
        for (int fila = 0; fila < filas; fila++) {

            if (fila == 0) {
                /* Primera fila: muestra id, nombre, peso, altura y ciudad */
                printf("%-*d %-*s %-*.2f %-*.2f %-*s ",
                       W_ID,     supers[i].id,
                       W_NOMBRE, nombreTrunc,
                       W_PESO,   supers[i].peso,
                       W_ALTURA, supers[i].altura,
                       W_CIUDAD, ciudadTrunc);
            } else {
                /* Filas siguientes: las columnas fijas van vacías para alinear */
                printf("%-*s %-*s %-*s %-*s %-*s ",
                       W_ID,     "",
                       W_NOMBRE, "",
                       W_PESO,   "",
                       W_ALTURA, "",
                       W_CIUDAD, "");
            }

            /* ── Columna PODERES: muestra el poder de la fila actual ── */
            if (fila < numPoderes) {
                char poderTrunc[W_PODERES + 1];
                truncar(poderTrunc, supers[i].fichaTecnica1.poderes[fila], W_PODERES - 1);
                printf("-%-*s ", W_PODERES - 1, poderTrunc);
            } else {
                printf("%-*s ", W_PODERES, ""); /* Celda vacía si no hay poder */
            }

            /* ── Columna DEBILIDADES: muestra la debilidad de la fila actual ── */
            if (fila < numDebil) {
                char debilTrunc[W_DEBIL + 1];
                truncar(debilTrunc, supers[i].fichaTecnica1.debilidades[fila], W_DEBIL - 1);
                printf("-%-*s ", W_DEBIL - 1, debilTrunc);
            } else {
                printf("%-*s ", W_DEBIL, ""); /* Celda vacía si no hay debilidad */
            }

            /* ── SAGA y ESTADO solo se imprimen en la primera fila ── */
            if (fila == 0) {
                printf("%-*s %-*s", W_SAGA, sagaTrunc, W_ESTADO, estadoTrunc);
            }

            printf("\n");
        }

        /* Separador horizontal entre superhéroes */
        for (int k = 0; k < totalAncho; k++) printf("-");
        printf("\n");
    }
}


/*
 * busquedaSuper
 * Permite buscar un superhéroe por nombre o por ID.
 * Repite el proceso hasta encontrar al superhéroe o hasta que el usuario elija salir.
 *
 * Parámetros:
 *   supers[]     – Arreglo de superhéroes registrados.
 *   ptrnumSupers – Número actual de superhéroes.
 *
 * Retorna:
 *   Índice del superhéroe encontrado en el arreglo, o -1 si no se encontró / se canceló.
 */
int busquedaSuper(struct super supers[], int *ptrnumSupers) {
    char buscado[20];
    bool encontrado = false;
    int  indiceEncontrado = -1;
    int  opcionBusqueda;
    int  idBuscado;

    do {
        printf("\n========== BUSQUEDA DE SUPERHEROE ==========\n");
        printf("[1]: Busqueda por Nombre.\n");
        printf("[2]: Busqueda por ID.\n");
        printf("[3]: Salir.\n");
        printf("--------------------------------\n");
        printf("Escoja: ");

        while (scanf("%d", &opcionBusqueda) != 1 ||
               opcionBusqueda > 3 || opcionBusqueda < 1) {
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while (getchar() != '\n');
            printf("\n========== BUSQUEDA DE SUPERHEROE ==========\n");
            printf("[1]: Busqueda por Nombre.\n");
            printf("[2]: Busqueda por ID.\n");
            printf("[3]: Salir.\n");
            printf("--------------------------------\n");
            printf("Escoja: ");
        }
        getchar();

        switch (opcionBusqueda) {

            case 1: /* ── Búsqueda por nombre (comparación exacta) ── */
                printf("Ingrese el nombre: ");
                fgets(buscado, 20, stdin);
                buscado[strcspn(buscado, "\n")] = '\0';
                for (int i = 0; i < *ptrnumSupers; i++) {
                    if (strcmp(buscado, supers[i].nombre) == 0 && !encontrado) {
                        encontrado = true;
                        indiceEncontrado = i;
                    }
                }
                break;

            case 2: /* ── Búsqueda por ID ── */
                printf("Ingrese el ID: ");
                while (scanf("%d", &idBuscado) != 1 || idBuscado < 0) {
                    printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
                    while (getchar() != '\n');
                    printf("Ingrese el ID: ");
                }
                for (int i = 0; i < *ptrnumSupers; i++) {
                    if (idBuscado == supers[i].id && !encontrado) {
                        encontrado = true;
                        indiceEncontrado = i;
                    }
                }
                break;

            case 3: /* ── El usuario elige salir sin buscar ── */
                return -1;
        }

        /* Informa si se encontró o no */
        if (encontrado)
            printf("\n>>>> SUPERHEROE ENCONTRADO <<<<\n");
        else
            printf("\n>>>> SUPERHEROE NO ENCONTRADO <<<<\n");

    } while (opcionBusqueda != 3 && !encontrado); /* Repite si no encontró */

    return indiceEncontrado;
}


/*
 * mostrarDatosIndividuales
 * Imprime todos los campos de un superhéroe específico de forma detallada.
 *
 * Parámetros:
 *   supers[]              – Arreglo de superhéroes.
 *   ptrnumSupers          – Número actual de superhéroes.
 *   ptrNumeroPoderes      – Cantidad de poderes a listar.
 *   ptrNumeroDebilidades  – Cantidad de debilidades a listar.
 *   ptrIndiceEncontrado   – Índice del superhéroe a mostrar (-1 si ninguno).
 */
void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers,
                               int *ptrNumeroPoderes, int *ptrNumeroDebilidades,
                               int *ptrIndiceEncontrado) {

    /* Si el índice es negativo, no hay nada que mostrar */
    if (*ptrIndiceEncontrado < 0) {
        return;
    }

    printf("\n=========================\n");
    printf("          %s ", supers[*ptrIndiceEncontrado].nombre);
    printf("\n=========================\n");
    printf("> ID: %d\n",             supers[*ptrIndiceEncontrado].id);
    printf("> NOMBRE: %s\n",         supers[*ptrIndiceEncontrado].nombre);
    printf("> PESO: %.2f\n",          supers[*ptrIndiceEncontrado].peso);
    printf("> ALTURA: %.2f\n",        supers[*ptrIndiceEncontrado].altura);
    printf("> CIUDAD ORIGEN: %s\n",  supers[*ptrIndiceEncontrado].fichaTecnica1.ciudadOrigen);

    /* Lista todos los poderes registrados */
    printf("> PODERES:\n");
    for (int j = 0; j < *ptrNumeroPoderes; j++)
        printf("    - %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.poderes[j]);

    /* Lista todas las debilidades registradas */
    printf("> DEBILIDADES:\n");
    for (int j = 0; j < *ptrNumeroDebilidades; j++)
        printf("    - %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.debilidades[j]);

    printf("> ARCHIENEMIGO: %s\n",   supers[*ptrIndiceEncontrado].fichaTecnica1.archienemigo);
    printf("> SAGA: %s\n",           supers[*ptrIndiceEncontrado].saga);
    printf("> ESTADO | VIGENTE: %s\n", supers[*ptrIndiceEncontrado].estado);
    printf("-------------------------------------\n");
}


/*
 * actualizarEstado
 * Localiza un superhéroe mediante busquedaSuper() y ofrece invertir su estado
 * de vigencia ("SI" → "NO" o "NO" → "SI").
 *
 * Parámetros:
 *   supers[]     – Arreglo de superhéroes.
 *   ptrnumSupers – Número actual de superhéroes.
 */
void actualizarEstado(struct super supers[], int *ptrnumSupers) {
    int indice;
    int opcionEstado;

    printf("\n============== ACTUALIZAR ESTADO DE SUPERHEROE ==============\n");

    /* Primero busca al superhéroe; si no se encuentra o se cancela, retorna */
    indice = busquedaSuper(supers, ptrnumSupers);
    if (indice < 0) return;

    /* Muestra el estado actual y solicita confirmación para cambiarlo */
    printf("----------------------------\n");
    printf("\nESTADO ACTUAL | VIGENTE: %s\n", supers[indice].estado);
    printf("-------------------------\n");
    printf("[1]: Cambiar Estado.\n");
    printf("[2]: Salir.\n");
    printf("-------------------------\n");
    printf("Escoja: ");

    while (scanf("%d", &opcionEstado) != 1 || opcionEstado < 1 || opcionEstado > 2) {
        printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
        while (getchar() != '\n');
        printf("----------------------------\n");
        printf("\nESTADO ACTUAL | VIGENTE: %s\n", supers[indice].estado);
        printf("-------------------------\n");
        printf("[1]: Cambiar Estado.\n");
        printf("[2]: Salir.\n");
        printf("-------------------------\n");
        printf("Escoja: ");
    }

    switch (opcionEstado) {
        case 1:
            /* Invierte el estado actual */
            if (strcmp(supers[indice].estado, "SI") == 0)
                strcpy(supers[indice].estado, "NO");
            else
                strcpy(supers[indice].estado, "SI");

            printf("<<<< ESTADO DE SUPERHEROE CAMBIADO A: VIGENTE -> '%s' >>>>\n",
                   supers[indice].estado);
            break;

        case 2:
            return; /* El usuario canceló sin modificar */
    }
}


/*
 * eliminarRegistro
 * Localiza un superhéroe mediante busquedaSuper() y lo elimina del arreglo
 * desplazando los elementos posteriores una posición hacia atrás.
 *
 * Nota: el bucle de desplazamiento tiene un error de condición en el original
 * (i < indice-1 debería ser i < *ptrnumSupers-1); se mantiene aquí tal cual.
 *
 * Parámetros:
 *   supers[]     – Arreglo de superhéroes.
 *   ptrnumSupers – Número actual de superhéroes (se decrementa al eliminar).
 */
void eliminarRegistro(struct super supers[], int *ptrnumSupers) {
    int indice = 0;

    printf("\n============== ELIMINAR REGISTRO DE SUPERHEROE ============\n");

    /* Busca el superhéroe a eliminar */
    indice = busquedaSuper(supers, ptrnumSupers);
    if (indice < 0) return;

    /* Desplaza los elementos posteriores una posición hacia la izquierda */
    for (int i = indice; i < indice - 1; i++) {
        supers[i] = supers[i + 1];
    }

    (*ptrnumSupers)--; /* Reduce el contador de superhéroes registrados */

    printf("\n<<< REGISTRO DE SUPERHEROE ELIMINADO >>>\n");
}