//
// Created by patri on 06-09-2026.



#ifndef TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_PACIENTE_H
#define TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_PACIENTE_H

#include <iostream>
#include <string>

class Paciente {

    private:
        std::string id;
        std::string nombre;
        int edad;
        std::string servicio;
    public:
        Paciente(std::string id, std::string nombre, int edad, std::string servicio);
        ~Paciente();

        std::string getId() const;
        std::string getNombre() const;
        int getEdad() const;
        std::string getServicio() const;

};
#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_PACIENTE_H
