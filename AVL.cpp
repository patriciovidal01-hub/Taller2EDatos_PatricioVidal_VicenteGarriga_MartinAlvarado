//
// Created by marti on 21/10/2026.
//
#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL() : raiz(nullptr) {}


void AVL::liberar(Nodo<Paciente>* nodo) {
    if (nodo == nullptr) {
        return;
    }
    liberar(nodo->getIzq());
    liberar(nodo->getDer());
    delete nodo;
}

AVL::~AVL() {
    liberar(raiz);
}

bool AVL::estaVacio() const {
    return raiz == nullptr;
}

int AVL::altura(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->getAltura();
}

//cuenta los pacientes del arbol
int AVL::contar(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + contar(nodo->getIzq()) + contar(nodo->getDer());
}

int AVL::cantidad() const {
    return contar(raiz);
}

int AVL::getAltura() const {
    return altura(raiz);
}

//factor de balance = altura(izquierdo) - altura(derecho)
int AVL::factorBalance(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->getIzq()) - altura(nodo->getDer());
}

int AVL::getFactorBalanceRaiz() const {
    return factorBalance(raiz);
}

void AVL::actualizarAltura(Nodo<Paciente>* nodo) {
    int hi = altura(nodo->getIzq());
    int hd = altura(nodo->getDer());
    nodo->setAltura(1 + (hi > hd ? hi : hd));
}

//ID clave de ordenamiento
Nodo<Paciente>* AVL::insertar(Nodo<Paciente>* nodo, const Paciente& paciente, bool& insertado) {
    if (nodo == nullptr) {
        insertado = true;
        return new Nodo<Paciente>(paciente);
    }
    if (paciente.getId() < nodo->getDato().getId()) {
        nodo->setIzq(insertar(nodo->getIzq(), paciente, insertado));
    } else if (paciente.getId() > nodo->getDato().getId()) {
        nodo->setDer(insertar(nodo->getDer(), paciente, insertado));
    } else {
        insertado = false; //IDduplicado
        return nodo;
    }
    actualizarAltura(nodo);
    return nodo;
}

bool AVL::insertar(const Paciente& paciente) {
    bool insertado = false;
    raiz = insertar(raiz, paciente, insertado);
    return insertado;
}

//busqueda por ID
Nodo<Paciente>* AVL::buscar(const std::string& id, std::string& ruta) const {
    Nodo<Paciente>* actual = raiz;
    ruta = "";
    while (actual != nullptr) {
        if (!ruta.empty()) {
            ruta += " -> ";
        }
        ruta += actual->getDato().getId();
        if (id == actual->getDato().getId()) {
            return actual;
        } else if (id < actual->getDato().getId()) {
            actual = actual->getIzq();
        } else {
            actual = actual->getDer();
        }
    }
    return nullptr;
}

//IMPLEMENTACION DE ROTACIONES
Nodo<Paciente>* AVL::rotacionDerecha(Nodo<Paciente>* nodo) {
    Nodo<Paciente>* nuevaRaiz = nodo->getIzq();
    Nodo<Paciente>* huerfano = nuevaRaiz->getDer();

    nuevaRaiz->setDer(nodo);
    nodo->setIzq(huerfano);

    return nuevaRaiz;
}

Nodo<Paciente>* AVL::rotacionIzquierda(Nodo<Paciente>* nodo) {
    Nodo<Paciente>* nuevaRaiz = nodo->getDer();
    Nodo<Paciente>* huerfano = nuevaRaiz->getIzq();
    
    nuevaRaiz->setIzq(nodo);
    nodo->setDer(huerfano);
//Actua como un espejo de la rotacionDerecha, lo que era der ahora es izq y viceversa
    return nuevaRaiz;
    } 
}

//PENDIENTE ROTACIONES, METODO VACIO TEMPORALMENTE
Nodo<Paciente>* AVL::balancear(Nodo<Paciente>* nodo) {
    return nodo;
}

Nodo<Paciente>* AVL::extraerMinimo(Nodo<Paciente>* nodo, Nodo<Paciente>*& minimo) {
    if (nodo->getIzq() == nullptr) {
        minimo = nodo;
        return nodo->getDer();
    }
    nodo->setIzq(extraerMinimo(nodo->getIzq(), minimo));
    actualizarAltura(nodo);
    return balancear(nodo);
}

//eliminacion por ID
Nodo<Paciente>* AVL::eliminar(Nodo<Paciente>* nodo, const std::string& id, bool& eliminado) {
    if (nodo == nullptr) {
        return nullptr; // el ID no existe
    }
    if (id < nodo->getDato().getId()) {
        nodo->setIzq(eliminar(nodo->getIzq(), id, eliminado));
    } else if (id > nodo->getDato().getId()) {
        nodo->setDer(eliminar(nodo->getDer(), id, eliminado));
    } else {
        eliminado = true;
        Nodo<Paciente>* izq = nodo->getIzq();
        Nodo<Paciente>* der = nodo->getDer();
        if (izq == nullptr || der == nullptr) { //hoja o un solo hijo
            Nodo<Paciente>* hijo = (izq != nullptr) ? izq : der;
            delete nodo;
            return hijo;
        }
        //dos hijos
        Nodo<Paciente>* sucesor = nullptr;
        Nodo<Paciente>* nuevaDer = extraerMinimo(der, sucesor);
        sucesor->setIzq(izq);
        sucesor->setDer(nuevaDer);
        delete nodo;
        nodo = sucesor;
    }
    actualizarAltura(nodo);
    return balancear(nodo);
}

bool AVL::eliminar(const std::string& id) {
    bool eliminado = false;
    raiz = eliminar(raiz, id, eliminado);
    return eliminado;
}

void AVL::inorden(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) return;
    inorden(nodo->getIzq());
    cout << nodo->getDato().getNombre() << " (" << nodo->getDato().getId() << ") ";
    inorden(nodo->getDer());
}

void AVL::preorden(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) return;
    cout << nodo->getDato().getNombre() << " (" << nodo->getDato().getId() << ") ";
    preorden(nodo->getIzq());
    preorden(nodo->getDer());
}

void AVL::postorden(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) return;
    postorden(nodo->getIzq());
    postorden(nodo->getDer());
    cout << nodo->getDato().getNombre() << " (" << nodo->getDato().getId() << ") ";
}

void AVL::mostrarFactores(Nodo<Paciente>* nodo) const {
    if (nodo == nullptr) return;
    mostrarFactores(nodo->getIzq());
    cout << nodo->getDato().getId() << ": FB=" << factorBalance(nodo)
         << " (altura " << nodo->getAltura() << ")" << endl;
    mostrarFactores(nodo->getDer());
}

void AVL::mostrarInorden() const {
    if (estaVacio()) { cout << "Sin pacientes" << endl; return; }
    inorden(raiz);
    cout << endl;
}

void AVL::mostrarPreorden() const {
    if (estaVacio()) { cout << "Sin pacientes" << endl; return; }
    preorden(raiz);
    cout << endl;
}

void AVL::mostrarPostorden() const {
    if (estaVacio()) { cout << "Sin pacientes" << endl; return; }
    postorden(raiz);
    cout << endl;
}

void AVL::mostrarFactoresBalance() const {
    if (estaVacio()) { cout << "Sin pacientes" << endl; return; }
    mostrarFactores(raiz);
}
