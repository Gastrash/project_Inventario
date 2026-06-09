//Producto.h

#pragma once
#include <string>

class Producto {
    private:
        std::string name;  
        int stock;  
        int id;
        bool active;

    public:
        Producto(std::string name, int stock);  
        std::string getName();
        int getStock();  
        int getId();  
        int idFunction();  
        void setStock(int stock);
        void setName(std::string name);
        void setActive(bool active);

};