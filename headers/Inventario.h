//Inventario.h

#pragma once
#include "../headers/Lista.h"
#include "../headers/Arbol.h"
#include "../headers/Producto.h"
#include <string>

class Inventario{
    private:
        Lista lista;
        Arbol arbol;
        
        Lista::Nodo* actual = nullptr;

    public:
        void pushProducto(std::string name, int stock);
        void popProducto(int id);
        Producto* buscarProducto(int id);
        void modificar(int id, std::string name);
        void modificar(int id, int stock);
        void listaProducto();
};