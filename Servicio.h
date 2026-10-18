//
// Created by patri on 19-09-2026.
//

#ifndef TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_SERVICIO_H
#define TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_SERVICIO_H
#include "Lista_Pacientes.h"

class Servicio {
    private:
        std::string servicio;
        Lista_Pacientes* pacientes;
    public:
        Servicio(std::string servicio, Lista_Pacientes* lista);
        ~Servicio();
        std::string getServicio();
        Lista_Pacientes* getPacientes();
        int getNumPacientes();
        void mostrarPacientes();
};


#endif //TALLER1EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_SERVICIO_H
