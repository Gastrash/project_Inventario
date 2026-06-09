//Arbol.h

#pragma once
#include "../headers/Lista.h"
#include "../headers/Producto.h"

class Arbol{
    private:
        struct Nodo_Arbol{
            Lista::Nodo* nodo;
            Nodo_Arbol* izq;
            Nodo_Arbol* der;
        };
        Nodo_Arbol* raiz = nullptr;

        Nodo_Arbol* buscarNodoArbol(int id);
        void borrarArbol(Nodo_Arbol* nodo);
        
    public:
        Arbol();
        void push(Lista::Nodo* nodo);
        void pop(int id);
        Lista::Nodo* buscarNodo(int id);
        ~Arbol();
};