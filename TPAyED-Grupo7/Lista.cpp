#include "Lista.h"

//Inicializo la lista en null
//Para construir una lista vacía,asignamos a lista.primerNodo Null
//para indicar  que no se refiere a ningún nodo.
void crearLista(Lista &lista) {
  lista.primerNodo = NULL;
}

//primitiva para recorrer la lista y no usar el atributo cuando se recorre
PtrNodo ptrSgte(Lista &lista, PtrNodo ptrNodo) {
    //pasa al ptrSiguiente nodo si hay un nodo a continuacion o no llego al final de la lista.
    if ((lista.primerNodo != NULL) && (ptrNodo != NULL))
    return ptrNodo->ptrSgte;
  else
    return NULL;
}

//Puntero al primer nodo de la lista
PtrNodo primerNodo(Lista &lista) {
  return lista.primerNodo;
}

//primitiva para agregar datos al final de la lista
PtrNodo agregarNodo(Lista &lista, Dato dato) {
PtrNodo nuevo = new Nodo;//pido espacio en memoria para un nuevo nodo
    nuevo->dato = dato;
    nuevo->ptrSgte = NULL;//el nuevo nodo queda apuntando a null

//si no hay nodos en la lista
  if  (lista.primerNodo == NULL){
    lista.primerNodo=nuevo;//asigno el valor al primer nodo
  }else {
    //se busca el ultimo elemento de la lista
    PtrNodo cursor=lista.primerNodo;//cursor para recorrer la lista
    while(cursor->ptrSgte != NULL){
        cursor=cursor->ptrSgte;//nos aseguramos que el cursor quede en el ultimo elemento de la lista
    }
    cursor->ptrSgte=nuevo;//le asigno el nuevo nodo que apunta a null
}
  return nuevo;
}


void eliminarNodo(Lista &lista, PtrNodo ptrNodo){
    PtrNodo ptrNodoAntes;
    PtrNodo ptrAnterior = NULL;
    PtrNodo cursor = lista.primerNodo;

    //verifico que la lista no este vacia y haya mas de un nodo
       if ((lista.primerNodo != NULL) && (ptrNodo != NULL)){
      if (ptrNodo == lista.primerNodo){//si el dato a eliminar esta al inicio de la lista
            lista.primerNodo = ptrSgte(lista,lista.primerNodo);//el primer nodo queda apuntando al siguiente nodo.
        }else{
            //recorro la lista hasta encontrar el puntero al nodo anterior del apuntado
            while (( cursor != NULL) && (cursor != ptrNodo)){
                ptrAnterior = cursor;
                cursor = ptrSgte(lista,cursor);
            }
            //al ptrNodoAntes se le asigna el valor del puntero anterior
            ptrNodoAntes = ptrAnterior;
            ptrNodoAntes->ptrSgte = ptrNodo->ptrSgte;//le asigno al ptrNodoAntes el puntero al que apuntaba el ptrNodo para no perder el enlace
        }
    delete ptrNodo;//elimino el nodo seleccionado
    }
}


void eliminarLista(Lista &lista){
PtrNodo borrar = NULL;
//voy recorriendo la lista desde el primer nodo
    while(lista.primerNodo != NULL){
        //voy guardando en borrar el puntero al nodo a eliminar
        borrar = lista.primerNodo;
        lista.primerNodo = borrar->ptrSgte;//voy al siguiente nodo antes de eliminar
        delete borrar;//elimino el nodo apuntado
    }
}
