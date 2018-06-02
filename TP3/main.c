#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

int main()
{
    int opcion=0;
    int cantidadActual=0;
    int cantidadMax=100;
    Movie* arrayMovie[cantidadMax];
    while(opcion!=5)
    {
        if(!getValidInt("\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n",
                    "\nPor favor, elija una opcion valida de 1 a 5\n",&opcion,1,5,1)){
            switch(opcion)
            {
                case 1:
                    if(!movie_agregar(arrayMovie,&cantidadActual,cantidadMax))
                        printf("\nPelicula agregada!\n");
                    else
                        printf("\nHa habido un error en los datos y no se ha agregado la pelicula\n");
                    break;
                case 2:
                    movie_read(arrayMovie,&cantidadActual,cantidadMax);
                    movie_mostrar(arrayMovie,cantidadActual);
                    if(!movie_borrar(arrayMovie,&cantidadActual))
                        printf("\nPelicula borrada!\n");
                    else
                        printf("\nID no encontrado\n");
                    break;
                case 3:
                    movie_read(arrayMovie,&cantidadActual,cantidadMax);
                    movie_mostrar(arrayMovie,cantidadActual);
                    if(!movie_modificar(arrayMovie,&cantidadActual))
                        printf("\nPelicula modificada!\n");
                    else
                        printf("\nID no encontrado\n");
                   break;
                case 4:
                    movie_read(arrayMovie,&cantidadActual,cantidadMax);
                    generarPagina(arrayMovie,"template/index.html",cantidadActual);
                    break;
            }
        }
    }

    return 0;
}
