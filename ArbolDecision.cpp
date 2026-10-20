//
// Created by patri on 19-10-2026.
//

#include "ArbolDecision.h"

ArbolDecision::ArbolDecision(NodoArbolDecision<int>* raiz) : raiz(raiz) {}
ArbolDecision::~ArbolDecision() {}

void ArbolDecision::crearArbol(NodoArbolDecision<int>* raiz) {
    // Nodos Hoja
    NodoArbolDecision* urgencia = new NodoArbolDecision("---A URGENCIAS---");
    NodoArbolDecision* pediatria = new NodoArbolDecision("---A PEDIATRÍA---");
    NodoArbolDecision* cardiologia = new NodoArbolDecision("---A CARDIOLOGÍA---");
    NodoArbolDecision* cirugía = new NodoArbolDecision("---A CIRUGÍA---");
    NodoArbolDecision* traumatologia = new NodoArbolDecision("---A TRAUMATOLOGÍA---");
    NodoArbolDecision* neurologIa = new NodoArbolDecision("---A NEUROLOGÍA---");
    NodoArbolDecision* hospitalizar = new NodoArbolDecision("---A HOSPITALIZACIÓN---");
    NodoArbolDecision* general = new NodoArbolDecision("---A MEDICINA GENERAL---");


    // Nodos de decisiones
    NodoArbolDecision* dolor = new NodoArbolDecision(DOLOR, MAYOR_IGUAL, 8,);
    NodoArbolDecision* temperatura = new NodoArbolDecision(TEMPERATURA, MAYOR_IGUAL, 40);
    NodoArbolDecision* edad = new NodoArbolDecision(EDAD, MAYOR, 14);
    NodoArbolDecision* presion = new NodoArbolDecision(PRESION, MAYOR, 140);
    NodoArbolDecision* pecho = new NodoArbolDecision(TIPODOLOR, IGUAL, 1); // TENGO QUE VER QUE NUMERO EQUIVALE A "pecho"
    NodoArbolDecision* trauma = new NodoArbolDecision(TRAUMA, IGUAL, 1);
    NodoArbolDecision* cirugia = new NodoArbolDecision(CIRUGIA, IGUAL, 1);
    NodoArbolDecision* neuro = new NodoArbolDecision(SINTOMAS, IGUAL, 1);
    NodoArbolDecision* hospitalizar = new NodoArbolDecision(HOSPITALIZACION, MAYOR_IGUAL  , 2);

    this->raiz = dolor;
}