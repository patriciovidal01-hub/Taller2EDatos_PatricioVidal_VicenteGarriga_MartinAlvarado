//
// Created by patri on 19-09-2026.
//

#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_SERVICIO_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_SERVICIO_H
#include "AVL.h"

class Servicio {
    private:
        std::string servicio;
        AVL* pacientes;
    public:
        Servicio(std::string servicio, AVL* avl);
        ~Servicio();
        std::string getServicio();
        AVL* getPacientes();
        int getNumPacientes();
        void mostrarPacientes();
};


#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_SERVICIO_H
