//
// Created by patri on 06-09-2026.
//
#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_QUEUE_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_QUEUE_H
#include "Nodo.h"
#include "Paciente.h"

class Queue {
private:
    Nodo<Paciente>* cabeza;
public:
    Queue();
    ~Queue();
    void eliminarCabeza();
    void agregarNodo(Nodo<Paciente>* nodo);
    void mostrarPacientes() const;
    Nodo<Paciente>* getCabeza() const;
    int cantidadPacientes() const;
};


#endif //TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_QUEUE_H
