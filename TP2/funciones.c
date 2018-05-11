#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

int persona_init(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    if(limite>0&&lista!=NULL){
        retorno=0;
        for(i=0;i<limite;i++){
            lista[i].estado=1;
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    if((limite > 0) && (lista != NULL)){
        for(i=0; i < limite; i++){
            if(lista[i].estado == 1){
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int persona_alta(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    char nombre[50];
    int edad;
    int dni;
    if(limite>0&&lista!=NULL){
        i=obtenerEspacioLibre(lista,limite);
        if(i>=0){
            if(!getValidString("\nNombre: ","\nEso no es un nombre\n","\n50 caracteres maximo\n",nombre,50,2)){
                if(!getValidInt("\nEdad: ","\n1 - 120\n",&edad,1,120,2)){
                    if(!getValidInt("\nDNI: ","\nDNI invalido\n",&dni,1,99999999,2)){
                        retorno=0;
                        strcpy(lista[i].nombre,nombre);
                        lista[i].edad=edad;
                        lista[i].dni=dni;
                        lista[i].estado=0;
                    }
                }
            }
            else retorno=-3;
        }
        else{
            retorno=-2;
        }
    }
    return retorno;
}

int buscarPorDni(EPersona* lista,int limite,int dni)
{
    int retorno=-1;
    int i;
    if(limite>0&&lista!=NULL){
        for(i=0;i<limite;i++){
            if(!lista[i].estado && lista[i].dni==dni){
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int persona_baja(EPersona* lista,int limite)
{
    int retorno=-1;
    int dni;
    if(!getValidInt("DNI de persona a borrar: ","DNI invalido\n",&dni,1,99999999,2)){
        int indice=buscarPorDni(lista,limite,dni);
        if(indice>=0){
            lista[indice].estado=1;
            retorno=0;
        }
        else
            retorno=-2;
    }
    return retorno;
}

int mostrar(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    if(limite>0&&lista!=NULL){
        retorno=0;
        for(i=0;i<limite;i++){
            if(!lista[i].estado){
                printf("\nNombre: %s - Edad: %d - DNI: %d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
            }
        }
    }
    return retorno;
}

int persona_ordenar(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    int flagSwap;
    EPersona aux;
    if(limite>0&&lista!=NULL){
        retorno=0;
        do{
            flagSwap=0;
            for(i=0;i<limite-1;i++){
                if((strcmp(lista[i].nombre,lista[i+1].nombre)>0)){
                    aux=lista[i];
                    lista[i]=lista[i+1];
                    lista[i+1]=aux;
                    flagSwap=1;
                }
           }
        }while(flagSwap);
        mostrar(lista,limite);
    }
    return retorno;
}


int persona_grafico(EPersona* lista,int limite)
{
    int retorno=-1;
    int i;
    int edad1=0;
    int edad2=0;
    int edad3=0;
    for(i=0;i<limite;i++){
        if(!lista[i].estado){
            retorno=0;
            if(lista[i].edad<18){
                edad1++;
            }
            else if(lista[i].edad>=19&&lista[i].edad<=35){
                edad2++;
            }
            else if(lista[i].edad!=18)
                edad3++;
        }
    }
    printf("\n");
    while((edad1||edad2)||edad3){
        if(edad1==edad2&&edad2==edad3){
            printf(" *      *      *");
            edad1--;
            edad2--;
            edad3--;
        }
        else{
            if(edad1>edad2&&edad1>edad3){
                printf(" *");
                edad1--;
            }
            else{
                if(edad1==edad2&&edad2>edad3){
                printf(" *      *");
                edad1--;
                edad2--;
                }
                else{
                    if(edad2>edad3){
                    printf("        *");
                    edad2--;
                    }
                    else{
                        if(edad2==edad3){
                            printf("        *      *");
                            edad2--;
                            edad3--;
                        }
                        else{
                            if(edad1==edad3){
                                printf(" *             *");
                                edad1--;
                                edad3--;
                            }
                            else{
                                printf("               *");
                                edad3--;
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    printf("<18   19-35   >35\n\n");
    return retorno;
}

/*int persona_altaForzada(EPersona* lista,int limite,char* nombre,int edad,int dni)
{
    int retorno=-1;
    int i;
    if(limite>0&&lista!=NULL){
        i=obtenerEspacioLibre(lista,limite);
        if(i>=0){
            retorno=0;
            strcpy(lista[i].nombre,nombre);
            lista[i].edad=edad;
            lista[i].dni=dni;
            lista[i].estado=0;
        }
            else retorno=-3;
    }
        else{
            retorno=-2;
        }
    return retorno;
}*/
