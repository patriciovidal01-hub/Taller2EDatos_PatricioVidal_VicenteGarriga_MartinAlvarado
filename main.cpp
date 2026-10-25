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

bool variablesCorrectas(int ed, float tp, int pr, int dl,int dh) {
    if (ed >= 0 && ed <= 120 && tp > 0 && pr > 0 && dl <= 10 && dl >= 0 && dh >= 0) {return true;};
    return false;
}

bool tipoDolorExiste(string const &tp) {
    string tipoDolores[] = {"pecho", "cabeza", "abdomen", "extremidad", "otro"};
    for (string s : tipoDolores) {
        if (s == tp) {return true;}
    }
    return false;
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
                bool idValido;
                if (id == "") {
                    idValido = false;
                } else {
                    idValido = true;
                }

                for(char ch : id) {
                    if(!isdigit(ch)){
                        idValido = false;
                    }
                }
                int edad = stoi(edad_str);
                float temperatura = stof(temp_str);
                int presion = stoi(presion_str);
                int nivel_dolor = stoi(dolor_str);

                int trauma = stoi(trauma_str);
                int sintomas_neuro = stoi(sint_neu_str);
                int cirugia = stoi(cirugia_str);

                int dias_hospitalizacion = stoi(dias_hospitalizacion_str);

                //Validación de que los datos sean correctos.
                if(esBinario(trauma) && esBinario(sintomas_neuro) && esBinario(cirugia) && variablesCorrectas(edad, temperatura, presion, nivel_dolor, dias_hospitalizacion) && tipoDolorExiste(tipo_dolor_str) && idValido && nombre != ""){
                   if (idDuplicado(colaPacientes, id)) {
                       cout << "Error: ID duplicado " << id << endl;
                       continue;
                   }
                    Paciente p(id, nombre, edad, temperatura, presion, nivel_dolor, tipo_dolor_str, trauma, sintomas_neuro, cirugia, dias_hospitalizacion ); // Cambiar
                    colaPacientes->agregarNodo(new Nodo<Paciente>(p));
                }        
                else {
                    cout << "Error: Datos de confirmacion inválidos en el paciente " << id << endl;
                }

            } 
            catch (const exception& e) {
                cout << "Error Desconocido, Algunos o todos los datos del paciente estan corruptos y son ilegibles" << endl;
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

            cout << "ID: " << p.getId() << endl;
            cout << "Nombre: " << p.getNombre() << endl;
            cout << "Edad: " << p.getEdad() << endl;
            cout << "Temperatura: " << p.getTemperatura() << endl;
            cout << "Dolor: " << p.getDolor() << endl;
            cout << "TipoDolor: " << p.getTipoDolor() << endl;
            cout << "Trauma: " << p.getTrauma() << endl;
            cout << "Sintomas Neurologicos: " << p.getSintomasNeurologicos() << endl;
            cout << "Requiere Cirugia: " << p.getRequiereCirugia() << endl;
            cout << "Dias Hospitalizacion: " << p.getDiasHospitalizacion() << endl;
            cout << "" << endl;

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
                    cout << "" << endl;
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
    int ctdServicios = lista_servicios->cantidadServicios();
    for (int i = 0; i < ctdServicios; i++) {
        Servicio servicioVer = lista_servicios->servicioNumero(i)->getDato();

        cout << " =========== Estado " << servicioVer.getServicio() << " =========== " << endl;
        cout << "Pacientes en el departamento de " << servicioVer.getServicio() << " es: "<< servicioVer.getNumPacientes() << endl;
        servicioVer.mostrarPacientes();
        cout << endl;
    }
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
            // Insertar funcion de buscar por nombre o por ID
            cout << "Ingrese formato de busqueda: Buscar por ID (1) ó Buscar por Nombre (2) " << endl;
            string respuesta;
            cin >> respuesta;

            if(respuesta == "1"){
                cout << "Ingrese el ID del paciente a buscar: " << endl;
                string idBuscar = "";
                string rutaInicial = "";
                bool existe = false;
                //Estas 3 cositas nos ayudaran a poder tener los parametros necesarios para la busqueda.
                cin >> idBuscar;
                Nodo<Servicio>* departamentoActual = servicios->getCabeza();

                while (departamentoActual != nullptr){
                    Servicio servActual = departamentoActual->getDato();
                    AVL* arbolActual = servActual.getPacientes();
                    Nodo<Paciente>* encontrado = arbolActual->buscar(idBuscar, rutaInicial);

                    if(encontrado != nullptr){
                        Paciente p = encontrado->getDato();
                        existe = true;
                        cout << "Paciente encontrado: " << endl;
                        cout << "===========" << endl;
                        cout << "ID: " << p.getId() << endl;
                        cout << "Nombre: " << p.getNombre() << endl;
                        cout << "Edad: " << p.getEdad() << endl;
                        cout << "Departamento: " << servActual.getServicio() << endl;
                        cout << "T: " << p.getTemperatura() << "° | ";
                        cout << "D: " << p.getDolor() << " | ";
                        cout << "TD: " << p.getTipoDolor() << " | ";
                        cout << "TR: " << p.getTrauma() << " | ";
                        cout << "SN: " << p.getSintomasNeurologicos() << " | ";
                        cout << "RC: " << p.getRequiereCirugia() << " | ";
                        cout << "DH: " << p.getDiasHospitalizacion() << endl;
                        cout << "===========" << endl;
                        cout << "" << endl;
                        cout << "La ruta fue: " << rutaInicial << endl;
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

            else if(respuesta == "2"){
                cout << "Ingrese el Nombre del paciente a buscar: " << endl;
                string nombreBuscar = "";
                int cantidadTotal = 0;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nombreBuscar);

                Nodo<Servicio>* departamentoActual = servicios->getCabeza();

                while (departamentoActual != nullptr) {
                    Servicio servActual = departamentoActual->getDato();
                    AVL* arbolActual = servActual.getPacientes();
                    cantidadTotal += arbolActual->mostrarBusquedaPaciente(nombreBuscar);
                    departamentoActual = departamentoActual->getSiguiente();
                    }

                if (cantidadTotal == 0) {
                    cout << "No existe el paciente en este hospital." << endl;
                    }
                cout << endl;
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


