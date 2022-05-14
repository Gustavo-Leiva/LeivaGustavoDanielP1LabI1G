#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "tipos.h"

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
} eMascota;


#endif // MASCOTA_H_INCLUDED
int menuMascotas();
int inicializarMascotas(eMascota vec[], int tam);
int altaMascota(eMascota vec[], int tam, eTipos tipos[], int tamt, int* pNextId);
int bajaMascota(eMascota vec[], int tam, eTipos tipos[], int tamt);
int buscarLibre(eMascota vec[], int tam, int* pIndex);
int buscarMascota(eMascota vec[], int tam, int id, int* pIndex);
int listarMascotas(eMascota vec[], int tam, eTipos tipos[], int tamt);
int menuModificarMascota();
int modificarMascota(eMascota vec[], int tam, eTipos tipos[], int tamt);
void mostrarMascota(eMascota emp, eTipos tipos[], int tamt);
void mostrarMascotaFila(eMascota masc, eTipos tipos[], int tamt);
int validarMascota(eMascota mascotas[], int tam, int id);
