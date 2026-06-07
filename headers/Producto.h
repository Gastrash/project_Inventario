//Producto.h

#pragma once
#include <string>

class Producto {
private:

std::string name;  
int cantidad;  
int id;
bool active;

public:

Producto();  

std::string getName();
int getCantidad();  
int getId();  
int idFunction();  
void setCantidad(int cantidad);
void setName(std::string name);
void setActive(bool active);

};