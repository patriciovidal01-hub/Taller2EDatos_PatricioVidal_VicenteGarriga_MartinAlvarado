//
// Created by patri on 19-09-2026.
//

#include "Lista_Servicios.h"

Lista_Servicios::Lista_Servicios() : Lista<Servicio>(nullptr) {}
Lista_Servicios::~Lista_Servicios(){}
Nodo<Servicio>* Lista_Servicios::encontrarServicio(std::string servicio) {
    Nodo<Servicio>* nodo = cabeza;
    while (nodo != nullptr) {
        if (nodo->getDato().getServicio() == servicio) {
            return nodo;
        } else {
            nodo = nodo->getSiguiente();
        }
    }
    return nullptr;
}

Nodo<Servicio>* Lista_Servicios::servicioNumero(int numeroServicio) {
    int contador = 1;
    if (cabeza != nullptr) {
        Nodo<Servicio>* nodo = cabeza;
        while (nodo != nullptr && numeroServicio != contador) {
            nodo = nodo->getSiguiente();
            contador++;
        }
        return nodo;
    } else {
        return nullptr;
    }
}




int Lista_Servicios::cantidadServicios() {
    int contador = 0;
    Nodo<Servicio>* nodo = cabeza;
    while (nodo != nullptr) {
        nodo = nodo->getSiguiente();
        contador++;
    }
    return contador;
}

