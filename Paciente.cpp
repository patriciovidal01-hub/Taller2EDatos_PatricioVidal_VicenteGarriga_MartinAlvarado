//
// Created by patri on 06-09-2026.
//

#include "Paciente.h"
#include <iostream>
#include <string>
using std::string;

Paciente:: Paciente(string id, string nombre, int edad, string servicio):
id(id), nombre(nombre), edad(edad), servicio(servicio) {}

Paciente::~Paciente() {}

string Paciente::getId() const {
    return id;
}

string Paciente::getNombre() const{
    return nombre;
}

int Paciente::getEdad() const{
    return edad;
}
string Paciente::getServicio() const {
    return servicio;
}