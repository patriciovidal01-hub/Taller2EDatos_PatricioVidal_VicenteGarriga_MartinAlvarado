//
// Created by patri on 19-09-2026.
//

#include "Servicio.h"
using namespace std;

Servicio::Servicio(string servicio, Lista_Pacientes* lista) : servicio(servicio), pacientes(lista) {}
Servicio::~ Servicio() {}

string Servicio ::getServicio() {
    return servicio;
}

Lista_Pacientes* Servicio::getPacientes() {
    return pacientes;
}

int Servicio::getNumPacientes() {
    Nodo<Paciente>* paciente = pacientes->getCabeza();
    int contador = 0;
    while (paciente != nullptr) {
        paciente = paciente->getSiguiente();
        contador++;
    }
    return contador;
}

void Servicio::mostrarPacientes() {
    Nodo<Paciente>* aux = pacientes->getCabeza();
    while (aux != nullptr) {
        Paciente paciente = aux->getDato();
        cout << paciente.getNombre() << "  (" << paciente.getEdad() << ") "<< endl;
        aux = aux->getSiguiente();
    }
}
