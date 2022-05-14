#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

#define TAM 20
#define TAMS 3
#define TAMT 5
#define TAMC 3

int cargarDescripcionTipos(eTipos tipos[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int listarTipos(eTipos tipos[], int tam){

 int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("   *** Listado de Tipos***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", tipos[i].id, tipos[i].descripcion);

         }
    }
    return todoOk;
}

int buscarTipos(eTipos vec[], int tam, int id, int* pIndex)
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


int validarTipos(eTipos vec[], int tam, int id){
 int esValido = 0;
 int indice;

 if (buscarTipos(vec, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}








