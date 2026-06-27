#include "universo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Universo::Universo(double constanteHubble) {
    H0 = constanteHubble;
    total = 0;
    capacidad = 100;
    catalogo = new Galaxia*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        catalogo[i] = NULL;
    }
}


Universo::~Universo() {
    for (int i = 0; i < total; i++) {
        delete catalogo[i];
    }
    delete[] catalogo;
}

void Universo::agregarGalaxia(const Galaxia& g) {
    if (total >= capacidad) {
        capacidad *= 2;
        Galaxia** nuevo = new Galaxia*[capacidad];
        for (int i = 0; i < total; i++) {
            nuevo[i] = catalogo[i];
        }
        delete[] catalogo;
        catalogo = nuevo;
    }
    
    catalogo[total] = new Galaxia(g);
    catalogo[total]->calcularVelocidad(H0);
    catalogo[total]->calcularDesplazamientoAlRojo();
    total++;
}

void Universo::cargarCatalogo(const char* archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir " << archivo << endl;
        return;
    }
    
    string nombre;
    double distancia;
    string linea;
    
    getline(file, linea); 
    
    while (file >> nombre >> distancia) {
        Galaxia g(nombre, distancia);
        agregarGalaxia(g);
    }
    
    file.close();
    cout << "Catalogo cargado desde " << archivo << endl;
}

void Universo::guardarResultados(const char* archivo) {
    ofstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al guardar archivo" << endl;
        return;
    }
    
    file << "Nombre,Distancia(Mpc),Velocidad(km/s),DesplazamientoAlRojo" << endl;
    for (int i = 0; i < total; i++) {
        file << catalogo[i]->getNombre() << ","
             << catalogo[i]->getDistancia() << ","
             << catalogo[i]->getVelocidad() << ","
             << catalogo[i]->getDesplazamientoAlRojo() << endl;
    }
    
    file.close();
    cout << "Resultados guardados en " << archivo << endl;
}

double Universo::getH0() const {
    return H0;
}

int Universo::getTotal() const {
    return total;
}