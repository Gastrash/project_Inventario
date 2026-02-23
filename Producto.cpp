#include <iostream>
#include <cstdlib>    // rand, srand
#include <ctime>
#include "Producto.h"

using namespace std;

// definición estática de la función de generación de IDs
int Producto::Random_id() {
    // inicializar la semilla la primera vez si es necesario
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }
    return rand();
}

Producto Producto::Constructor(){
    Producto P;

    P.name = "NULL";
    P.cantidad = 0;
    P.id = Random_id();
    P.vacio = true;
    P.active = false;   

    return P;
}
