#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"
#include "color.h"
#include "tipos.h"
#include "servicio.h"

#define TAM 20
#define TAMS 3
#define TAMT 5
#define TAMC 3

int menuMascotas()
{

    int opcion;

    system("cls");
    printf("     *** ABM Mascota ***\n\n");
    printf("1. Alta mascota\n");
    printf("2. Baja mascota\n");
    printf("3. Modificar mascota\n");
    printf("4. Listar mascotas\n"); //ver funcion listar empleados
    printf("5. Listar tipos\n"); //ver funcion listar sectores
    printf("6. Listar colores\n"); //ver funcion listar sectores
    printf("7. Listar servicios\n"); //ver funcion listar sectores
    printf("8.Alta Trabajo\n");
    printf("9.Listar Trabajos\n");
    printf("10. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


int inicializarMascotas(eMascota vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarLibre(eMascota vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaMascota(eMascota vec[], int tam, eTipos tipos[], int tamt, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int idTipos;
    int idColor;
    eMascota nuevoMascota;
    //eFecha fecha;

    if( vec != NULL && pNextId != NULL && tipos != NULL && tam > 0 && tamt > 0)
    {
        system("cls");
        printf("    *** Alta Mascota ***\n\n");
        buscarLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoMascota.id = *pNextId;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoMascota.nombre);


            printf("ingrese edad: ");
            scanf("%d", &nuevoMascota.edad);



            listarTipos(tipos, tamt);

            printf("Ingrese id tipos: ");
            scanf("%d", &idTipos);

            // validar si existe ese id tipo
            while( !validarTipos(tipos,tamt, idTipos) )
            {
                printf("Id invalido. Reingrese id Tipo: ");
                scanf("%d", &idTipos);
            }

            nuevoMascota.idTipo = idTipos;




            //listarColores(colores, tamt);

            printf("Ingrese id color: ");
            scanf("%d", &idColor);

            // validar si existe ese id tipo
//            while( !validarColores(colores,tamc, idColor) )
//            {
//                printf("Id invalido. Reingrese id Color: ");
//                scanf("%d", &idColor);
//            }

            nuevoMascota.idColor = idColor;






            nuevoMascota.isEmpty = 0;

            vec[indice] = nuevoMascota;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}


int buscarMascota(eMascota vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMascota(eMascota mascotas[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarMascota(mascotas, tam, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}









int bajaMascota(eMascota vec[], int tam, eTipos tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( vec != NULL && tam > 0 && tipos != NULL && tamt > 0)
    {
        listarMascotas(vec, tam, tipos, tamt);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMascota(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una mascota con id: %d en el sistema\n", id);
            }
            else
            {

                mostrarMascota(vec[indice], tipos, tamt);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}


int modificarMascota(eMascota vec[], int tam, eTipos tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    int edad;
    int idTipos;
    int idColor;
    char vacunado;



    if( vec != NULL && tam > 0 && tipos != NULL && tamt > 0 )
    {
        listarMascotas(vec, tam, tipos, tamt);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMascota(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una mascota con id: %d en el sistema\n", id);
            }
            else
            {

                mostrarMascota(vec[indice], tipos, tamt);

                switch(menuModificarMascota())
                {

                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                    //valido nombre
                    strcpy(vec[indice].nombre, auxCad);
                    printf("Nombre modificado!");
                    break;

                case 2:
                    listarTipos(tipos, tamt);

                    printf("Ingrese id tipos: ");
                    scanf("%d", &idTipos);

                    // validar si existe ese id sector
                    while( !validarTipos,tamt, idTipos)
                    {
                        printf("Id invalido. Reingrese id tipos: ");
                        scanf("%d", &idTipos);
                    }

                    vec[indice].idTipo = idTipos;
                    break;

                case 3:
                    //listarColores(Colores, tamt);

                    printf("Ingrese id colores: ");
                    scanf("%d", &idColor);

//                    // validar si existe ese id color
//                    while( !validarColores,tamc, idTipos)
//                    {
//                        printf("Id invalido. Reingrese id tipos: ");
//                        scanf("%d", &idColor);
//                    }

                    vec[indice].idColor = idColor;
                    break;

                case 4:
                    printf("Ingrese nueva edad: ");
                    scanf("%d", &edad);
                    // validar edad
                    vec[indice].edad = edad;
                    printf("Edad modificada!");
                    break;

                case 5:
                    printf("Ingrese s si esta vacunado o n si no lo esta: ");
                    fflush(stdin);
                    gets(auxCad);
                    fflush(stdin);
                    scanf("%c", &vacunado);
                    printf("condicion modificada!");
                    break;



                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}


int menuModificarMascota()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. nombre\n");
    printf("2. tipo\n");
    printf("3. color\n");
    printf("4. edad\n");
    printf("5. vacunado\n");
    printf("6. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



int listarMascotas(eMascota vec[], int tam, eTipos tipos[], int tamt)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        //system("cls");
        printf("       *** Listado de Mascotas ***\n");
        printf("   id       nombre       sexo  edad     sueldo   F.Ingreso Sector\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarMascotaFila(vec[i], tipos, tamt);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay mascota en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


void mostrarMascota(eMascota masc, eTipos tipos[], int tamt)
{
    char descripcion[20];
    cargarDescripcionTipos(tipos,tamt, masc.idTipo, descripcion);

    printf("id: %d\n", masc.id);
    printf("Nombre: %s\n", masc.nombre);
    printf("id Tipo: %c\n", masc.idTipo);
    printf("id Color: %d\n", masc.idColor);
    printf("edad: %.2f\n", masc.edad);
    printf("vacunado: %s\n", descripcion);
}



void mostrarMascotaFila(eMascota masc, eTipos tipos[], int tamt)
{

    char descripcion[20];

    cargarDescripcionTipos(tipos, tamt, masc.idTipo, descripcion);


    printf("    %4d    %10s      %c    %2d    %7.2f   %02d/%02d/%d  %10s\n",
           masc.id,
           masc.nombre,
           masc.idTipo,
           masc.idColor,
           masc.edad,
           masc.vacunado
        );
}


