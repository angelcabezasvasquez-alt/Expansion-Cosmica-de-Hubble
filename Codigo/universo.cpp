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

void Universo::ordenarPorDistancia() {
    if (total <= 1) return;
    
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (catalogo[i]->getDistancia() > catalogo[j]->getDistancia()) {
                Galaxia* temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    cout << "Galaxias ordenadas por distancia." << endl;
}

void Universo::ordenarPorVelocidad() {
    if (total <= 1) return;
    
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (catalogo[i]->getVelocidad() > catalogo[j]->getVelocidad()) {
                Galaxia* temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    cout << "Galaxias ordenadas por velocidad." << endl;
}

int Universo::buscarPorNombre(const string& nombre) {
    for (int i = 0; i < total; i++) {
        if (catalogo[i]->getNombre() == nombre) {
            return i;
        }
    }
    return -1;
}

Galaxia* Universo::buscarMasCercana() {
    if (total == 0) return NULL;
    
    int idx = 0;
    for (int i = 1; i < total; i++) {
        if (catalogo[i]->getDistancia() < catalogo[idx]->getDistancia()) {
            idx = i;
        }
    }
    return catalogo[idx];
}

Galaxia* Universo::buscarMasLejana() {
    if (total == 0) return NULL;
    
    int idx = 0;
    for (int i = 1; i < total; i++) {
        if (catalogo[i]->getDistancia() > catalogo[idx]->getDistancia()) {
            idx = i;
        }
    }
    return catalogo[idx];
}

void Universo::mostrarCatalogo() {
    if (total == 0) {
        cout << "El catalogo esta vacio." << endl;
        return;
    }
    
    for (int i = 0; i < total; i++) {
        cout << "--- Galaxia " << i + 1 << " ---" << endl;
        catalogo[i]->mostrar();
        cout << endl;
    }
}

void Universo::mostrarEstadisticas() {
    cout << "=== ESTADISTICAS DEL UNIVERSO ===" << endl;
    cout << "Total de galaxias: " << total << endl;
    cout << "Constante de Hubble: " << H0 << " km/s/Mpc" << endl;
    
    if (total > 0) {
        Galaxia* cercana = buscarMasCercana();
        Galaxia* lejana = buscarMasLejana();
        cout << "Galaxia mas cercana: " << cercana->getNombre() 
             << " (" << cercana->getDistancia() << " Mpc)" << endl;
        cout << "Galaxia mas lejana: " << lejana->getNombre() 
             << " (" << lejana->getDistancia() << " Mpc)" << endl;
    }
}