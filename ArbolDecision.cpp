//
// Created by patri on 19-10-2026.
//

#include "ArbolDecision.h"

ArbolDecision::ArbolDecision(NodoArbolDecision* raiz) : raiz(raiz) {}
ArbolDecision::~ArbolDecision() {}

void ArbolDecision::crearArbol(NodoArbolDecision* raiz) {
    // Nodos Hoja
    NodoArbolDecision* urgencia = new NodoArbolDecision("---A URGENCIAS---");
    NodoArbolDecision* pediatria = new NodoArbolDecision("---A PEDIATRÍA---");
    NodoArbolDecision* cardiologia = new NodoArbolDecision("---A CARDIOLOGÍA---");
    NodoArbolDecision* cirugia = new NodoArbolDecision("---A CIRUGÍA---");
    NodoArbolDecision* traumatologia = new NodoArbolDecision("---A TRAUMATOLOGÍA---");
    NodoArbolDecision* neurologia = new NodoArbolDecision("---A NEUROLOGÍA---");
    NodoArbolDecision* hospitalizacion = new NodoArbolDecision("---A HOSPITALIZACIÓN---");
    NodoArbolDecision* general = new NodoArbolDecision("---A MEDICINA GENERAL---");


    // Nodos de decisiones
    NodoArbolDecision* hospitalizar = new NodoArbolDecision(HOSPITALIZACION, MAYOR_IGUAL,2, hospitalizacion, general);
    NodoArbolDecision* neuro = new NodoArbolDecision(SINTOMAS, IGUAL, 1, neurologia, hospitalizar);
    NodoArbolDecision* cirug = new NodoArbolDecision(CIRUGIA, IGUAL, 1, cirugia, traumatologia);
    NodoArbolDecision* trauma = new NodoArbolDecision(TRAUMA, IGUAL, 1, cirug, neuro);
    NodoArbolDecision* pecho = new NodoArbolDecision(TIPODOLOR, IGUAL, 1, cardiologia, trauma); // TENGO QUE VER QUE NUMERO EQUIVALE A "pecho"
    NodoArbolDecision* presion = new NodoArbolDecision(PRESION, MAYOR, 140, pecho, trauma);
    NodoArbolDecision* edad = new NodoArbolDecision(EDAD, MENOR_IGUAL, 14, pediatria, presion);
    NodoArbolDecision* temperatura = new NodoArbolDecision(TEMPERATURA, MAYOR_IGUAL, 40, urgencia, edad);
    NodoArbolDecision* dolor = new NodoArbolDecision(DOLOR, MAYOR_IGUAL, 8, temperatura, edad);

    this->raiz = dolor;
}