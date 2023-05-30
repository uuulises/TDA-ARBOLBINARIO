#ifndef ARBIN_H
#define ARBIN_H
#include "Lista.h"


template <typename T>
class Arbin {

private:
    struct nodo
    {
        T elemento;
        nodo *izq;
        nodo *der;
    };
    nodo *raiz;
    // estas son las fucniones que use para los distintos procesos recursivos de las funciones de la clase(not4 public)
    void insertarordenado(nodo*& raiz, nodo *aux);
    int profundidadarbol(nodo *raiz) const;
    int cantidadnodos(nodo *raiz) const;
    void vaciar(nodo *raiz);
    bool buscarcoincidenciaenarbol(nodo *raiz, const T & elemento) const;
    Lista<T> inorder(Lista<T> & G, nodo*raiz);
    Lista<T> listarhojas(Lista<T> & F, nodo*raiz);

public:

    Arbin();
    ~Arbin();

    void insertar(const T & elemento);
    bool pertence(const T & elemento) const;
    int cantidadnodosarbol() const;
    bool esvacio() const;
    int profundidad() const;
    Lista<T> listarordenado();
    Lista<T> frontera();



};

#endif

