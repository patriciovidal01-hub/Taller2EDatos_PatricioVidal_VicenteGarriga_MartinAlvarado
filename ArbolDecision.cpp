//
// Created by patri on 19-10-2026.
//

#include "ArbolDecision.h"
#include <iostream>

ArbolDecision::ArbolDecision() : raiz(nullptr) {}
ArbolDecision::~ArbolDecision() {
    liberar(this->raiz);
}

void ArbolDecision::liberar(NodoArbolDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }
    liberar(nodo->getIzq());
    liberar(nodo->getDer());
    delete nodo;
}

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


NodoArbolDecision* ArbolDecision::evaluar(Paciente const &  paciente) const{
    std::cout << "Ruta:" << std::endl;

    NodoArbolDecision* nuevoNodo = this->raiz;
    double datoPaciente = 0;
    std::string ruta;
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
        std::cout << ruta << " " << nuevoNodo->getStrop() << " " << nuevoNodo->getComparar();
        nuevoNodo = nuevoNodo->preguntar(datoPaciente);
        if (!esServicio(nuevoNodo)) {
            std::cout << " -> " ;
        } else {
            std::cout << " Positivo! ";
            std::cout << std::endl;
        }
    }
    return nuevoNodo;
};

bool ArbolDecision::esServicio(NodoArbolDecision *nodo) const {
  if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
      return true;
  }
     return false;
};

void ArbolDecision::inorden(NodoArbolDecision* nodo) const {
    if (nodo == nullptr) return;
    inorden(nodo->getIzq());
    if (esServicio(nodo)) {
        std::cout << nodo->getResultado() << std::endl;
    } else {
        std::cout << nodo->getResultado() << " (" << enumToString(nodo->getAtributo()) << ") ";
    }
    inorden(nodo->getDer());
}

void ArbolDecision::preorden(NodoArbolDecision* nodo) const {
    if (nodo == nullptr) return;
    if (esServicio(nodo)) {
        std::cout << nodo->getResultado() << std::endl;
    } else {
        std::cout << nodo->getResultado() << " (" << enumToString(nodo->getAtributo()) << ") ";
    }
    preorden(nodo->getIzq());
    preorden(nodo->getDer());
}

void ArbolDecision::postorden(NodoArbolDecision* nodo) const {
    if (nodo == nullptr) return;
    postorden(nodo->getIzq());
    postorden(nodo->getDer());
    if (esServicio(nodo)) {
        std::cout << nodo->getResultado() << std::endl;
    } else {
        std::cout << nodo->getResultado() << " (" << enumToString(nodo->getAtributo()) << ") ";
    }
}

void ArbolDecision::mostrarIN() const {
    if (this->raiz == nullptr) {
        std::cout << "El arbol de decisión esta vacío" << std::endl;
    }
    inorden(this->raiz);
    std::cout << std::endl;
}

void ArbolDecision::mostrarPR() const {
    if (this->raiz == nullptr) {
        std::cout << "El arbol de decisión esta vacío" << std::endl;
    }
    preorden(this->raiz);
    std::cout << std::endl;
}

void ArbolDecision::mostrarPS() const{
    if (this->raiz == nullptr) {
        std::cout << "El arbol de decisión esta vacío" << std::endl;
    }
    postorden(this->raiz);
    std::cout << std::endl;
}

std::string ArbolDecision::enumToString(int number) const{
    switch (number) {
        case 0:
            return "EDAD";
            break;
        case 1:
            return "TEMPERATURA";
            break;
        case 2:
            return "PRESION";
            break;
        case 3:
            return "DOLOR";
            break;
        case 4:
            return "TIPODOLOR";
            break;
        case 5:
            return "TRAUMA";
            break;
        case 6:
            return "SINTOMAS";
            break;
        case 7:
            return "CIRUGIA";
            break;
        case 8:
            return "HOSPITALIZACION";
            break;
        default:
            return "NINGUNO";
            break;
    }
}