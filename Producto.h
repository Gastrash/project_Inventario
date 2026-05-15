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
    
    std::string getName();
    int getCantidad();
    int getId();
    
    void setCantidad(int cantidad);
    
    static int Random_id();
};