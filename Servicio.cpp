//
// Created by patri on 19-09-2026.
//

#include "Servicio.h"
using namespace std;

Servicio::Servicio(string servicio, AVL* avl) : servicio(servicio), pacientes(avl) {}
Servicio::~ Servicio() {}

string Servicio ::getServicio() {
    return servicio;
}

AVL* Servicio::getPacientes() {
    return pacientes;
}

int Servicio::getNumPacientes() { /// CAMBIAR METODO
    Nodo<Paciente>* paciente = pacientes->getCabeza();
    int contador = 0;
    while (paciente != nullptr) {
        paciente = paciente->getSiguiente();
        contador++;
    }
    return contador;
}

void Servicio::mostrarPacientes() { /// CAMBIAR METODO
    Nodo<Paciente>* aux = pacientes->getCabeza();
    while (aux != nullptr) {
        Paciente paciente = aux->getDato();
        cout << paciente.getNombre() << "  (" << paciente.getEdad() << ") "<< endl;
        aux = aux->getSiguiente();
    }
}
