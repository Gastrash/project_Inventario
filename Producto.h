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

    Producto Constructor();
    static int Random_id();
};