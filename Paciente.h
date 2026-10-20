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
        double temperatura;
        int presionArterial;
        int dolor;
        std::string tipoDolor;
        int trauma;
        int sintomasNeurologicos;
        int requiereCirugia;
        int diasHospitalizacion;
        std::string servicio;
    public:
        Paciente(std::string id, std::string nombre, int edad, double temperatura,
                 int presionArterial, int dolor, std::string tipoDolor, int trauma,
                 int sintomasNeurologicos, int requiereCirugia, int diasHospitalizacion);
        ~Paciente();
 
        std::string getId() const;
        std::string getNombre() const;
        int getEdad() const;
        double getTemperatura() const;
        int getPresionArterial() const;
        int getDolor() const;
        std::string getTipoDolor() const;
        int getTrauma() const;
        int getSintomasNeurologicos() const;
        int getRequiereCirugia() const;
        int getDiasHospitalizacion() const;
        std::string getServicio() const;
        void setServicio(std::string servicio);

};
#endif //TALLER2EDATOS_PATRICIOVIDAL_VICENTEGARRIGA_MARTINALVARADO_PACIENTE_H
