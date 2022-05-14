#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


#define TAM 20
#define TAMS 3
#define TAMT 5
#define TAMC 3

int cargarDescripcionServicios(eServicios servicios[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(servicios != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( servicios[i].id == id){
                strcpy( desc, servicios[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int listarServicios(eServicios servicios[], int tam){

 int todoOk = 0;
    if(servicios != NULL && tam > 0 ){

        printf("   *** Listado de Servicios***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", servicios[i].id, servicios[i].descripcion);

         }
    }
    return todoOk;
}

int buscarServicios(eServicios vec[], int tam, int id, int* pIndex)
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


int validarServicios(eServicios vec[], int tam, int id){
 int esValido = 0;
 int indice;

 if (buscarServicios(vec, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}





