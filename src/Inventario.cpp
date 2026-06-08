//Inventario.cpp

#include "../headers/Inventario.h"

/*
void siguienteProducto();
void productoAnterior();
void mostrarProductoActual();
void borrarProductoActual();
*/

void Inventario::run(){

}

void Inventario::pushProducto(){
    Lista::Nodo* nuevo_nodo = lista.push();
    arbol.push(nuevo_nodo);
}

void Inventario::popProducto(int id){
    Lista::Nodo* borrar = arbol.buscarNodo(id);
    
    arbol.pop(id);
    lista.pop(borrar);
}

Producto* Inventario::buscarProducto(int id){
    Lista::Nodo* nodo = arbol.buscarNodo(id);
    if(nodo == nullptr) return nullptr;
    return &nodo->P;
}

void Inventario::listaProducto(){
    //devolver array de Productos en memoria
}