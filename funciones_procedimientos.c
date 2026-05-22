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


        printf("> ID: ");
        scanf("%d", &id);
        getchar();
        
        
        for(int i=0; i<*ptrnumSupers; i++){
            while(supers[i].id == id){
                printf("[INVALIDO] ID ya registrado.\n");
                printf("> ID: ");
                scanf("%d", &id);
                getchar();
            }
        }
        
        supers[i].id=id;

        
        printf("> Nombre: ");
        fgets(nombre, 100, stdin);
        nombre[strcspn(nombre, "\n")]='\0';
        strcpy(supers[i].nombre, nombre);

        printf("> Peso (kg): ");
        scanf("%f", &peso);
        supers[i].peso=peso;

        printf("> Altura (m): ");
        scanf("%f", &altura);
        supers[i].altura=altura;

        printf("> Ciudad de Origen: ");
        while(getchar()!='\n');
        fgets(ciudadOrigen, 100, stdin);
        ciudadOrigen[strcspn(ciudadOrigen, "\n")]='\0';
        strcpy(supers[i].fichaTecnica1.ciudadOrigen, ciudadOrigen);

        printf("> Poderes: \n");
        printf("\tCantidad de poderes: ");
        scanf("%d", ptrNumeroPoderes);
        getchar();
        for(int j=0; j<*ptrNumeroPoderes; j++){
            printf("\tPoder %d: ", j+1 );
            fgets(poderes[j], 80, stdin);
            poderes[j][strcspn(poderes[j], "\n")]='\0';
            strcpy(supers[i].fichaTecnica1.poderes[j], poderes[j]);
        }

        printf("> Debilidades: \n");
        printf("\tCantidad de debilidades: ");
        scanf("%d", ptrNumeroDebilidades);
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
        scanf("%d", &estado);
        if(estado==1){
            strcpy(supers[i].estado, vigencia[0]);
        }else{
            strcpy(supers[i].estado, vigencia[1]);
        }
        while(getchar()!='\n');
        
        
    }
    
    
    
}


int menuPrincipal(int *ptrOpcionmenuPrincipal){
    
    printf("\n==============================\n");
    printf("\n<<<<<< MENU DE ACCIONES >>>>>\n");
    printf("\n==============================\n");
    printf("[1]: Mostrar lista de Superheroes.\n");
    printf("[2]: Buscar Superheroe.\n");
    printf("[3]: Actualizar estado de Superheroe.\n");
    printf("[4]: Eliminar registro de Superheroe.\n");
    printf("[5]: Salir.\n");
    printf("-----------------------------------\n");
    printf("Escoja una opcion: ");
    scanf("%d", ptrOpcionmenuPrincipal);

    return *ptrOpcionmenuPrincipal;
}

void mostrarDatosTabla(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades){
    for(int i=0; i<*ptrnumSupers; i++){
        printf("\t");
        printf("ID: %d", supers[i].id);
        printf("\tNOMBRE: %s", supers[i].nombre);
        printf("\tPESO: %.2f kg", supers[i].peso);
        printf("\tALTURA: %.2f m", supers[i].altura);
        printf("\tCIUDAD ORIGEN: %s", supers[i].fichaTecnica1.ciudadOrigen);
        printf("\tPODERES:");
        for(int j=0; j<*ptrNumeroPoderes; j++){
            printf("    - %s\n", supers[i].fichaTecnica1.poderes[j]);
            
        }
        printf("DEBILIDADES:\n");
        for(int j=0; j<*ptrNumeroDebilidades; j++){
            printf("    - %s\n", supers[i].fichaTecnica1.debilidades[j]);
        }
        printf("ARCHIENEMIGO: %s\n", supers[i].fichaTecnica1.archienemigo);
        printf("SAGA: %s\n", supers[i].saga);
        printf("ESTADO | VIGENTE: %s\n", supers[i].estado);
        printf("-------------------------------------\n");
        
    }
}
