#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define LEN_lista 20

int main()
{

    char seguir='s';
    int opcion=0;
    int aux;
    EPersona lista[LEN_lista];
    persona_init(lista,LEN_lista);
    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(lista,LEN_lista);
                break;
            case 2:
                aux=persona_baja(lista,LEN_lista);
                if(!aux){
                    printf("\nPersona borrada\n");
                }
                else{
                    if(aux==-2)
                        printf("\nNo se encontro el DNI en la lista\n");
                }
                break;
            case 3:
                persona_ordenar(lista,LEN_lista);
                break;
            case 4:
                persona_grafico(lista,LEN_lista);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }

    return 0;
}
