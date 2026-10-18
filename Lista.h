//
// Created by patri on 18-09-2026.
//

#ifndef TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_H
#define TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_H
#include <iostream>
#include "Nodo.h"

template <typename T>
class Lista {
    protected:
        Nodo<T>* cabeza;
    public:
        Lista(Nodo<T>* cabeza) : cabeza(cabeza){}
        virtual ~Lista() {
            while (cabeza != nullptr) {
                eliminarPrimero();
            }
        }
    
        Nodo<T>* getCabeza() {
            return cabeza;
        }

        Nodo<T>* getUltimo() {
            if (cabeza != nullptr){
                Nodo<T>* ultimo = cabeza;
                while (ultimo->getSiguiente() != nullptr) {
                    ultimo = ultimo->getSiguiente();
                }
                return ultimo;
            }
            return cabeza;
        }

        void agregarNodo(Nodo<T>* nodo) {
            if (cabeza == nullptr) {
                cabeza = nodo;
            } else {
                Nodo<T>* agregado = cabeza;
                while (agregado->getSiguiente() != nullptr) {
                    agregado = agregado->getSiguiente();
                }
                agregado->setSiguiente(nodo);
            }
        }

        void eliminarPrimero() {
            if (cabeza != nullptr) {
                Nodo<T>* primero = cabeza;
                cabeza = primero->getSiguiente();
                delete primero;
            }
        }
};


#endif //TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_H
