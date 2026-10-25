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
#include "ArbolDecision.h"
#include "AVL.h"
#include "NodoArbolDecision.h"

using namespace std;

//valida si es duplicado y valida si el el valor para los atributos realmente son binarios o no
bool idDuplicado(Queue* colaPacientes, const string& id) {
    Nodo<Paciente>* aux = colaPacientes->getCabeza();
    while (aux != nullptr) {
        if (aux->getDato().getId() == id) {
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}
 
bool esBinario(int valor) {
    return valor == 0 || valor == 1;
}

void leerArchivo(Queue* colaPacientes ) {
    ifstream archivo("pacientes.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id, nombre, edad_str, temp_str, presion_str, dolor_str, tipo_dolor_str, trauma_str, sint_neu_str, cirugia_str, dias_hospitalizacion_str;

            getline(ss, id, ';');
            getline(ss, nombre, ';');
            getline(ss, edad_str, ';');
            getline(ss, temp_str, ';');
            getline(ss, presion_str, ';');
            getline(ss, dolor_str, ';');
            getline(ss, tipo_dolor_str, ';');
            getline(ss, trauma_str, ';');
            getline(ss, sint_neu_str, ';');
            getline(ss, cirugia_str, ';');
            getline(ss, dias_hospitalizacion_str, ';'); 

            //Aca hacemos las conversiones de los datos papus
            //Finalizado

            try{
            int edad = stoi(edad_str);
            float temperatura = stof(temp_str);
            int presion = stoi(presion_str);
            int nivel_dolor = stoi(dolor_str);
            
            int trauma = stoi(trauma_str);
            int sintomas_neuro = stoi(sint_neu_str);
            int cirugia = stoi(cirugia_str);
                
            int dias_hospitalizacion = stoi(dias_hospitalizacion_str);

                //Aca hacemos la validacion de que sea 0"s y 1"s wazaaa.
                if(esBinario(trauma) && esBinario(sintomas_neuro) && esBinario(cirugia)){
                   Paciente p(id, nombre, edad, temperatura, presion, nivel_dolor, tipo_dolor_str, trauma, sintomas_neuro, cirugia, dias_hospitalizacion ); // Cambiar
                    colaPacientes->agregarNodo(new Nodo<Paciente>(p));
                }        
                else {
                    cout << "Error: Datos de confirmacion inválidos en el paciente " << id << endl;
                }
            } 
            catch (const exception& e) {
                cout << "Error Desconocido, Algunos o todos los datos del paciente estan corruptos y son ilegibles" << endl;
                continue;
            }
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
        AVL* avl = new AVL();
        Servicio servicio = Servicio(s, avl);
        lista_servicios->agregarNodo(new Nodo<Servicio>(servicio));
    }
}


void atenderPacientes(Queue* colaPacientes, Lista_Servicios* lista_servicios, ArbolDecision* arbolDecision) {

    if (colaPacientes->cantidadPacientes() > 0) {
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
            NodoArbolDecision* resultado = arbolDecision->evaluar(p);

            // METODO EN MAIN PARA DETERMINAR SERVICIO
            if (lista_servicios->encontrarServicio(resultado->getResultado()) != nullptr) {
                Nodo<Servicio>* nodoS = lista_servicios->encontrarServicio(resultado->getResultado());
                Servicio s = nodoS->getDato();
                AVL* avl = s.getPacientes();
                p.setServicio(resultado->getResultado());
                bool insertado = avl->insertar(p);
                if (insertado) {
                    cout << p.getNombre() << " fue enviado a " << p.getServicio() << endl;
                    cout << "Paciente insertado en " << p.getServicio() << endl;
                } else {
                    cout << p.getNombre() << " ID duplicado " << "no se pudo enviar a " << p.getServicio() << endl;
                }
            } else {
                cout << "No hay servicio al que se pueda mandar" << endl;
            }
            colaPacientes->eliminarCabeza();
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

int main() {
    Queue* colaPacientes = new Queue();
    leerArchivo(colaPacientes);
    Lista_Servicios* servicios = new Lista_Servicios();
    llenarServicios(servicios);
    ArbolDecision* arbolDecision = new ArbolDecision();
    arbolDecision->crearArbol();

    string opcion;

    do {
        cout << " =========== Hospital Marmaja =========== " << endl;
        cout << "1. Atender pacientes " << endl;
        cout << "2. Ver departamento " << endl;
        cout << "3. Buscar paciente " << endl;
        cout << "4. Salir " << endl;

        cin >> opcion;

        if (opcion == "1") {
            atenderPacientes(colaPacientes, servicios, arbolDecision);

        } else if (opcion == "2") {
            verDepartamentos(servicios);

        } else if (opcion == "3") {
            // Finalizado
           
            cout << "Ingrese el ID del paciente a buscar: " << endl;
            string idBuscar = "";
            string rutaInicial = "";
            bool existe = false;
            //Estas 3 cositas nos ayudaran a poder tener los parametros necesarios para la busqueda.
            cin >> idBuscar;
            Nodo<Servicio>* departamentoActual = lista_servicios->getCabeza();

            while (departamentoActual != nullptr){
                Servicio servActual = departamentoActual->getDato();
                AVL* arbololActual = servActual.getPacientes();
                Nodo<Paciente>* encontrado = arbololActual->buscar(idBuscar, rutaInicial);
        
                if(encontrado != nullptr){
                    existe = true;
                    cout << "Paciente encontrado: " << encontrado->getDato().getNombre() << ". La ruta fue: " << rutaInicial << endl;
                    break;
                }   
                else {
                    departamentoActual = departamentoActual->getSiguiente();
                    }
                }
        
            if (existe != true) {
                cout << "La ID ingresada no pertenece a ningun paciente del hospital." << endl;
                }
            }

        } else if (opcion == "4") {
            cout << "Cerrando sistema...." << endl;
            break;

        } else {
            cout << "Opcion Invalida" << endl;
        }

    } while (opcion != "4");
    delete arbolDecision;
    delete servicios;
    delete colaPacientes;
    return 0;
}



