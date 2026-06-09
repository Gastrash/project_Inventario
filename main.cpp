//main.cpp

//#include "headers/Inventario.h"
//#include "headers/UX.h"
#include "headers/Arbol.h"
#include "headers/Lista.h"
//#include "headers/Producto.h"
#include <iostream>

int main(){

    Lista l;
    Arbol a;

    Lista::Nodo* Nodo1 = l.push("a", 5);
    a.push(Nodo1);
    Lista::Nodo* Nodo2 = l.push("a", 5);
    a.push(Nodo2);
    Lista::Nodo* Nodo3 = l.push("a", 5);
    a.push(Nodo3);

    std::cout<<"oa"<<std::endl;
    std::cin.get();

    return 0;
}