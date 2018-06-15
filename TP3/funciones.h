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
 *  @return devuelve 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(Movie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie el puntero de la estructura a ser eliminada al archivo
 *  @return devuelve 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(Movie* movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(ArrayList* arrayMovie, char* nombre);

/** \brief Encuentra un espacio de memoria para la pelicula
 *
 * \return Movie* direccion del elemento
 *
 */
Movie* movie_new();

/** \brief Libera el espacio de memoria reservado
 *
 * \param this Movie* pelicula a borrar
 * \return void
 *
 */
void movie_delete(Movie* this);

/** \brief Genera una pelicula dados todos sus campos
 *
 * \param titulo char*
 * \param genero char*
 * \param duracion int
 * \param descripcion char*
 * \param puntaje int
 * \param linkImagen char*
 * \return Movie* elemento generado
 *
 */
Movie* movie_newP(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen);

/** \brief Pide los datos y añade una pelicula al ArrayList
 *
 * \param arrayMovie ArrayList* lista de peliculas
 * \return int -1 si hubo error, 0 si OK
 *
 */
int movie_agregar(ArrayList* arrayMovie);

/** \brief Sobreescribe los datos de una pelicula de la lista
 *
 * \param arrayMovie ArrayList* lista de peliculas
 * \param index int indice de la pelicula
 * \return int -1 si el indice no existe, 0 si OK
 *
 */
int movie_modificar(ArrayList* arrayMovie,int index);

/** \brief Imprime la lista de peliculas
 *
 * \param arrayMovie ArrayList* lista de peliculas
 * \return int -1 si la lista esta vacia, 0 si OK
 *
 */
int movie_mostrar(ArrayList* arrayMovie);

/** \brief Lee y carga la lista de peliculas de un archivo binario
 *
 * \param arrayMovie ArrayList* lista de peliculas
 * \return int
 *
 */
int movie_read(ArrayList* arrayMovie);

/** \brief Guarda la lista de peliculas en un archivo binario
 *
 * \param arrayMovie ArrayList* lista de peliculas
 * \return int
 *
 */
int movie_write(ArrayList* arrayMovie);

/** \brief Compara los puntajes de dos peliculas
 *
 * \param peli1 void* Pelicula 1
 * \param peli2 void* Pelicula 2
 * \return int 1 si el puntaje de la primera es mayor, -1 si es menor, 0 si son iguales
 *
 */
int movie_compararPuntaje(void* peli1, void* peli2);

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
