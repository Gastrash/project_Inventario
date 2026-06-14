//UX.cpp

#include "../headers/UX.h"
#include <thread>
#include <chrono>

using namespace std;

//main

void UX::run(){
    startMenu();
    
}

//funciones principales

void UX::render(){
    switch(estado){
        case MENU:
            startMenu();
            break;
        case PUSH:
            pushMenu();
            break;
        case POP:
            popMenu();
            break;
        case BUSCAR:
            buscarMenu();
            break;
        case LISTA:
            listaMenu();
            break;
        case PRODUCTO:
            productoMenu();
            break;
        case SALIR:
            salir();
            break;
    }
}

void UX::startMenu(){
    limpiarPantalla();
    cout<<"Iniciando Inventario..";
    sleep(1);
    limpiarPantalla();
    int i;

    cout<<"Inventario         "<<release<<"\n\n";
    cout<<"-------------------------------\n\n\n";
    cout<<"0 . Nuevo Producto\n\n";
    cout<<"1 . Ver Productos\n\n";
    cout<<"2 . Buscar Producto\n\n";
    cout<<"3 . Lista de Productos\n\n";    
    cout<<"4 . Salir\n\n";
    cout<<"--------------------------------\n\n";
    
    cin>>i;
    
    switch(i){
        case 0:
            estado = PUSH;
            render();
        case 1:
            estado = PRODUCTO;
            render();
        case 2:
            estado = BUSCAR;
            render();
        case 3:
            estado = LISTA;
            render();
        case 4:
            estado = SALIR;
            render();
    }
}

void UX::pushMenu(){
    cout<<"..";
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

void UX::popMenu(){

}

void UX::buscarMenu(){

}

void UX::listaMenu(){

}

void UX::productoMenu(Producto* P){
    if(P == nullptr){
        P = inventario.buscarProducto();
    }
}

void UX::salir(){
    
}

//funciones secundarias

void UX::limpiarPantalla(){
    cout << "\033[2J\033[H";
}

void sleep(int i){
    std::this_thread::sleep_for(std::chrono::seconds(i));
}