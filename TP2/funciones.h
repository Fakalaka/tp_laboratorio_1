#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Obtiene el primer espacio sin activar del array.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int indice de lugar disponible.
 *
 */
int obtenerEspacioLibre(EPersona lista[],int limite);

/** \brief Busca una persona activa mediante su dni.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \param dni int dni de la persona a buscar.
 * \return int -1 si no se encuentra la persona.
 *
 */
int buscarPorDni(EPersona* lista,int limite,int dni);

/** \brief Imprime la lista de personas activas.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int -1 lista vacia.
 *
 */
int mostrar(EPersona* lista,int limite);

/** \brief Genera un grafico categorizado por edad.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int -1 si no hay edades validas.
 *
 */
int persona_grafico(EPersona* lista,int limite);

/** \brief Agrega una persona
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \param nombre char* nombre de la persona.
 * \param edad int edad de la persona.
 * \param dni int dni de la persona.
 * \return int
 *
 */
int persona_altaForzada(EPersona* lista,int limite,char* nombre,int edad,int dni);

/** \brief Inicializa los estados de todas las personas.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int
 *
 */
int persona_init(EPersona* lista,int limite);

/** \brief El usuario agrega una persona.
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int -1 si hubo algun error en los datos.
 *
 */
int persona_alta(EPersona* lista,int limite);

/** \brief Cambia el estado de una persona a 1
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int -2 no se encontro el DNI en la lista.
 *
 */
int persona_baja(EPersona* lista,int limite);

/** \brief Ordena la lista alfabeticamente
 *
 * \param lista EPersona* el array de personas.
 * \param limite int el limite del array.
 * \return int -1 lista vacia.
 *
 */
int persona_ordenar(EPersona* lista,int limite);

#endif // FUNCIONES_H_INCLUDED
