//
// Created by marti on 21/10/2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
#include "Nodo.h"
#include "Paciente.h"
#include <string>

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
    Nodo<Paciente>* rotacionDerecha(Nodo<Paciente>* nodo); //agregamos la funcion de equilibrar si es que hay desbalance hacia la izq
    Nodo<Paciente>* rotacionIzquierda(Nodo<Paciente>* nodo); //agregamos la funcion de equilibrar si es que hay desbalance hacia la der
    void mostrarFactores(Nodo<Paciente>* nodo) const;
    int contar(Nodo<Paciente>* nodo) const;
    void liberar(Nodo<Paciente>* nodo);
    Nodo<Paciente>* eliminar(Nodo<Paciente>* nodo, const std::string& id, bool& eliminado);
    Nodo<Paciente>* extraerMinimo(Nodo<Paciente>* nodo, Nodo<Paciente>*& minimo);
    Nodo<Paciente>* balancear(Nodo<Paciente>* nodo); //aqui va las rotaciones PENDIENTE
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
    Nodo<Paciente>* buscar(const std::string& id, std::string& ruta) const;
    Nodo<Paciente>* buscarNombre(const std::string& id, std::string& ruta) const;
    void inordenNombre(Nodo<Paciente>* nodo, std::string &ruta, std::string nombre, Nodo<Paciente>* &p) const;
    bool eliminar(const std::string& id); // false si el ID no existe
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_AVL_H
