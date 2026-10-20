//
// Created by patri on 19-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
#include "NodoArbolDecision.h"

class ArbolDecision {
private:
    NodoArbolDecision<int>* raiz;

public:
    ArbolDecision(NodoArbolDecision* raiz);
    ~ArbolDecision();

    void crearArbol(NodoArbolDecision* raiz);
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_ARBOLDECISION_H
