#include "galaxia.h"
#include <iostream>
using namespace std;

const double VelocidadLuz = 299792.0;

Galaxia::Galaxia() {
    nombre = "";
    distancia = 0.0;
    velocidad = 0.0;
    desplazamientoAlRojo = 0.0;
}

Galaxia::Galaxia(string nom, double dist) {
    nombre = nom;
    distancia = dist;
    velocidad = 0.0;
    desplazamientoAlRojo = 0.0;
}


string Galaxia::getNombre() const {
    return nombre;
}

double Galaxia::getDistancia() const {
    return distancia;
}

double Galaxia::getVelocidad() const {
    return velocidad;
}

double Galaxia::getDesplazamientoAlRojo() const {
    return desplazamientoAlRojo;
}