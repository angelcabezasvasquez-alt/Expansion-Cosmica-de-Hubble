#include <iostream>
#include "galaxia.h"
#include "universo.h"
using namespace std;

int main() {
    cout << "SIMULADOR DE LA LEY DE HUBBLE" << endl;

    cout << "Prueba de la clase Galaxia" << endl;
    Galaxia g1("Andromeda", 0.78);
    g1.calcularVelocidad(70.0);
    g1.calcularDesplazamientoAlRojo();
    g1.mostrar();
    
    cout << endl;

    cout << "Prueba de la clase Universo" << endl;
    Universo universo(70.0); 
    cout << "Universo creado exitosamente." << endl;
    cout << "Constante de Hubble: " << universo.getH0() << " km/s/Mpc" << endl;
    

    cout << "Prueba de funcionagregarGalaxia() de la clase universo" << endl;
    Galaxia g2("Via Lactea", 0.0);
    universo.agregarGalaxia(g2);
    cout << "Galaxia agregada al catalogo." << endl;
    cout << "Total de galaxias: " << universo.getTotal() << endl;
    
    return 0;
}