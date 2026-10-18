//
// Created by patri on 19-09-2026.
//

#ifndef TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_PACIENTES_H
#define TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_PACIENTES_H
#include "Lista.h"
#include "Paciente.h"


class Lista_Pacientes : public Lista<Paciente> {
    public:
        Lista_Pacientes();
        virtual ~Lista_Pacientes();
};


#endif //TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_LISTA_PACIENTES_H
