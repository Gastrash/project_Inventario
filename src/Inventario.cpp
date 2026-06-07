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

Lista::Nodo* Inventario::buscarProducto(int id){
    return arbol.buscarNodo(id);
}

void Inventario::listaProducto(){
    
}