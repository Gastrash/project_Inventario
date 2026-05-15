#include <cstdlib>
#include <ctime>

#include "Producto.h"

Producto::Producto(){

    name = "NULL";
    cantidad = 0;
    id = Random_id();
    vacio = true;
    active = false;
}

int Producto::Random_id(){

    static bool seeded = false;

    if(!seeded){
        srand(time(nullptr));
        seeded = true;
    }

    return 1000 + rand() % 9000;
}

std::string Producto::getName(){
    return name;
}

int Producto::getCantidad(){
    return cantidad;
}

void Producto::setCantidad(int nuevaCantidad){
    cantidad = nuevaCantidad;
}