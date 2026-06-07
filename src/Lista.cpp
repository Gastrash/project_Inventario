//Lista.cpp

#include "../headers/Lista.h"
#include "../headers/Producto.h"

using namespace std;

Lista::Nodo* Lista::Push(){
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;
    nuevo_nodo->P = Pr;

    if(!Cabeza){
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;

        Ultimo_nodo = nuevo_nodo;
        Cabeza = nuevo_nodo;  

        return nuevo_nodo;
    }  

    Ultimo_nodo->siguiente = nuevo_nodo;  
    nuevo_nodo->anterior = Ultimo_nodo;  
    nuevo_nodo->siguiente = Cabeza;
    Cabeza->anterior = nuevo_nodo;  

    Ultimo_nodo = nuevo_nodo;

    return nuevo_nodo;
}

void Lista::Pop(Nodo* borrar){
    if(!borrar) return;
    
    Nodo* anterior = borrar->anterior;
    Nodo* siguiente = borrar->siguiente;

    if(Cabeza == borrar && Ultimo_nodo == borrar){  
        delete borrar;  
        Cabeza = nullptr;  
        Ultimo_nodo = nullptr;  
        return;  
}

    if(Cabeza == borrar){  

        Cabeza = Cabeza->siguiente;  
        Cabeza->anterior = Ultimo_nodo;  
        Ultimo_nodo->siguiente = Cabeza;

        delete borrar;
        return;
    }  

    if(Ultimo_nodo == borrar){  

        Ultimo_nodo = anterior;  
        Ultimo_nodo->siguiente = Cabeza;  
        Cabeza->anterior = Ultimo_nodo;  

        delete borrar;  
        return;  
    }

    siguiente->anterior = anterior;  
    anterior->siguiente = siguiente;  

    delete borrar;  
    return;
}

void Lista::borrarLista(){
    while(Cabeza){
        Pop(Cabeza);
    }
}

Lista::~Lista(){
    borrarLista();
}
