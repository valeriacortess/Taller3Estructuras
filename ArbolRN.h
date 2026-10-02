#ifndef __ARBOLRN_H__
#define __ARBOLRN_H__

#include <set>
#include <list>

// Árbol rojinegro: envuelve std::set de la STL (implementado como árbol rojinegro)
template <class T>
class arbolRN {
protected:
    std::set<T> arbol;

public:
    bool insert(T val) {
        return this->arbol.insert(val).second;     // true si no estaba
    }

    bool erase(T val) {
        return this->arbol.erase(val) > 0;         // true si existía
    }

    void inOrdenEnLista(std::list<T>& lista) {
        lista.assign(this->arbol.begin(), this->arbol.end());
    }
};

#endif