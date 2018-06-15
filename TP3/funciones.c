#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"

static int isValidTitulo(char* titulo);
static int isValidDuracion(int duracion);
static int isValidPuntaje(int puntaje);

Movie* movie_new()
{
    return malloc(sizeof(Movie));
}

Movie* movie_newP(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen)
{
    Movie* this=movie_new();
    if(!movie_setTitulo(this,titulo) && !movie_setGenero(this,genero)&&
        !movie_setDuracion(this,duracion) && !movie_setDescripcion(this,descripcion)&&
        !movie_setPuntaje(this,puntaje) && !movie_setLinkImagen(this,linkImagen)){
        return this;
    }
    movie_delete(this);
    return NULL;
}

void movie_delete(Movie* this)
{
    if(this!=NULL)
        free(this);
}

int movie_write(ArrayList* arrayMovie)
{
    int i;
    Movie* aux;
    FILE* path=fopen("pelis.bin","wb");
    for(i=0;i<al_len(arrayMovie);i++){
        aux=al_get(arrayMovie,i);
        fwrite(aux,sizeof(Movie),1,path);
    }
    fclose(path);
    return 0;
}

int movie_read(ArrayList* arrayMovie)
{
    int cant;
    Movie* aux;
    al_clear(arrayMovie);
    FILE* path=fopen("pelis.bin","rb");
    while(!feof(path)){
        aux=movie_new();
        cant=fread(aux,sizeof(Movie),1,path);
        if(cant==1)
            al_add(arrayMovie,aux);
    }
    fclose(path);
    return 0;
}

int movie_setTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && isValidTitulo(titulo))
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}

int movie_getTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo,this->titulo);
    }
    return retorno;
}

int movie_setGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && isValidTitulo(genero))
    {
        retorno = 0;
        strcpy(this->genero,genero);
    }
    return retorno;
}

int movie_getGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero,this->genero);
    }
    return retorno;
}

int movie_setDuracion(Movie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL && isValidDuracion(duracion))
    {
        retorno = 0;
        this->duracion=duracion;
    }
    return retorno;
}

int movie_getDuracion(Movie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        *duracion=this->duracion;
    }
    return retorno;
}

int movie_setDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && isValidTitulo(descripcion))
    {
        retorno = 0;
        strcpy(this->descripcion,descripcion);
    }
    return retorno;
}

int movie_getDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(descripcion,this->descripcion);
    }
    return retorno;
}

int movie_setPuntaje(Movie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL && isValidPuntaje(puntaje))
    {
        retorno = 0;
        this->puntaje=puntaje;
    }
    return retorno;
}

int movie_getPuntaje(Movie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        *puntaje=this->puntaje;
    }
    return retorno;
}

int movie_setLinkImagen(Movie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL && isValidTitulo(linkImagen))
    {
        retorno = 0;
        strcpy(this->linkImagen,linkImagen);
    }
    return retorno;
}

int movie_getLinkImagen(Movie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(linkImagen,this->linkImagen);
    }
    return retorno;
}

int movie_agregar(ArrayList* arrayMovie)
{
    Movie* aux;
    int retorno=-1;
    char bTitulo[4096];
    char bGenero[4096];
    int bDuracion;
    char bDescripcion[4096];
    int bPuntaje;
    char bLinkImagen[4096];
    if(!getValidString("Titulo: ","Error\n","Hasta 50 caracteres\n",bTitulo,50,2)&&
       !getValidString("Genero: ","Error\n","Hasta 50 caracteres\n",bGenero,50,2)&&
       !getValidInt("Duracion: ","Ingresar duracion en minutos (10 - 300)\n",&bDuracion,10,300,2)&&
       !getValidString("Descripcion: ","Error\n","Hasta 100 caracteres\n",bDescripcion,100,2)&&
       !getValidInt("Puntaje: ","Error\n",&bPuntaje,1,100,2)&&
       !getValidString("Link Imagen: ","Error\n","Hasta 500 caracteres\n",bLinkImagen,500,2)){
        aux=movie_newP(bTitulo,bGenero,bDuracion,bDescripcion,bPuntaje,bLinkImagen);
        if(!al_add(arrayMovie,aux))
            retorno=0;
        }
    return retorno;
}

int movie_modificar(ArrayList* arrayMovie,int index)
{
    if(index>=al_len(arrayMovie))
        return -1;
    Movie* aux;
    int retorno=-1;
    char bTitulo[4096];
    char bGenero[4096];
    int bDuracion;
    char bDescripcion[4096];
    int bPuntaje;
    char bLinkImagen[4096];
    if(!getValidString("Titulo: ","Error\n","Hasta 50 caracteres\n",bTitulo,50,2)&&
       !getValidString("Genero: ","Error\n","Hasta 50 caracteres\n",bGenero,50,2)&&
       !getValidInt("Duracion: ","Ingresar duracion en minutos (10 - 300)\n",&bDuracion,10,300,2)&&
       !getValidString("Descripcion: ","Error\n","Hasta 100 caracteres\n",bDescripcion,100,2)&&
       !getValidInt("Puntaje: ","Error\n",&bPuntaje,1,100,2)&&
       !getValidString("Link Imagen: ","Error\n","Hasta 500 caracteres\n",bLinkImagen,500,2)){
        aux=movie_newP(bTitulo,bGenero,bDuracion,bDescripcion,bPuntaje,bLinkImagen);
        if(!al_set(arrayMovie,index,aux)){
            retorno=0;
        }
    }
    return retorno;
}

int movie_mostrar(ArrayList* arrayMovie)
{
    int retorno=-1;
    int i;
    Movie* aux;
    int size=al_len(arrayMovie);
    char bTitulo[4096];
    char bGenero[4096];
    int bDuracion;
    char bDescripcion[4096];
    int bPuntaje;
    char bLinkImagen[4096];
    if(arrayMovie!=NULL){
        retorno=0;
        for(i=0;i<size;i++){
            aux=al_get(arrayMovie,i);
            if(aux!=NULL&&
               !movie_getTitulo(aux,bTitulo)&&!movie_getGenero(aux,bGenero)&&
               !movie_getDuracion(aux,&bDuracion)&&!movie_getDescripcion(aux,bDescripcion)&&
               !movie_getPuntaje(aux,&bPuntaje)&&!movie_getLinkImagen(aux,bLinkImagen)){
                printf("\nID: %d - Titulo: %s - Genero: %s - Duracion: %d - Descripcion: %s - Puntaje: %d - Link Imagen: %s\n"
                       ,i,bTitulo,bGenero,bDuracion,bDescripcion,bPuntaje,bLinkImagen);
            }
        }
    }
    return retorno;
}


void generarPagina(ArrayList* arrayMovie, char* nombre)
{
    int i;
    Movie* aux;
    char bTitulo[4096];
    char bGenero[4096];
    int bDuracion;
    char bDescripcion[4096];
    int bPuntaje;
    char bLinkImagen[4096];
    FILE* path=fopen(nombre,"w");
                fprintf(path,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
    for(i=0;i<al_len(arrayMovie);i++){
        aux=al_get(arrayMovie,i);
        if(aux!=NULL&&
            !movie_getTitulo(aux,bTitulo)&&!movie_getGenero(aux,bGenero)&&
            !movie_getDuracion(aux,&bDuracion)&&!movie_getDescripcion(aux,bDescripcion)&&
            !movie_getPuntaje(aux,&bPuntaje)&&!movie_getLinkImagen(aux,bLinkImagen)){
            fprintf(path,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li>					</ul><p>%s</p></article>",bLinkImagen,bTitulo,bGenero,bPuntaje,bDuracion,bDescripcion);
        }
    }
    fprintf(path,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    fclose(path);
}

int movie_compararPuntaje(void* peli1, void* peli2)
{
    int puntaje1;
    int puntaje2;
    movie_getPuntaje(peli1,&puntaje1);
    movie_getPuntaje(peli2,&puntaje2);
    if(puntaje1>puntaje2)
        return 1;
    if(puntaje1<puntaje2)
        return -1;
    else
        return 0;
}

int isValidTitulo(char* titulo)
{
    return 1;
}

int isValidDuracion(int duracion)
{
    return 1;
}

int isValidPuntaje(int puntaje)
{
    return 1;
}


