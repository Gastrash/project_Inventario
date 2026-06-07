//Inventario.h

#pragma once
#include "../headers/Lista.h"
#include "../headers/Arbol.h"

class Inventario{
    private:
        Lista lista;
        Arbol Arbol;

    public:
        void run();
        void pushProducto();
        void popProducto();
        void buscarProducto();
        void listaProducto();
};