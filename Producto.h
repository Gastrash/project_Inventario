//Producto.h

#pragma once
#include <string>

class Producto {
private:

std::string name;  
int cantidad;  
int id;  
bool vacio;  
bool active;

public:

Producto(std::string name, int cantidad);  

std::string Producto::getName();  
int Producto::getCantidad();  
int Producto::getId();  
int Producto::idFunction();  
void Producto::setCantidad(int cantidad);  
void Producto::setActive(bool active);

};