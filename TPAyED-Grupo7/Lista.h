#ifndef __LISTA_H__
#define __LISTA_H__

#ifndef NULL
#define NULL      0
#endif

/*
=================================================================================
LIBRERIA(BIBLIOTECA) DE FUNCIONES PARA LISTAS
Es un archivo que el compilador puede leer, en él encuentra las
distintas funciones para el manejo de las listas.
 =================================================================================
*/


/*
=================================================================================
Castear en el main a que tipo de dato estamos apuntando.
=================================================================================
*/


typedef void* Dato;//puntero al tipo de Dato dinámico

//Estructura del Nodo de la lista
struct Nodo {
    Dato dato; //contiene el dato almacenado en el Nodo de la lista
    Nodo* ptrSgte; // El ptrSgte apunta al siguiente nodo o a null en caso que no exista otro nodo.
};

/*
Tipo de dato Nodo = Puntero al nodo inicial.
Este puntero tiene la dirección del primer nodo de la lista, es fundamental porque al tener
la dirección del primer nodo de la lista nos permite acceder a los demás nodos.
Por lo tanto, se utilizará para recorrer y acceder a sus datos.
*/
typedef Nodo* PtrNodo;

//Estructura de la lista
struct Lista{
    PtrNodo primerNodo;// puntero al primer nodo de la lista
};

/*
=================================================================================
PRE: La Lista no debe haber sido creada ni destruida.
POST: La Lista ya puede ser utilizada.
=================================================================================
*/
void crearLista(Lista &lista);

/*
=================================================================================
PRE: La Lista se creo con la primitiva crearLista(Lista &lista).
POST: Devuelve el puntero al proximo nodo, o devuelve NULL si la lista esta
vacia o si ese puntero apuntaba a NULL.
=================================================================================
*/
PtrNodo ptrSgte(Lista &lista, PtrNodo ptrNodo);


/*
=================================================================================
PRE: La Lista se creo con la primitiva crearLista(Lista &lista).
POST: Devuelve el puntero al primer elemento de la lista o NULL si está vacía.
=================================================================================
*/
PtrNodo primerNodo(Lista &lista);

/*
=================================================================================
PRE: La Lista se creo con la primitiva crearLista(Lista &lista).
POST: Agrega un nodo nuevo al final de la lista y devuelve un puntero
a ese elemento.
=================================================================================
*/
PtrNodo agregarNodo(Lista &lista, Dato dato);

/*
=================================================================================
PRE: La Lista se creo con la primitiva crearLista(Lista &lista).
POST: Se elimina el nodo apuntado con el puntero.
=================================================================================
*/
void eliminarNodo(Lista &lista, PtrNodo ptrNodo);

/*
=================================================================================
PRE: La Lista se creo con la primitiva crearLista(Lista &lista).
POST: La lista es eliminada.
=================================================================================
*/
void eliminarLista(Lista &lista);


#endif

