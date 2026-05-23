#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funciones_procedimientos.h"



void etiquetaInicial(){
    printf("\n===========================\n");
    printf("- REGISTRO DE SUPERHEROES -\n");
    printf("===========================\n");
}


void registrarSuper(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades){
    
    for(int i=0; i<*ptrnumSupers; i++){
        char nombre[100];
        char ciudadOrigen[100];
        char poderes[*ptrNumeroPoderes][100];
        char debilidades[*ptrNumeroDebilidades][100];
        char archienemigo[100];
        char saga[100];
        char vigencia[2][4]={"SI", "NO"};
        int estado;
        float peso;
        float altura;
        int id;
        
 
        printf("\n<<< SUPERHEROE %d >>>\n", i+1);
        printf("------------------------------\n");


        printf("> ID (MAXIMO 5 CARACTERES): ");
        while((scanf("%d", &id) !=1) || (id)<=0 || (id)>=100000){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("> ID (MAXIMO 5 CARACTERES): ");

        }
        getchar();
        
        
        for(int i=0; i<*ptrnumSupers; i++){
            while(supers[i].id == id){
                printf("\n[INVALIDO] ID ya registrado.\n");
                printf("> ID (MAXIMO 5 CARACTERES): ");
                while((scanf("%d", &id) !=1) || (id)<=0 || (id)>=100000){
                    printf("\n[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
                    while(getchar()!='\n');
                    printf("> ID (MAXIMO 5 CARACTERES): ");

                }
                getchar();
            }
        }
        
        supers[i].id=id;

        
        printf("> Nombre: ");
        fgets(nombre, 100, stdin);
        nombre[strcspn(nombre, "\n")]='\0';
        strcpy(supers[i].nombre, nombre);

        printf("> Peso (kg): ");
        while((scanf("%f", &peso) !=1) || (peso)<=0){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("> Peso (kg): ");

        }
        getchar();

        supers[i].peso=peso;

        printf("> Altura (m): ");
        while((scanf("%f", &altura) !=1) || (altura)<=0){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("> Altura (m): ");

        }
        supers[i].altura=altura;

        while(getchar()!='\n');
        printf("> Ciudad de Origen: ");
        fgets(ciudadOrigen, 100, stdin);
        ciudadOrigen[strcspn(ciudadOrigen, "\n")]='\0';
        strcpy(supers[i].fichaTecnica1.ciudadOrigen, ciudadOrigen);

        printf("> Poderes: \n");
        printf("\tCantidad de poderes: ");
        while((scanf("%d", ptrNumeroPoderes) !=1) || (*ptrNumeroPoderes)<=0){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("\tCantidad de poderes: ");

        }
        getchar();


        for(int j=0; j<*ptrNumeroPoderes; j++){
            
            printf("\tPoder %d: ", j+1 );
            fgets(poderes[j], 80, stdin);
            poderes[j][strcspn(poderes[j], "\n")]='\0';
            strcpy(supers[i].fichaTecnica1.poderes[j], poderes[j]);
        }

        
        printf("> Debilidades: \n");
        printf("\tCantidad de debilidades: ");
        while((scanf("%d", ptrNumeroDebilidades) !=1) || (*ptrNumeroDebilidades)<=0){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("\tCantidad de debilidades: ");

        }
        getchar();

        for(int j=0; j<*ptrNumeroDebilidades; j++){
            
            printf("\tDebilidad %d: ", j+1 );
            fgets(debilidades[j], 80, stdin);
            debilidades[j][strcspn(debilidades[j], "\n")]='\0';
            strcpy(supers[i].fichaTecnica1.debilidades[j], debilidades[j]);
        }

        
        printf("> Archienemigo: ");
        fgets(archienemigo, 100, stdin);
        archienemigo[strcspn(archienemigo, "\n")]='\0';
        strcpy(supers[i].fichaTecnica1.archienemigo, archienemigo);

        
        printf("> Saga: ");
        fgets(saga, 100, stdin);
        saga[strcspn(saga, "\n")]='\0';
        strcpy(supers[i].saga, saga);
        
        printf("> Estado (Vigente): \n");
        printf("    [1]: Si.\n");
        printf("    [0]: No.\n");
        printf("    Vigente: ");
        while((scanf("%d", &estado) !=1) || estado>1 || estado<0){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("> Estado (Vigente): \n");
            printf("    [1]: Si.\n");
            printf("    [0]: No.\n");
            printf("    Vigente: ");

        }

        if(estado==1){
            strcpy(supers[i].estado, vigencia[0]);
        }else{
            strcpy(supers[i].estado, vigencia[1]);
        }
        
        
        
    }
    
    
    
}


int menuPrincipal(int *ptrOpcionmenuPrincipal){
    
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
    
    while(scanf("%d", ptrOpcionmenuPrincipal)!=1 || (*ptrOpcionmenuPrincipal)>5 || *ptrOpcionmenuPrincipal<1){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
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

// Trunca src en maxAncho caracteres, añadiendo "..." si se excede
void truncar(char *destino, const char *cadena, int maxAncho) {
    if ((int)strlen(cadena) > maxAncho) {
        snprintf(destino, maxAncho - 2, "%s", cadena); // copia maxAncho-3 chars
        strcat(destino, "...");
    } else {
        snprintf(destino, maxAncho + 1, "%s", cadena);
    }
}

void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades) {

    int totalAncho = W_ID + W_NOMBRE + W_PESO + W_ALTURA + W_CIUDAD + W_PODERES + W_DEBIL + W_SAGA + W_ESTADO + 8;

    printf("\n");
    for (int k = 0; k < totalAncho; k++){
        printf("=");
    } 
    printf("\n");

    // Encabezado
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

    for (int k = 0; k < totalAncho; k++){
        printf("=");
    }
    printf("\n");

    for (int i = 0; i < *ptrnumSupers; i++) {

        // Buffers truncados para campos fijos
        char nombreTrunc[W_NOMBRE + 1];
        char ciudadTrunc[W_CIUDAD + 1];
        char sagaTrunc[W_SAGA + 1];
        char estadoTrunc [W_ESTADO + 1];

        truncar(nombreTrunc, supers[i].nombre, W_NOMBRE);
        truncar(ciudadTrunc, supers[i].fichaTecnica1.ciudadOrigen, W_CIUDAD);
        truncar(sagaTrunc,   supers[i].saga, W_SAGA);
        truncar(estadoTrunc, supers[i].estado, W_ESTADO);

        // Contar poderes y debilidades reales (no vacíos)
        int numPoderes = 0, numDebil = 0;
        for (int j = 0; j < *ptrNumeroPoderes; j++)
            if (strlen(supers[i].fichaTecnica1.poderes[j]) > 0) numPoderes++;
        for (int j = 0; j < *ptrNumeroDebilidades; j++)
            if (strlen(supers[i].fichaTecnica1.debilidades[j]) > 0) numDebil++;

        int filas;
        if(numPoderes > numDebil){
            filas=numPoderes;
        }else{
            filas=numDebil;
        }
        if (filas == 0) filas = 1;

        for (int fila = 0; fila < filas; fila++) {

            if (fila == 0) {
                printf("%-*d %-*s %-*.2f %-*.2f %-*s ",
                       W_ID,     supers[i].id,
                       W_NOMBRE, nombreTrunc,
                       W_PESO,   supers[i].peso,
                       W_ALTURA, supers[i].altura,
                       W_CIUDAD, ciudadTrunc);
            } else {
                printf("%-*s %-*s %-*s %-*s %-*s ",
                       W_ID,     "",
                       W_NOMBRE, "",
                       W_PESO,   "",
                       W_ALTURA, "",
                       W_CIUDAD, "");
            }

            // Columna PODERES
            if (fila < numPoderes) {
                char poderTrunc[W_PODERES + 1];
                truncar(poderTrunc, supers[i].fichaTecnica1.poderes[fila], W_PODERES - 1); // -1 por el guion
                printf("-%-*s ", W_PODERES - 1, poderTrunc);
            } else {
                printf("%-*s ", W_PODERES, "");
            }

            // Columna DEBILIDADES
            if (fila < numDebil) {
                char debilTrunc[W_DEBIL + 1];
                truncar(debilTrunc, supers[i].fichaTecnica1.debilidades[fila], W_DEBIL - 1); // -1 por el guion
                printf("-%-*s ", W_DEBIL - 1, debilTrunc);
            } else {
                printf("%-*s ", W_DEBIL, "");
            }

            // SAGA y ESTADO solo en la primera fila
            if (fila == 0) {
                printf("%-*s %-*s", W_SAGA, sagaTrunc, W_ESTADO, estadoTrunc);
            }

            printf("\n");
        }

        // Separador entre superhéroes
        for (int k = 0; k < totalAncho; k++){
            printf("-");
        }
        
        printf("\n");
    }
}





int busquedaSuper(struct super supers[], int *ptrnumSupers){
    char buscado[20];
    bool encontrado=false;
    int indiceEncontrado=-1;
    int opcionBusqueda;
    int idBuscado;

    do{
        printf("\n========== BUSQUEDA DE SUPERHEROE ==========\n");
        printf("[1]: Busqueda por Nombre.\n");
        printf("[2]: Busqueda por ID.\n");
        printf("[3]: Salir.\n");
        printf("--------------------------------\n");
        printf("Escoja: ");
        
        while(scanf("%d", &opcionBusqueda)!=1 || (opcionBusqueda)>3 || opcionBusqueda<1){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("\n========== BUSQUEDA DE SUPERHEROE ==========\n");
            printf("[1]: Busqueda por Nombre.\n");
            printf("[2]: Busqueda por ID.\n");
            printf("[3]: Salir.\n");
            printf("--------------------------------\n");
            printf("Escoja: ");

        }
        getchar();

        switch(opcionBusqueda){
            case 1:
                printf("Ingrese el nombre: ");
                fgets(buscado, 20, stdin);
                buscado[strcspn(buscado, "\n")]='\0';
                for(int i=0; i<*ptrnumSupers; i++){
                    if(((strcmp(buscado, supers[i].nombre))==0) && encontrado==false){
                        encontrado=true;
                        indiceEncontrado = i;
                    }
                }

                break;
            case 2:
                printf("Ingrese el ID: ");
                while(scanf("%d", &idBuscado)!=1 || idBuscado<0){
                    printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
                    while(getchar()!='\n');
                    printf("Ingrese el ID: ");

                }
                

                for(int i=0; i<*ptrnumSupers; i++){
                    if((idBuscado == supers[i].id) && encontrado==false){
                        encontrado=true;
                        indiceEncontrado = i;
                    }
                }
                break;
            case 3:
                return -1;
                break;

        }
        if(encontrado==true){
            printf("\n>>>> SUPERHEROE ENCONTRDO <<<<\n");
        }else{
            printf("\n>>>> SUPERHEROE NO ENCONTRADO <<<<\n");
        }
        
    }while(opcionBusqueda != 3 && encontrado==false);
    return indiceEncontrado;

    

}

void mostrarDatosIndividuales(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades, int *ptrIndiceEncontrado){

    if((*ptrIndiceEncontrado) < 0){
        return;
    } else{
        printf("\n=========================\n");
        printf("          %s ", supers[*ptrIndiceEncontrado].nombre);
        printf("\n=========================\n");
        printf("> ID: %d\n", supers[*ptrIndiceEncontrado].id);
        printf("> NOMBRE: %s\n", supers[*ptrIndiceEncontrado].nombre);
        printf("> PESO: %.2f\n", supers[*ptrIndiceEncontrado].peso);
        printf("> ALTURA: %.2f\n", supers[*ptrIndiceEncontrado].altura);
        printf("> CIUDAD ORIGEN: %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.ciudadOrigen);
        printf("> PODERES:\n");
        for(int j=0; j<*ptrNumeroPoderes; j++){
            printf("    - %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.poderes[j]);
            
        }
        printf("> DEBILIDADES:\n");
        for(int j=0; j<*ptrNumeroDebilidades; j++){
            printf("    - %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.debilidades[j]);
        }
        printf("> ARCHIENEMIGO: %s\n", supers[*ptrIndiceEncontrado].fichaTecnica1.archienemigo);
        printf("> SAGA: %s\n", supers[*ptrIndiceEncontrado].saga);
        printf("> ESTADO | VIGENTE: %s\n", supers[*ptrIndiceEncontrado].estado);
        printf("-------------------------------------\n");
    }
    
        
}


void actualizarEstado (struct super supers[], int *ptrnumSupers){
    int indice;
    int opcionEstado;
    printf("\n============== ACTUALIZAR ESTADO DE SUPERHEROE ==============\n");
    indice = busquedaSuper(supers, ptrnumSupers);
    if(indice < 0){
        return;
    }else{
        printf("----------------------------\n");
        printf("\nESTADO ACTUAL | VIGENTE: %s\n", supers[indice].estado);
        printf("-------------------------\n");
        printf("[1]: Cambiar Estado.\n");
        printf("[2]: Salir.\n");
        printf("-------------------------\n");
        printf("Escoja: ");
        
        while(scanf("%d", &opcionEstado)!=1 || opcionEstado<1 || opcionEstado > 2){
            printf("[ERROR]: DATO INVALIDO O FUERA DE RANGO. INGRESE NUEVAMENTE.\n");
            while(getchar()!='\n');
            printf("----------------------------\n");
            printf("\nESTADO ACTUAL | VIGENTE: %s\n", supers[indice].estado);
            printf("-------------------------\n");
            printf("[1]: Cambiar Estado.\n");
            printf("[2]: Salir.\n");
            printf("-------------------------\n");
            printf("Escoja: ");
        }
        

        switch(opcionEstado){
            case 1:
                if((strcmp(supers[indice].estado, "SI"))==0){
                    strcpy(supers[indice].estado, "NO");
                } else{
                    strcpy(supers[indice].estado, "SI");
                }
                printf("<<<< ESTADO DE SUPERHEROE CAMBIADO A: VIGENTE -> '%s' >>>>\n", supers[indice].estado);
                break;
            case 2:
                return;
                break;
        }
    }
}



void eliminarRegistro(struct super supers[], int *ptrnumSupers){
    int indice=0;
    printf("\n============== ELIMINAR REGISTRO DE SUPERHEROE ============\n");
    indice=busquedaSuper(supers, ptrnumSupers);
    if(indice < 0){
        return;
    }else{
        for(int i=indice; i<indice-1;i++){
            supers[i]=supers[i+1];
        }
        (*ptrnumSupers)--;
    }
    printf("\n<<< REGISTRO DE SUPERHEROE ELIMINADO >>>\n");

}
