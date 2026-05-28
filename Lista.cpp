//Lista.cpp

#include "Lista.h"
#include "Producto.h"
#include "Arbol.h"

using namespace std;

void Lista::Push(const Producto &Pr){
this->Cabeza;
this->Ultimo_nodo;

Nodo* nuevo_nodo = new Nodo();  
    nuevo_nodo->P = Pr;  

    if(!Cabeza){  
    nuevo_nodo->siguiente = nuevo_nodo;  
    nuevo_nodo->anterior = nuevo_nodo;  

            Ultimo_nodo = nuevo_nodo;  
            Cabeza = nuevo_nodo;  

            Arbol::Insertar(Ultimo_nodo);  
            return;  
}  

    Ultimo_nodo->siguiente = nuevo_nodo;  
    nuevo_nodo->anterior = Ultimo_nodo;  
    nuevo_nodo->siguiente = Cabeza;  
    Cabeza->anterior = nuevo_nodo;  

    Ultimo_nodo = nuevo_nodo;  

    Arbol::Insertar(Ultimo_nodo);

}

void Lista::Pop(Nodo* borrar){
if(!borrar) return;

Nodo* Cabeza = this->Cabeza;  
    Nodo* Ultimo_nodo = this->Ultimo_nodo;  

    int id = borrar->P.getId();  

    if(Cabeza == borrar && Ultimo_nodo == borrar){  

            Arbol::Pop(id);  
            delete borrar;  
            Cabeza = nullptr;  
            Ultimo_nodo = nullptr;  
            return;  
}  

    if(Cabeza == borrar){  

            Cabeza = Cabeza->siguiente;  
            Cabeza->anterior = Ultimo_nodo;  
            Ultimo_nodo->siguiente = Cabeza;  

            Arbol::Pop(id);  
            delete borrar;  
            return;  
    }  

    if(Ultimo_nodo == borrar){  

            Ultimo_nodo = Ultimo_nodo->anterior;  
            Ultimo_nodo->siguiente = Cabeza;  
            Cabeza->anterior = Ultimo_nodo;  

            Arbol::Pop(id);  
            delete borrar;  
            return;  
    }  

    Nodo* aux1 = borrar->siguiente;  
    Nodo* aux2 = borrar->anterior;  

    aux1->anterior = aux2;  
    aux2->siguiente = aux1;  

    Arbol::Pop(id);  
    delete borrar;  
    return;

}