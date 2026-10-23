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
   return pacientes->cantidad();
}

void Servicio::mostrarPacientes() { /// CAMBIAR METODO
   pacientes->mostrarInorden();
}
