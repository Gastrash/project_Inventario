//Arbol.cpp

#include "Arbol.h"

void Arbol::Insertar(Lista::Nodo* nodo){

    Nodo_Arbol* nuevo = new Nodo_Arbol();
    nuevo->nodo = nodo;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;

    if(raiz == nullptr){
        raiz = nuevo;
        return;
    }

    Nodo_Arbol* actual = raiz;
    Nodo_Arbol* padre = nullptr;
    int id_nuevo = nodo->P.getId();
    
    while(actual){
        padre = actual;
        int id_actual = actual->nodo->P.getId();

        if(id_nuevo < id_actual) actual = actual->izq;

        else actual = actual->der;
    }
    
    if(id_nuevo < padre->nodo->P.getId()) padre->izq = nuevo;
    else padre->der = nuevo;
}


void Arbol::Pop(int id){
// Implementation for removing node with given id from the tree
}

Nodo_Arbol* Arbol::BuscarNodoArbol(int id){
    Nodo_Arbol* actual = raiz;

    while(actual){
        int id_actual = actual->nodo->P.getId();

        if(id == id_actual) return actual;

        else if(id < id_actual) actual = actual->izq;

        else actual = actual->der;
    }
    return nullptr;
}

Lista::Nodo* Arbol::BuscarNodo(int id){
    Nodo_Arbol* arbol = BuscarNodoArbol(id);
    return arbol->nodo;
}