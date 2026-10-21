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
    //campos para usar el nodo en el AVL
    Nodo<T>* izq;
    Nodo<T>* der;
    int altura; //una hoja tiene altura 1

public:
    Nodo(T dato): dato(dato), siguiente(nullptr), izq(nullptr), der(nullptr), altura(1) {}
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
    Nodo* getIzq() const {
        return izq;
    }
    Nodo* getDer() const {
        return der;
    }
    int getAltura() const {
        return altura;
    }
    void setIzq(Nodo* nodo) {
        izq = nodo;
    }
    void setDer(Nodo* nodo) {
        der = nodo;
    }
    void setAltura(int nuevaAltura) {
        altura = nuevaAltura;
    }
};

#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODO_H
