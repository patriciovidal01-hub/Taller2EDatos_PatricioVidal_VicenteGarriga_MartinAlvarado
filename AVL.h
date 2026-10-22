//
// Created by marti on 21/10/2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
#include "Nodo.h"
#include "Paciente.h"

class AVL {
private:
    Nodo<Paciente>* raiz;

    // metodos recursivos auxiliares
    Nodo<Paciente>* insertar(Nodo<Paciente>* nodo, const Paciente& paciente, bool& insertado);
    int altura(Nodo<Paciente>* nodo) const;
    int factorBalance(Nodo<Paciente>* nodo) const;
    void actualizarAltura(Nodo<Paciente>* nodo);
    void inorden(Nodo<Paciente>* nodo) const;
    void preorden(Nodo<Paciente>* nodo) const;
    void postorden(Nodo<Paciente>* nodo) const;
    void mostrarFactores(Nodo<Paciente>* nodo) const;
    int contar(Nodo<Paciente>* nodo) const;
    void liberar(Nodo<Paciente>* nodo);

public:
    AVL();
    ~AVL();

    bool insertar(const Paciente& paciente); //false si el ID ya existe
    bool estaVacio() const;
    int getAltura() const;
    int cantidad() const; //cantidad de pacientes del arbol
    int getFactorBalanceRaiz() const;
    void mostrarInorden() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;
    void mostrarFactoresBalance() const; //factor de balance de cada nodo
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
