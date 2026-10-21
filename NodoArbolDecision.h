//
// Created by patri on 20-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
#include <string>

enum Operador { MENOR, MENOR_IGUAL, IGUAL, MAYOR, MAYOR_IGUAL };
enum Atributo { EDAD, TEMPERATURA, PRESION, DOLOR, TIPODOLOR, TRAUMA, SINTOMAS, CIRUGIA, HOSPITALIZACION };

class NodoArbolDecision {
private:
    Atributo atributo;
    Operador operador;
    double comparar;
    double servicio;
    NodoArbolDecision* izq;
    NodoArbolDecision* der;
    std::string resultado;
    std::string strop;

public:
    NodoArbolDecision(Atributo atributo, Operador operador, double comparar, NodoArbolDecision* izq, NodoArbolDecision* der );
    NodoArbolDecision(std::string resultado);
    NodoArbolDecision* preguntar(double datoPaciente);
    NodoArbolDecision* izqNodo();
    NodoArbolDecision* derNodo();
    Atributo getAtributo();
    std::string getStrop();
    double getComparar();
    ~NodoArbolDecision();
};

#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
