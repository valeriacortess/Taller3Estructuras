#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <vector>
#include <algorithm>
#include <list>
#include <functional>

// Montículo usando std::vector de la STL y algoritmos de heap
template <class T>
class monticulo {
protected:
    std::vector<T> datos;

public:
    // Insertar un elemento
    bool insert(T val) {
        // Evitar duplicados 
        if (std::find(this->datos.begin(), this->datos.end(), val) != this->datos.end()) {
            return false;
        }
        this->datos.push_back(val);
        std::push_heap(this->datos.begin(), this->datos.end(), std::greater<T>());
        return true;
    }

    // Eliminar un elemento por valor
    bool erase(T val) {
        typename std::vector<T>::iterator it = std::find(this->datos.begin(), this->datos.end(), val);
        if (it == this->datos.end()) {
            return false;
        }
        // Mover el elemento a eliminar al final y rehacer el heap
        std::swap(*it, this->datos.back());
        this->datos.pop_back();
        if (!this->datos.empty()) {
            std::make_heap(this->datos.begin(), this->datos.end(), std::greater<T>());
        }
        return true;
    }

    // Generar la secuencia ordenada 
    void inOrdenEnLista(std::list<T>& lista) {
        std::vector<T> copia = this->datos;
        std::sort(copia.begin(), copia.end());
        lista.assign(copia.begin(), copia.end());
    }

};

#endif
