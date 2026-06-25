#ifndef UNIVERSO_H
#define UNIVERSO_H

#include "galaxia.h"

class Universo {
private:
    Galaxia** catalogo;
    int total;
    int capacidad;
    double H0;

public:
    Universo(double constanteHubble);
    ~Universo();
    
    void agregarGalaxia(const Galaxia& g);
    void cargarCatalogo(const char* archivo);
    void guardarResultados(const char* archivo);
    
    void ordenarPorDistancia();
    void ordenarPorVelocidad();
    
    int buscarPorNombre(const string& nombre);
    Galaxia* buscarMasCercana();
    Galaxia* buscarMasLejana();
    
    void mostrarCatalogo();
    void mostrarEstadisticas();
    
    double getH0() const;
    int getTotal() const;
};

#endif