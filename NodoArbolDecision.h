//
// Created by patri on 20-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
#include <string>;

enum Operador { MENOR, MENOR_IGUAL, IGUAL, MAYOR, MAYOR_IGUAL };
enum Atributo { EDAD, TEMPERATURA, PRESION, DOLOR, TIPODOLOR, TRAUMA, SINTOMAS, CIRUGIA, HOSPITALIZACION };

class NodoArbolDecision {
private:
    std::string resultado;
    Atributo atributo;
    Operador operador;
    int comparar;
    int servicio;
    NodoArbolDecision* izq;
    NodoArbolDecision* der;

public:
    NodoArbolDecision(Atributo atributo, Operador operador, int comparar, NodoArbolDecision* izq, NodoArbolDecision* der );
    NodoArbolDecision(std::string resultado);
    NodoArbolDecision* preguntar(int datoPaciente);
    ~NodoArbolDecision();
};

#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
