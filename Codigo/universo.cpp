#include "universo.h"
#include <iostream>
using namespace std;

Universo::Universo(double constanteHubble) {
    H0 = constanteHubble;
    total = 0;
    capacidad = 100;
    
    catalogo = new Galaxia*[capacidad];
    
    for (int i = 0; i < capacidad; i++) {
        catalogo[i] = nullptr;
    }
}


Universo::~Universo() {

    for (int i = 0; i < total; i++) {
        delete catalogo[i];
    }

    delete[] catalogo;
}