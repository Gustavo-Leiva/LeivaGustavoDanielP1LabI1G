#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "tipos.h"
#include "servicio.h"
#include "color.h"


#define TAM 20
#define TAMS 3
#define TAMT 5
#define TAMC 3

int main()
{

            char salir = 'n';
        int proximoId = 1000;
        int proximoIdServicios = 20000;
        int proximoIdColores = 5000;
        eMascota lista[TAM];
        eTipos tipos[TAMT]=
        {
            {1000, "Ave" },
            {1001, "Perro" },
            {1002, "Roedor" },
            {1003, "Gato" },
            {1004, "Pez" }
        };

        eServicios servicios[TAMS]=
        {

            {7001, "Corte", 450},
            {7002, "Desparasitado", 800 },
            {7003, "Castrado", 600}
        };

        eColores color[TAMC]=
        {

            {5000, "Negro"},
            {5001, "Blanco"},
            {5002, "Rojo"}
        };
    do
    {
        switch(menuMascotas())
        {
        case 1:
            if(altaMascota(lista, TAM, tipos, TAMT, &proximoId))
            {
                printf("Mascota cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar la Mascota\n");
            }
            break;
        case 2:
            bajaMascota(lista, TAM, tipos, TAMT);
            break;

        case 3:
            modificarMascota(lista, TAM, tipos, TAMT);
            break;

        case 4:
            system("cls");
            listarMascotas(lista, TAM, tipos, TAMT);
            break;

        case 5:
            listarTipos(lista, TAM);
            break;

        case 6:
            listarColores(lista, TAM);
            break;

        case 7:
            listarServicios(lista, TAM);
//            break;

        case 8:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}









