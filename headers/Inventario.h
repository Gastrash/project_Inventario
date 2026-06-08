//Inventario.h

#pragma once
#include "../headers/Lista.h"
#include "../headers/Arbol.h"
#include "../headers/Producto.h"

class Inventario{
    private:
        Lista lista;
        Arbol arbol;
        
        Lista::Nodo* actual = nullptr;

    public:
        void run();
        void pushProducto();
        void popProducto(int id);
        Producto* buscarProducto(int id);
        void listaProducto();
};