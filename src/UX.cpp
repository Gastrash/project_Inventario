//UX.cpp

#include "../headers/UX.h"

using namespace std;

//main

void UX::run(){
    startMenu();
}

//funciones principales

void UX::startMenu(){
    cout<<"Iniciando Inventario..";
    sleep(1);
    limpiarPantalla();

    cout<<"Inventario         "<<release<<"\n\n";
    cout<<"-------------------------------\n\n\n";
    cout<<"0 . Nuevo Producto\n\n";
    cout<<"1 . Ver Productos\n\n";
    cout<<"2 . Buscar Producto\n\n";
    cout<<"3 . Lista de Productos\n\n";
    cout<<"4 . Salir\n\n";
    cout<<"--------------------------------\n\n";
}

void UX::pushMenu(){

}

void UX::popMenu(){

}

void UX::buscarMenu(){

}

void UX::listaMenu(){

}

void UX::productoMenu(){

}

//funciones secundarias

void UX::limpiarPantalla(){

}

void sleep(int i){

}