//
// Created by patri on 19-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#include "NodoArbolDecision.h"
#include "Paciente.h"
#include "Servicio.h"

class ArbolDecision {
private:
    NodoArbolDecision* raiz;

public:
    ArbolDecision();
    ~ArbolDecision();
    void liberar(NodoArbolDecision* nodo);
    void crearArbol();
    NodoArbolDecision* evaluar(Paciente paciente);
    bool esServicio(NodoArbolDecision* nodo);
    void inorden(NodoArbolDecision *nodo) const;
    void preorden(NodoArbolDecision *nodo) const;
    void postorden(NodoArbolDecision *nodo) const;
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
