//
// Created by patri on 19-10-2026.
//

#include "ArbolDecision.h"
#include <iostream>

ArbolDecision::ArbolDecision(NodoArbolDecision* raiz) : raiz(raiz) {}
ArbolDecision::~ArbolDecision() {}

void ArbolDecision::crearArbol() {
    // Nodos Hoja
    NodoArbolDecision* urgencia = new NodoArbolDecision("Urgencias");
    NodoArbolDecision* pediatria = new NodoArbolDecision("Pediatria");
    NodoArbolDecision* cardiologia = new NodoArbolDecision("Cardiologia");
    NodoArbolDecision* cirugia = new NodoArbolDecision("Cirugia");
    NodoArbolDecision* traumatologia = new NodoArbolDecision("Traumatologia");
    NodoArbolDecision* neurologia = new NodoArbolDecision("Neurologia");
    NodoArbolDecision* hospitalizacion = new NodoArbolDecision("Hospitalizacion");
    NodoArbolDecision* general = new NodoArbolDecision("Medicina General");

    // Nodos de decisiones
    NodoArbolDecision* hospitalizar = new NodoArbolDecision(HOSPITALIZACION, MAYOR_IGUAL,2, hospitalizacion, general);
    NodoArbolDecision* neuro = new NodoArbolDecision(SINTOMAS, IGUAL, 1, neurologia, hospitalizar);
    NodoArbolDecision* cirug = new NodoArbolDecision(CIRUGIA, IGUAL, 1, cirugia, traumatologia);
    NodoArbolDecision* trauma = new NodoArbolDecision(TRAUMA, IGUAL, 1, cirug, neuro);
    NodoArbolDecision* presion = new NodoArbolDecision(PRESION, MAYOR, 140, cardiologia, trauma);
    NodoArbolDecision* edad = new NodoArbolDecision(EDAD, MENOR_IGUAL, 14, pediatria, presion);
    NodoArbolDecision* dolor = new NodoArbolDecision(DOLOR, MAYOR_IGUAL, 8, urgencia, edad);

    this->raiz = dolor;
}


NodoArbolDecision* ArbolDecision::evaluar(Paciente paciente) {
    std::cout << "Ruta:" << std::endl;

    NodoArbolDecision* nuevoNodo = this->raiz;
    double datoPaciente = 0;
    std::string ruta = "";
    while (!esServicio(nuevoNodo)) {
        switch (nuevoNodo->getAtributo()) {
            case EDAD:
                datoPaciente = paciente.getEdad();
                ruta = "Edad";
                break;
            case TEMPERATURA:
                datoPaciente = paciente.getTemperatura();
                ruta = "Temperatura";
                break;
            case PRESION:
                datoPaciente = paciente.getPresionArterial();
                ruta = "Presion";
                break;
            case DOLOR:
                datoPaciente = paciente.getDolor();
                ruta = "Dolor";
                break;
            case TIPODOLOR:
                // Hacer otro switch para una cadena saber que tipo de dolor corresponde a cada numero.
                break;
            case TRAUMA:
                datoPaciente = paciente.getTrauma();
                ruta = "Trauma";
                break;
            case SINTOMAS:
                datoPaciente = paciente.getSintomasNeurologicos();
                ruta = "Sintomas";
                break;
            case CIRUGIA:
                datoPaciente = paciente.getRequiereCirugia();
                ruta = "Cirugia";
                break;
            case HOSPITALIZACION:
                datoPaciente = paciente.getDiasHospitalizacion();
                ruta = "Hospitalizacion";
                break;
        }
        std::cout << ruta << nuevoNodo->getStrop() << nuevoNodo->getComparar();
        nuevoNodo = nuevoNodo->preguntar(datoPaciente);
        std::cout << " -> ";
    }
    return nuevoNodo;
};

bool ArbolDecision::esServicio(NodoArbolDecision *nodo) {
  if (nodo->izqNodo() == nullptr && nodo->derNodo() == nullptr) {
      return true;
  }
     return false;
};
