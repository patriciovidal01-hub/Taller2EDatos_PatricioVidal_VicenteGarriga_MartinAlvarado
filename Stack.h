//
// Created by patri on 19-09-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_STACK_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_STACK_H
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


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_STACK_H
