//Lista.cpp

#include "Lista.h"
#include "Producto.h"
#include "Arbol.h"

using namespace std;

void Lista::Push(const Producto &Pr){
    Arbol arbol;

    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;
    nuevo_nodo->P = Pr;  

    if(!Cabeza){
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;

        Ultimo_nodo = nuevo_nodo;  
        Cabeza = nuevo_nodo;  

        arbol.Insertar(Ultimo_nodo);  
        return;  
    }  

    Ultimo_nodo->siguiente = nuevo_nodo;  
    nuevo_nodo->anterior = Ultimo_nodo;  
    nuevo_nodo->siguiente = Cabeza;
    Cabeza->anterior = nuevo_nodo;  

    Ultimo_nodo = nuevo_nodo;  

    arbol.Insertar(Ultimo_nodo);

}

void Lista::Pop(Nodo* borrar){
    if(!borrar) return;

    this->Cabeza;
    this->Ultimo_nodo;
    
    Arbol arbol;
    
    Nodo* anterior = borrar->anterior;
    Nodo* siguiente = borrar->siguiente;
    int id = borrar->P.getId();  

    if(Cabeza == borrar && Ultimo_nodo == borrar){  

        arbol.Pop(id);  
        delete borrar;  
        Cabeza = nullptr;  
        Ultimo_nodo = nullptr;  
        return;  
}

    if(Cabeza == borrar){  

        Cabeza = Cabeza->siguiente;  
        Cabeza->anterior = Ultimo_nodo;  
        Ultimo_nodo->siguiente = Cabeza;  

        arbol.Pop(id);
        delete borrar;  
        return;  
    }  

    if(Ultimo_nodo == borrar){  

        Ultimo_nodo = anterior;  
        Ultimo_nodo->siguiente = Cabeza;  
        Cabeza->anterior = Ultimo_nodo;  

        arbol.Pop(id);  
        delete borrar;  
        return;  
    }

    siguiente->anterior = anterior;  
    anterior->siguiente = siguiente;  

    arbol.Pop(id);  
    delete borrar;  
    return;
}