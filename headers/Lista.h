//Lista.h

#pragma once
#include "../headers/Producto.h"

class Lista {

    public: 
        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;
        };
        
        Nodo* push();

        void pop(Nodo* borrar);

        ~Lista();
    
    private:
    
        Nodo* Cabeza = nullptr;  
        Nodo* Ultimo_nodo = nullptr;

        void borrarLista();
};