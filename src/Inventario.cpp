//Inventario.cpp

#include "../headers/Inventario.h"

/*
void siguienteProducto();
void productoAnterior();
void mostrarProductoActual();
void borrarProductoActual();
*/

void Inventario::pushProducto(std::string name, int stock){
    Lista::Nodo* nuevo_nodo = lista.push(name, stock);
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

void Inventario::modificar(int id, std::string name){
    Producto* p = buscarProducto(id);
    if(!p) return;

    p->setName(name);
}

void Inventario::modificar(int id, int stock){
    Producto* p = buscarProducto(id);
    if(!p) return;

    p->setStock(stock);
}

void Inventario::listaProducto(){
    //devolver array de Productos en memoria
}