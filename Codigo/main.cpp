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
    

    cout << "Prueba de funcion cargarCatalogo()" << endl;
    universo.cargarCatalogo("datos/catalogo.csv");
    cout << "Total de galaxias en el catalogo: " << universo.getTotal() << endl;

    cout << "Prueba de funcion guardarResultados()" << endl;
    universo.guardarResultados("datos/resultados.csv");
    
    cout << "Prueba de ordenamiento por distancia" << endl;
    universo.ordenarPorDistancia();
    universo.mostrarCatalogo();

    cout << "Prueba de busqueda por nombre" << endl;
    int pos = universo.buscarPorNombre("Andromeda");
    if (pos != -1) {
        cout << "Galaxia encontrada:" << endl;
        universo.mostrarCatalogo();         
    } else {
        cout << "Galaxia no encontrada." << endl;
    }

    cout << "Prueba de estadisticas" << endl;
    universo.mostrarEstadisticas();

    return 0;
}

