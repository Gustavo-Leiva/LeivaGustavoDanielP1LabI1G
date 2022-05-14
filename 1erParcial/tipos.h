#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


typedef struct{

 int id;
 char descripcion[20];

}eTipos;


#endif // TIPOS_H_INCLUDED
int cargarDescripcionTipos(eTipos tipos[], int tam, int id, char desc[]);
int listarTipos(eTipos tipos[], int tam);
int buscarTipos(eTipos vec[], int tam, int id, int* pIndex);
int validarTipos(eTipos vec[], int tam, int id);
