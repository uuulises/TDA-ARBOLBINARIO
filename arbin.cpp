#include "arbin.h"
#include <iostream>
#include <cassert> // no lo use

template<typename T>
Arbin<T>::Arbin()
{
    raiz = NULL;
}

template<typename T>
Arbin<T>::~Arbin()
{
    vaciar(raiz);
}

void Arbin<T>::vaciar(nodo *raiz)
{
    if (raiz != NULL) {
        vaciar(raiz->izq);
        vaciar(raiz->der);
        delete raiz;
        raiz = NULL;
    }
}

template<typename T> // no se como hacer que el arbol inserte de forma ordenda si los elementos no son numeros
void Arbin<T>::insertar(const T & elemento)
{
    nodo * aux = new nodo;
    aux->elemento = elemento;
    aux->izq = NULL;
    aux->der = NULL;
    insertarordenado(raiz, aux);
}

void Arbin<T>::insertarordenado(nodo *raiz, nodo *aux)
{
    if (raiz == NULL)
        raiz = aux;
    else {
        if (aux->elemento < raiz->elemento)
            insertarordenado(raiz->izq, aux);
        else
            insertarordenado(raiz->der, aux);
    }
}

template<typename T>
bool Arbin<T>::pertence(const T & elemento) const
{
    nodo * aux = raiz; 
    buscarcoincidenciaenarbol(aux, elemento);        
}

bool Arbin<T>::buscarcoincidenciaenarbol(nodo *raiz, const T & elemento) const
{
    if (raiz != NULL)
        return false;
    else {
        if (raiz->elemento == elemento)
            return true;
        else {
            if (elemento < raiz->elemento)
                return buscarcoincidenciaenarbol(raiz->izq, elemento);
            else
                return buscarcoincidenciaenarbol(raiz->der, elemento);
        }
    }
}


template<typename T>
int Arbin<T>::cantidadnodosarbol() const
{
    return cantidadnodos(raiz);
}

int cantidadnodos(nodo *raiz) const{
    if raiz == NULL
        return 0;
    else {
        // Recursivamente contar los nodos en el subárbol izquierdo y derecho
        
        int nodosIzq = cantidadnodos(raiz->izq);
        int nodosDer = cantidadnodos(raiz->der);
        
        // Sumar el nodo actual y los nodos de los subárboles
        return 1 + nodosIzq + nodosDer;
    }
}

template<typename T>
bool Arbin<T>::esvacio() const
{
    return raiz == NULL;
}

template<typename T>
int Arbin<T>::profundidad() const
{   
    return profundidadarbol(raiz);
}

int Arbin<T>::profundidadarbol(nodo *raiz) const{
    if (raiz == NULL)
        return 0;
    else {
        // Calcular la profundidad de cada subárbol
        int profundidadIzq = profundidadarbol(raiz->izq);
        int profundidadDer = profundidadarbol(raiz->der);
        
        // Sumar la profundidad del subárbol más profundo
        if (profundidadIzq > profundidadDer)
            return 1 + profundidadIzq;
        else
            return 1 + profundidadDer;
    }
}

////ULI ACA DEFINITE LOS TIPOS DE DATPS QUE ACEPTA T ASI NO SALE EL ERROR

