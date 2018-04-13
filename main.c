#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    int flag=0;
    int eleccion=0;
    int numero1=0;
    int numero2=0;
    float resultado;
    do{
        printf("\n1.Ingresar 1er operando (A=%d)\n2.Ingresar 2do operando (B=%d)\n3.Calcular la suma (A+B)\n4.Calcular la resta (A-B)\n5.Calcular la division (A/B)\n6.Calcular la multiplicacion (A*B)\n7.Calcular el factorial (A!)\n8.Calcular todas las operaciones\n9.Salir\n", numero1, numero2);
        fflush(stdin);
        scanf("%d",&eleccion);
        switch(eleccion){
        case 1:
            printf("\nPrimer operando: ");
            fflush(stdin);
            scanf("%d",&numero1);
            break;
        case 2:
            printf("\nSegundo operando: ");
            fflush(stdin);
            scanf("%d",&numero2);
            break;
        case 3:
            if(!suma(numero1, numero2, &resultado)){
                printf("\n%d+%d=%f\n", numero1, numero2, resultado);
            }
            else printf("ERROR");
            break;
        case 4:
            if(resta(numero1, numero2, &resultado)==0){
                printf("\n%d-%d=%g\n", numero1, numero2, resultado);
            }
            else printf("ERROR");
            break;
        case 5:
            if(division(numero1, numero2, &resultado)==0){
                printf("\n%d/%d=%g\n", numero1, numero2, resultado);
            }
            else printf("\nERROR\n");
            break;
        case 6:
            if(multiplicacion(numero1, numero2, &resultado)==0){
                printf("\n%d*%d=%g\n", numero1, numero2, resultado);
            }
            else printf("\nERROR\n");
            break;
        case 7:
            if(!factorial(numero1,&resultado)){
                printf("\n%d!=%g\n", numero1, resultado);
            }
            else printf("\nERROR\n");
            break;
        case 8:
            suma(numero1, numero2, &resultado);
            printf("\n%d+%d=%.0f\n", numero1, numero2, resultado);
            resta(numero1, numero2, &resultado);
            printf("\n%d-%d=%.0f\n", numero1, numero2, resultado);
            if(!division(numero1, numero2, &resultado)){
                printf("\n%d/%d=%.5f\n", numero1, numero2, resultado);
            }
            else printf("\nERROR\n");
            multiplicacion(numero1, numero2, &resultado);
            printf("\n%d*%d=%0.f\n", numero1, numero2, resultado);
            if(!factorial(numero1,&resultado)){
                printf("\n%d!=%.0f\n", numero1, resultado);
            }
            else printf("\nERROR\n");
            break;
        case 9:
            flag=1;
            break;
        default: printf("\nOpcion no valida.\n");
        }
    }while(!flag);
    printf("\nChau!");
    return 0;
}
