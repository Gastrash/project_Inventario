//Producto.cpp

#include "../headers/Producto.h"

Producto::Producto(){
    this->name = "";
    this->cantidad = 0;
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

void Producto::setName(std::string name){
    this->name = name;
}

void Producto::setActive(bool active){
    this->active = active;
}