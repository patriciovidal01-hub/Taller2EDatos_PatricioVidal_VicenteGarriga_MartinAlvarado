//
// Created by patri on 06-09-2026.
//

#include "Queue.h"
#include "Paciente.h"
using namespace std;

Queue::Queue():cabeza(nullptr) {}
Queue::~Queue() {
    while (cabeza != nullptr) {
        eliminarCabeza();
    }
}

void Queue::eliminarCabeza() {
    if (cabeza != nullptr) {
        Nodo<Paciente>* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
    }
}

void Queue::agregarNodo(Nodo<Paciente>* nodo) {
    if (cabeza == nullptr) {
        cabeza = nodo;
    } else {
        Nodo<Paciente>* aux = cabeza;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nodo);
    }
}

void Queue::mostrarPacientes() const {
    int contador = 1;
    Nodo<Paciente>* aux = cabeza;
    while (aux != nullptr) {
        Paciente paciente = aux->getDato();
        cout << contador << ". " << paciente.getId() << " - " << paciente.getNombre() << endl;
        contador += 1;
        aux = aux->getSiguiente();
    }
}

Nodo<Paciente>* Queue:: getCabeza() const {
    return cabeza;
}

int Queue:: cantidadPacientes() const {
    Nodo<Paciente>* paciente = cabeza;
    int contador = 0;
    while (paciente != nullptr) {
        paciente = paciente->getSiguiente();
        contador++;
    }
    return contador;
}


