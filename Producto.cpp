#include <cstdlib>
#include <ctime>

#include "Producto.h"

Producto::Producto(std::string name, int cantidad){

    this->name = name;
    this->cantidad = cantidad;
    this->id = idFunction();
    this->active = true;
}

std::string Producto::getName(){
    return name;
}

int Producto::getCantidad(){
    return cantidad;
}

int Producto::getId(){
    return id;
}

int Producto::idFunction(){
    static int id = 0;
    return id++;
}

void Producto::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

void Producto::setActive(bool active){
    this->active = active;
}