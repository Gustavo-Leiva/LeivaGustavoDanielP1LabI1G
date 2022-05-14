#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

 int id;
 char descripcion[20];

}eColores;

#endif // COLOR_H_INCLUDED
int cargarDescripcionColores(eColores colores[], int tam, int id, char desc[]);
int listarColores(eColores colores[], int tam);
int buscarColores(eColores vec[], int tam, int id, int* pIndex);
int validarColores(eColores vec[], int tam, int id);
