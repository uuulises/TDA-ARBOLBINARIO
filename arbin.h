#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
//#include "LISTA.h"


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
    void insertarordenado(nodo *raiz, nodo *aux);
    int profundidadarbol(nodo *raiz) const;
    int cantidadnodos(nodo *raiz) const;
    void vaciar(nodo *raiz);
    bool buscarcoincidenciaenarbol(nodo *raiz, const T & elemento) const;


public:

    Arbin();
    ~Arbin();

    void insertar(const T & elemento);
    bool pertence(const T & elemento) const;
    int cantidadnodosarbol() const;
    bool esvacio() const;
    int profundidad() const;
    const T & listarelementosultimahoja() const; //se refiere a devolver una lista con los elementos de la ultima hoja
    const T & listarelementosordenados() const;


};

#endif // ARBOLBINARIO_H


//// Esto es lo que hizo vico para el tema de las listas

/*#ifndef ARBIN_H
#define ARBIN_H
#include "LISTA.h"


template <typename T>
class ARBIN
{
    public:
        ARBIN();
        virtual ~ARBIN();
        void agregar(const T & elemento);
        bool pertenece(const T &elemento);
        int cantidadnodos() const;
        bool vacio() const;
        int profundidad() const;
        void frontera(LISTA<T> & lista);
        LISTA<T> inorder();

    protected:

    private:
        struct Nodo{
            T elemento;
            ARBIN * mayor;
            ARBIN * menor;
        };
        void fronteraPriv(LISTA<T>&lista);

        void inOrderPriv(LISTA<T>lista);

        Nodo * raiz;

        void vaciar();
};*/
