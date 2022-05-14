#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"


#define TAM 20
#define TAMS 3
#define TAMT 5
#define TAMC 3

int cargarDescripcionColores(eColores colores[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(colores != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( colores[i].id == id){
                strcpy( desc, colores[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int listarColores(eColores colores[], int tam){

 int todoOk = 0;
    if(colores!= NULL && tam > 0 ){

        printf("   *** Listado de Colores***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", colores[i].id, colores[i].descripcion);

         }
    }
    return todoOk;
}

int buscarColores(eColores vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarColores(eColores vec[], int tam, int id){
 int esValido = 0;
 int indice;

 if (buscarColores(vec, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}



