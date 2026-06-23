#ifndef GALAXIA_H
#define GALAXIA_H

#include <string>
using namespace std;

class Galaxia {
private:
    string nombre;
    double distancia;
    double velocidad;
    double desplazamientoAlRojo;

public:
    Galaxia();
    Galaxia(string nom, double dist);
    
    string getNombre() const;
    double getDistancia() const;
    double getVelocidad() const;
    double getDesplazamientoAlRojo() const;
    
    void setNombre(string nom);
    void setDistancia(double dist);
    
    void calcularVelocidad(double H0);
    void calcularDesplazamientoAlRojo();
    void mostrar() const;
};

#endif