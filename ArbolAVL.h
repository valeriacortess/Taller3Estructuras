#ifndef __ARBOLAVL__
#define __ARBOLAVL__


#include "NodoAVL.h"
#include <list>

template <class T>
class ArbolAVL{
protected:


    NodoAVL<T>* raiz;
    NodoAVL<T>* balancear(NodoAVL<T>* nodo);
    NodoAVL<T>* insertarRecursivo(NodoAVL<T>* nodo, T val, bool& insertado);
    NodoAVL<T>* eliminarRecursivo(NodoAVL<T>* nodo, T val, bool& eliminado);
    void inOrdenEnLista(NodoAVL<T>* nodo, std::list<T>& lista);

public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool insert(T val);
    bool erase(T val);
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void inOrdenEnLista(std::list<T>& lista);

};

#include "ArbolAVL.hxx"

#endif