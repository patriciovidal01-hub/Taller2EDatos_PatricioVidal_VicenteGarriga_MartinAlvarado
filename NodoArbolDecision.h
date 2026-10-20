//
// Created by patri on 20-10-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H


enum Operador { MENOR, MENOR_IGUAL, IGUAL, MAYOR, MAYOR_IGUAL };
enum Atributo { EDAD, TEMPERATURA, PRESION, DOLOR, TIPODOLOR, TRAUMA, SINTOMAS, CIRUGIA, HOSPITALIZACIÓN };

template <typename T>
class NodoArbolDecicision {
private:
    Atributo atributo;
    Operador operador;
    T comparar;
    int servicio;

    NodoArbolDecicision<T>* izq;
    NodoArbolDecicision<T>* der;
public:
    NodoArbolDecicision(Atributo atributo, Operador operador, T comparar): atributo(atributo), operador(operador),
    comparar(comparar), servicio(-1), izq(nullptr), der(nullptr) {}
    ~NodoArbolDecicision(){}
};

#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_NODOARBOLDECISION_H
