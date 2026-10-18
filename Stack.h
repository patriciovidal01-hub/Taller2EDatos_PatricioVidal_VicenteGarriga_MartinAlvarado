//
// Created by patri on 19-09-2026.
//

#ifndef TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_STACK_H
#define TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_STACK_H
#include "Nodo.h"
#include "Paciente.h"


class Stack {
    private:
        Nodo<Paciente>* atencionCabeza;

    public:
        Stack();
        ~Stack();
        void eliminarCabeza();
        void push(Nodo<Paciente>* nodo);
        void mostrarHistorial() const;
};


#endif //TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_STACK_H
