#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funciones_procedimientos.h"

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
        
        supers[i].id=i+1; 
        printf("Superheroe %d\n", i+1);
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
            printf("\n");
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
            printf("\n");
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
        printf("    1: Si.\n");
        printf("    0: No.");
        printf("Estado: ");
        scanf("%d", &estado);
        if(estado==1){
            strcpy(supers[i].estado, vigencia[0]);
        }else{
            strcpy(supers[i].estado, vigencia[1]);
        }
        while(getchar()!='\n');
        
        
    }
    
    
    
}


void mostrarDatos(struct super supers[], int *ptrnumSupers, int *ptrNumeroPoderes, int *ptrNumeroDebilidades){
    for(int i=0; i<*ptrnumSupers; i++){
        printf("ID: %d\n", supers[i].id);
        printf("NOMBRE: %s\n", supers[i].nombre);
        printf("PESO: %.2f\n", supers[i].peso);
        printf("ALTURA: %.2f\n", supers[i].altura);
        printf("CIUDAD ORIGEN: %s\n", supers[i].fichaTecnica1.ciudadOrigen);
        printf("PODERES:\n");
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