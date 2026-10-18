//
// Created by patri on 19-09-2026.
//

#include "Stack.h"

Stack::Stack() : atencionCabeza(nullptr){}
Stack::~Stack() {
    while (atencionCabeza != nullptr) {
        eliminarCabeza();
    }
}

void Stack::eliminarCabeza() {
    if (atencionCabeza != nullptr) {
        Nodo<Paciente>* aux = atencionCabeza;
        atencionCabeza = atencionCabeza->getSiguiente();
        delete aux;
    }
}


void Stack::push(Nodo<Paciente>* nodo) {
    nodo->setSiguiente(atencionCabeza);
    atencionCabeza = nodo;
}

void Stack::mostrarHistorial() const{
    Nodo<Paciente>* aux = atencionCabeza;
    while (aux != nullptr) {
        Paciente paciente = aux->getDato();
        std::cout << " Nombre: " <<paciente.getNombre() << " | " << "Edad: " <<paciente.getEdad()
        << " | "<< "Departamento: " << paciente.getServicio() << std::endl;
        aux = aux->getSiguiente();
    }
}