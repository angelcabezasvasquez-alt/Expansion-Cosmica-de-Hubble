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

void Galaxia::setNombre(string nom) {
    nombre = nom;
}

void Galaxia::setDistancia(double dist) {
    distancia = dist;
}

void Galaxia::calcularVelocidad(double H0) {
    velocidad = H0 * distancia;  // v = H0 * d
}

void Galaxia::calcularDesplazamientoAlRojo() {
    if (velocidad < VelocidadLuz) {
        desplazamientoAlRojo = velocidad / VelocidadLuz;  // z = v / c
    } else {
        desplazamientoAlRojo = -1;
    }
}

void Galaxia::mostrar() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Distancia: " << distancia << " Mpc" << endl;
    cout << "Velocidad de recesion: " << velocidad << " km/s" << endl;
    cout << "Desplazamiento al rojo: " << desplazamientoAlRojo << endl;
}