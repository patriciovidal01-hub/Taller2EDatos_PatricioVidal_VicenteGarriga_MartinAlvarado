//
// Created by patri on 06-09-2026.
//

#include "Paciente.h"
#include <iostream>
#include <string>
using std::string;

Paciente:: Paciente(string id, string nombre, int edad, double temperatura, int presionArterial, int dolor, string tipoDolor
,int trauma, int sistemasNeurologicos, int RequiereCirugia, int diasHospitalizacion):

id(id), nombre(nombre), edad(edad), temperatura(temperatura),
presionArterial(presionArterial), dolor(dolor), tipoDolor(tipoDolor), trauma(trauma),
sintomasNeurologicos(sintomasNeurologicos), requiereCirugia(requiereCirugia),
diasHospitalizacion(diasHospitalizacion), servicio("") {}

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

double Paciente::getTemperatura() const {
    return temperatura;
}
 
int Paciente::getPresionArterial() const {
    return presionArterial;
}
 
int Paciente::getDolor() const {
    return dolor;
}
 
string Paciente::getTipoDolor() const {
    return tipoDolor;
}
 
int Paciente::getTrauma() const {
    return trauma;
}
 
int Paciente::getSintomasNeurologicos() const {
    return sintomasNeurologicos;
}
 
int Paciente::getRequiereCirugia() const {
    return requiereCirugia;
}
 
int Paciente::getDiasHospitalizacion() const {
    return diasHospitalizacion;
}

string Paciente::getServicio() const {
    return servicio;
}
 
// setter para asignar el servicio desde el arbol de decision
void Paciente::setServicio(string nuevoServicio) {
    servicio = nuevoServicio;
}
