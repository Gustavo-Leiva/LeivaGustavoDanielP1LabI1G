#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

 int id;
 char descripcion[25];
 float precio;

}eServicios;



#endif // SERVICIO_H_INCLUDED

int cargarDescripcionServicios(eServicios servicios[], int tam, int id, char desc[]);
int listarServicios(eServicios servicios[], int tam);
int buscarServicios(eServicios vec[], int tam, int id, int* pIndex);
int validarServicios(eServicios vec[], int tam, int id);
