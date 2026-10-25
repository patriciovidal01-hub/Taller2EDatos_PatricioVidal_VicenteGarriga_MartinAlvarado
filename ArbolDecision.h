//
// Created by patri on 19-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#include "NodoArbolDecision.h"
#include "Paciente.h"


class ArbolDecision {
private:
    NodoArbolDecision* raiz;

public:
    ArbolDecision();
    ~ArbolDecision();
    void liberar(NodoArbolDecision* nodo);
    void crearArbol();
    NodoArbolDecision* evaluar(Paciente const &paciente) const;
    bool esServicio(NodoArbolDecision* nodo) const;
    void inorden(NodoArbolDecision *nodo) const;
    void preorden(NodoArbolDecision *nodo) const;
    void postorden(NodoArbolDecision *nodo) const;
    void mostrarIN() const;
    void mostrarPR() const;
    void mostrarPS() const;
    std::string enumToString(int number) const;
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
