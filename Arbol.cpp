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
    Nodo_Arbol* actual = raiz;
    Nodo_Arbol* padre = nullptr;

    while(actual){
        int id_actual = actual->nodo->P.getId();

        if(id == id_actual) break;
        padre = actual;
        if(id < id_actual) actual = actual->izq;
        else actual = actual->der;
    }

    if(actual == nullptr) return;

    /*if(padre == nullptr){ //raiz
        raiz = nullptr;
        return;
    }*/

    if(actual->der == nullptr && actual->izq == nullptr){ //hoja
        if(padre->izq == actual) padre->izq = nullptr;
        else padre->der = nullptr;
        delete actual;
    }

    else if(actual->der == nullptr || actual->izq == nullptr){ //un hijo
        if(actual->izq){
            if(padre->izq == actual) padre->izq = actual->izq;
            else padre->der = actual->izq;
            delete actual;
        }
        else{
            if(padre->izq == actual) padre->izq = actual->der;
            else padre->der = actual->der;
            delete actual;
        }
    }

    else if((actual->der) && (actual->izq)){ //dos hijos
        padre->izq = actual->izq;
        padre->der = actual->der;
        delete actual;
    }
}

Arbol::Nodo_Arbol* Arbol::BuscarNodoArbol(int id){
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
    if(arbol == nullptr) return nullptr;
    return arbol->nodo;
}