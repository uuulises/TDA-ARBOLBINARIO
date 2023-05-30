#include "arbin.h"
#include "Lista.h"
#include <iostream>


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

template<typename T>
void Arbin<T>::vaciar(nodo *raiz)
{
    if (raiz != NULL) {
        vaciar(raiz->izq);
        vaciar(raiz->der);
        delete raiz;
        raiz = NULL;
    }
}

template<typename T>
void Arbin<T>::insertarordenado(nodo *& raizR, nodo *aux)
{
    if (raizR == NULL)
        raizR = aux;
    else {
        if (aux->elemento < raizR->elemento)
            insertarordenado(raizR->izq, aux);
        else
            insertarordenado(raizR->der, aux);
    }
}

template<typename T> 
void Arbin<T>::insertar(const T & elemento)
{
    nodo * aux = new nodo;
    aux->elemento = elemento;
    aux->izq = NULL;
    aux->der = NULL;
    insertarordenado(raiz, aux);
}

template<typename T>
bool Arbin<T>::buscarcoincidenciaenarbol(nodo *raiz, const T & elemento) const
{
    if (raiz == NULL)
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
bool Arbin<T>::pertence(const T & elemento) const
{
    nodo * aux = raiz;
    return (buscarcoincidenciaenarbol(aux, elemento));
}

template<typename T>
int Arbin<T>::cantidadnodos(nodo *raiz) const{
    if (raiz == NULL)
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
int Arbin<T>::cantidadnodosarbol() const
{
    return cantidadnodos(raiz);
}


template<typename T>
bool Arbin<T>::esvacio() const
{
    return raiz == NULL;
}

template<typename T>
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


template<typename T>
int Arbin<T>::profundidad() const
{
    return profundidadarbol(raiz);
}



template<typename T>
Lista<T> Arbin<T>::inorder(Lista<T> & G, nodo*nodoarb)
{
    if(nodoarb!=NULL){
        inorder(G,nodoarb->izq);
        G.agregarUltimo(nodoarb->elemento);
        inorder(G,nodoarb->der);

    }
    return G;
}

template<typename T>
Lista<T> Arbin<T>::listarordenado()
{
    Lista<T> G;
    return inorder(G,raiz);
}

template<typename T>
Lista<T> Arbin<T>::listarhojas(Lista<T> & F, nodo*nodoarb)
{
    if(nodoarb!=NULL){
        if((nodoarb->izq==NULL)&&(nodoarb->der==NULL)){
            F.agregarUltimo(nodoarb->elemento);
        }
        listarhojas(F,nodoarb->izq);
        listarhojas(F,nodoarb->der);
    }
    return F;
}

template<typename T>
Lista<T> Arbin<T>::frontera()
{
    Lista<T> F;
    return listarhojas(F,raiz);
}

template class Arbin<int>;
template class Arbin<float>;
