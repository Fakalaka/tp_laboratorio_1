#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[500];
}Movie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie el puntero de la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(Movie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie el puntero de la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(Movie* movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(ArrayList* arrayMovie, char* nombre);

Movie* movie_new();
void movie_delete(Movie* this);
Movie* movie_newP(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen);
int movie_agregar(ArrayList* arrayMovie);
Movie* buscarPorId(Movie** arrayMovie);
int movie_borrar(Movie** arrayMovie);
int movie_modificar(ArrayList* arrayMovie,int index);
int movie_mostrar(ArrayList* arrayMovie);
int movie_read(ArrayList* arrayMovie);
int movie_init(Movie** arrayMovie);
int movie_write(ArrayList* arrayMovie);
int movie_ordenarPuntaje(Movie* peli1, Movie* peli2);

/** \brief
 *
 * \param this Movie*
 * \param titulo char*
 * \return int
 *
 */
int movie_setTitulo(Movie* this, char* titulo);

/** \brief
 *
 * \param this Movie*
 * \param titulo char*
 * \return int
 *
 */
int movie_getTitulo(Movie* this, char* titulo);

/** \brief
 *
 * \param this Movie*
 * \param genero char*
 * \return int
 *
 */
int movie_setGenero(Movie* this, char* genero);

/** \brief
 *
 * \param this Movie*
 * \param genero char*
 * \return int
 *
 */
int movie_getGenero(Movie* this, char* genero);

/** \brief
 *
 * \param this Movie*
 * \param duracion char*
 * \return int
 *
 */
int movie_setDuracion(Movie* this, int duracion);

/** \brief
 *
 * \param this Movie*
 * \param duracion char*
 * \return int
 *
 */
int movie_getDuracion(Movie* this, int* duracion);

/** \brief
 *
 * \param this Movie*
 * \param descripcion char*
 * \return int
 *
 */
int movie_setDescripcion(Movie* this, char* descripcion);

/** \brief
 *
 * \param this Movie*
 * \param descripcion char*
 * \return int
 *
 */
int movie_getDescripcion(Movie* this, char* descripcion);

/** \brief
 *
 * \param this Movie*
 * \param puntaje char*
 * \return int
 *
 */
int movie_setPuntaje(Movie* this, int puntaje);

/** \brief
 *
 * \param this Movie*
 * \param puntaje char*
 * \return int
 *
 */
int movie_getPuntaje(Movie* this, int* puntaje);

/** \brief
 *
 * \param this Movie*
 * \param linkImagen char*
 * \return int
 *
 */
int movie_setLinkImagen(Movie* this, char* linkImagen);

/** \brief
 *
 * \param this Movie*
 * \param linkImagen char*
 * \return int
 *
 */
int movie_getLinkImagen(Movie* this, char* linkImagen);

#endif // FUNCIONES_H_INCLUDED
