//Producto.cpp

#include "../headers/Producto.h"

Producto::Producto(std::string name, int stock){
    this->name = name;
    this->stock = stock;
    this->id = idFunction();
    this->active = true;
}

std::string Producto::getName(){
    return name;
}

int Producto::getStock(){
    return stock;
}

int Producto::getId(){
    return id;
}

int Producto::idFunction(){
    static int id = 0;
    return id++;
}

void Producto::setStock(int stock){
    this->stock = stock;
}

void Producto::setName(std::string name){
    this->name = name;
}

void Producto::setActive(bool active){
    this->active = active;
}