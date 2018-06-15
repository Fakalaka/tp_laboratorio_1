#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"

int main()
{
    int opcion=0;
    int index;
    ArrayList* arrayMovie=al_newArrayList();
    movie_read(arrayMovie);
    while(opcion!=6)
    {
        if(!getValidInt("\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Ordenar peliculas por puntaje\n5- Generar pagina web\n6- Salir\n",
                    "\nPor favor, elija una opcion valida de 1 a 5\n",&opcion,1,6,1)){
            switch(opcion)
            {
                case 1:
                    if(!movie_agregar(arrayMovie)){
                        printf("\nPelicula agregada!\n");
                        movie_write(arrayMovie);
                    }
                    else
                        printf("\nHa habido un error en los datos y no se ha agregado la pelicula\n");
                    break;
                case 2:

                    movie_mostrar(arrayMovie);
                    getValidInt("\nIndice de la pelicula a borrar: ","Indice invalido\n",&index,0,100,2);
                    if(!al_remove(arrayMovie,index))
                        printf("\nPelicula borrada!\n");
                    else
                        printf("\nIndice no encontrado\n");
                    movie_write(arrayMovie);
                    break;
                case 3:
                    movie_mostrar(arrayMovie);
                    getValidInt("\nIndice de la pelicula a modificar: ","Indice invalido\n",&index,0,100,2);
                    if(!movie_modificar(arrayMovie,index))
                        printf("\nPelicula modificada!\n");
                    else
                        printf("\nError\n");
                    movie_write(arrayMovie);
                   break;
                case 4:
                    al_sort(arrayMovie,movie_ordenarPuntaje,0);
                    movie_write(arrayMovie);
                    break;
                case 5:
                    generarPagina(arrayMovie,"template/index.html");
                    printf("\nPagina web generada!\n");
                    break;
            }
        }
    }

    return 0;
}
