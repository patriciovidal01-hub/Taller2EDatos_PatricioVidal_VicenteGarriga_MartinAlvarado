//
// Created by patri on 12-09-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODO_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODO_H
#include <iostream>

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
public:
    Nodo(T dato): dato(dato), siguiente(nullptr) {}
    ~Nodo(){}
    void setSiguiente(Nodo* nodo) {
        siguiente = nodo;
    }
    Nodo* getSiguiente() const {
        return siguiente;
    }
    T getDato() const {
        return dato;
    }
};

#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODO_H
