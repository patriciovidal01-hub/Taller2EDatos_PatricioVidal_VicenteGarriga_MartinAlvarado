#include "NodoArbolDecision.h"

#include "Nodo.h"
#include <string>
//
// Created by patri on 20-10-2026.
//
NodoArbolDecision::NodoArbolDecision(Atributo atributo, Operador operador, int comparar, NodoArbolDecision* izq, NodoArbolDecision* der): atributo(atributo), operador(operador),
    comparar(comparar), servicio(-1), izq(izq), der(der), resultado("") {}
NodoArbolDecision::NodoArbolDecision(std::string resultado): atributo(EDAD), operador(MENOR),
    comparar(0), servicio(-1), izq(nullptr), der(nullptr), resultado(resultado){}
NodoArbolDecision::~NodoArbolDecision(){}