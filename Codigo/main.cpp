#include <iostream>
#include "galaxia.h"
using namespace std;

int main() {
    cout << "SIMULADOR DE LA LEY DE HUBBLE" << endl;

    Galaxia g1("Andromeda", 0.78);
    g1.calcularVelocidad(70.0);
    g1.calcularDesplazamientoAlRojo();
    g1.mostrar();
    
    return 0;
}