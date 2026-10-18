#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Queue.h"
#include "Paciente.h"
#include "Nodo.h"
#include "Lista_Servicios.h"
#include "Lista_Pacientes.h"
#include <limits>
#include "Stack.h"

using namespace std;

void leerArchivo(Queue* colaPacientes ) {
    ifstream archivo("pacientes.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id, nombre, edad_str, servicio;

            getline(ss, id, ';');
            getline(ss, nombre, ';');
            getline(ss, edad_str, ';');
            getline(ss, servicio, ';');

            int edad = stoi(edad_str);


            Paciente p(id, nombre, edad, servicio);
            colaPacientes->agregarNodo(new Nodo<Paciente>(p));
        }
        archivo.close();
        cout << "Archivo cargado correctamente en la Cola." << endl;

    } else {
        cout << "Error: No se encontro pacientes.txt" << endl;
    }
}

void llenarServicios (Lista_Servicios* lista_servicios) {
    string servicios[8] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};

    for (string s : servicios) {
        Lista_Pacientes* lista = new Lista_Pacientes();
        Servicio servicio = Servicio(s, lista);
        lista_servicios->agregarNodo(new Nodo<Servicio>(servicio));
    }
}


void atenderPacientes(Queue* colaPacientes, Lista_Servicios* lista_servicios, Stack* historial) {
    if (colaPacientes->cantidadPacientes() != 0) {
        cout << " =========== Pacientes en espera =========== " << endl;
        colaPacientes->mostrarPacientes();

        int numeroAtender;
        cout << endl;
        cout << "Indique la cantidad de pacientes que desea atender" << endl;
        cin >> numeroAtender;
        while (cin.fail()) {
            cout << "Opcion Invalida" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> numeroAtender;
        }

        cout << " =========== Atendiendo a pacientes =========== " << endl;
        if (numeroAtender > colaPacientes->cantidadPacientes()) {
            numeroAtender = colaPacientes->cantidadPacientes();
        }
        for (int i = 0; i < numeroAtender; i++) {
            Nodo<Paciente>* nodo = colaPacientes->getCabeza();
            Paciente p = nodo->getDato();
            Nodo<Servicio>* servicioPaciente = lista_servicios->encontrarServicio(nodo->getDato().getServicio());
            if (servicioPaciente != nullptr) {
                servicioPaciente->getDato().getPacientes()->agregarNodo(new Nodo<Paciente>(p));
                historial->push(new Nodo<Paciente>(p));
            }
            colaPacientes->eliminarCabeza();


            cout << "ID: " << p.getId() << endl;
            cout << "Nombre: " << p.getNombre() << endl;
            cout << "Edad: " << p.getEdad() << endl;
            cout << "Servicio: " << p.getServicio() << endl;
            cout << endl;
            if (servicioPaciente != nullptr) {
                cout << "Paciente fue enviado a " << p.getServicio() << endl;
            } else {
                cout << "El servicio del paciente no existe" << endl;
            }

        }
    } else {
        cout << "No hay pacientes para atender" << endl;
        cout << endl;
    }
}

void verDepartamentos(Lista_Servicios* lista_servicios){
    Nodo<Servicio>* aux = lista_servicios->getCabeza();
    int ctdServicios = lista_servicios->cantidadServicios();
    for (int i = 0; i < ctdServicios; i++) {
        cout << i+1 << ". " << aux->getDato().getServicio() << endl;
        aux = aux->getSiguiente();
    }
    int opcion;
    cout << endl;
    cout << "Seleccionar opcion: ";
    cin >> opcion;

    while (cin.fail() || opcion > ctdServicios || opcion < 1 ) {
        cout << "Opcion Invalida" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> opcion;
    }

    Servicio servicioVer = lista_servicios->servicioNumero(opcion)->getDato();

    cout << " =========== Estado " << servicioVer.getServicio() << " =========== " << endl;
    cout << "Pacientes en el departamento de " << servicioVer.getServicio() << " es: "<< servicioVer.getNumPacientes() << endl;
    servicioVer.mostrarPacientes();
    cout << endl;
}

void revisarHistorial(Stack* historial) {
    cout << "=========== Historial de ultimas atenciones del hospital ===========" << endl;
    historial->mostrarHistorial();
}

int main() {
    Queue* colaPacientes = new Queue();
    leerArchivo(colaPacientes);
    Lista_Servicios* servicios = new Lista_Servicios();
    llenarServicios(servicios);
    Stack* historial = new Stack();

    string opcion;

    do {
        cout << " =========== Hospital Marmaja =========== " << endl;
        cout << "1. Atender pacientes " << endl;
        cout << "2. Ver departamento " << endl;
        cout << "3. Revisar historial de atencion " << endl;
        cout << "4. Salir " << endl;

        cin >> opcion;

        if (opcion == "1") {
            atenderPacientes(colaPacientes, servicios, historial);

        } else if (opcion == "2") {
            verDepartamentos(servicios);

        } else if (opcion == "3") {
            revisarHistorial(historial);

        } else if (opcion == "4") {
            cout << "Cerrando sistema...." << endl;
            break;

        } else {
            cout << "Opcion Invalida" << endl;
        }

    } while (opcion != "4");
    delete historial;
    delete servicios;
    delete colaPacientes;
    return 0;
}



