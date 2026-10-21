#include "NodoArbolDecision.h"
#include <string>;
//
// Created by patri on 20-10-2026.
//
NodoArbolDecision::NodoArbolDecision(Atributo atributo, Operador operador, int comparar, NodoArbolDecision* izq, NodoArbolDecision* der): atributo(atributo), operador(operador),
    comparar(comparar), servicio(-1), izq(izq), der(der), resultado("") {}
NodoArbolDecision::NodoArbolDecision(std::string resultado): atributo(EDAD), operador(MENOR),
    comparar(0), servicio(-1), izq(nullptr), der(nullptr), resultado(resultado){}

NodoArbolDecision* NodoArbolDecision::preguntar(int datoPaciente) {
    switch(this->operador) {
       case MENOR:
            if (datoPaciente < this->comparar) {
                return this->izq;
            }
            break;
        case MENOR_IGUAL:
            if (datoPaciente <= this->comparar) {
                return this->izq;
            }
            break;
        case IGUAL:
            if (datoPaciente == this->comparar) {
                return this->izq;
            }
            break;
        case MAYOR:
            if (datoPaciente > this->comparar) {
                return this->izq;
            }
            break;
        case MAYOR_IGUAL:
            if (datoPaciente >= this->comparar) {
                return this->izq;
            }
            break;
    }
    return this->der;
}
NodoArbolDecision::~NodoArbolDecision(){}