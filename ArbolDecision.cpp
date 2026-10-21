//
// Created by patri on 19-10-2026.
//

#include "ArbolDecision.h"

ArbolDecision::ArbolDecision(NodoArbolDecision* raiz) : raiz(raiz) {}
ArbolDecision::~ArbolDecision() {}

void ArbolDecision::crearArbol(NodoArbolDecision* raiz) {
    // Nodos Hoja
    NodoArbolDecision* urgencia = new NodoArbolDecision("Urgencia");
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