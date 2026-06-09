//Lista.h

#pragma once
#include "../headers/Producto.h"
#include<string>

class Lista {

    public: 
        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;

            Nodo(std::string name, int stock);
        };
        
        Nodo* push(std::string name, int stock);
        void pop(Nodo* borrar);
        ~Lista();
    
    private:
    
        Nodo* Cabeza = nullptr;  
        Nodo* Ultimo_nodo = nullptr;

        void borrarLista();
};