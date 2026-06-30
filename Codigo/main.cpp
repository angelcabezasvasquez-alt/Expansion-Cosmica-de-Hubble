#include <iostream>
#include "galaxia.h"
#include "universo.h"
using namespace std;

int main() {
    const double HUBBLE_CONSTANT = 70.0;
    Universo universo(HUBBLE_CONSTANT);
    
    cout << "-----------------------------------------" << endl;
    cout << "    SIMULADOR DE LA LEY DE HUBBLE" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Constante de Hubble: " << HUBBLE_CONSTANT << " km/s/Mpc" << endl << endl;
    
    universo.cargarCatalogo("datos/catalogo.csv");
    cout << "Catalogo cargado. " << universo.getTotal() << " galaxias encontradas." << endl << endl;
    
    int opcion;
    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Mostrar todas las galaxias" << endl;
        cout << "2. Ordenar por distancia (burbuja)" << endl;
        cout << "3. Ordenar por velocidad (burbuja)" << endl;
        cout << "4. Buscar galaxia por nombre" << endl;
        cout << "5. Mostrar estadisticas" << endl;
        cout << "6. Guardar resultados en archivo" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "\nCATALOGO DE GALAXIAS" << endl;
                universo.mostrarCatalogo();
                break;
                
            case 2:
                cout << "\nORDENANDO POR DISTANCIA" << endl;
                universo.ordenarPorDistancia();
                universo.mostrarCatalogo();
                break;
                
            case 3:
                cout << "\nORDENANDO POR VELOCIDAD" << endl;
                universo.ordenarPorVelocidad();
                universo.mostrarCatalogo();
                break;
                
            case 4: {
                cout << "\nBUSCAR GALAXIA" << endl;
                string nombre;
                cout << "Ingrese el nombre de la galaxia: ";
                cin >> nombre;
                int pos = universo.buscarPorNombre(nombre);
                if (pos != -1) {
                    cout << "Galaxia encontrada:" << endl;
                    universo.mostrarCatalogo();
                } else {
                    cout << "Galaxia no encontrada." << endl;
                }
                break;
            }
                
            case 5:
                cout << "\nESTADISTICAS" << endl;
                universo.mostrarEstadisticas();
                break;
                
            case 6:
                cout << "\nGUARDANDO RESULTADOS" << endl;
                universo.guardarResultados("datos/resultados.csv");
                break;
                
            case 7:
                cout << "\nSaliendo del simulador..." << endl;
                break;
                
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);
    
    return 0;
}