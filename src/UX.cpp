//UX.cpp

#include "../headers/UX.h"
#include <thread>
#include <chrono>

using namespace std;

//main

void UX::run(){
    while(render()){}
}

//render

bool UX::render(){
    switch(estado){
        case MENU:
            startMenu();
            return true;
            break;
        case PUSH:
            pushMenu();
            return true;
            break;
        case POP:
            popMenu();
            return true;
            break;
        case BUSCAR:
            buscarMenu();
            return true;
            break;
        case LISTA:
            listaMenu();
            return true;
            break;
        case PRODUCTO:
            productoMenu();
            return true;
            break;
        case SALIR:
            return false;
            break;
    }
}

//funciones UX
/*
- void startMenu();
- void pushMenu();
- void popMenu();
- void buscarMenu();
- void listaMenu();
- void productoMenu(Producto* P);
*/

void UX::startMenu(){
    limpiarPantalla();
    cout<<"Iniciando Inventario..";
    sleepSeconds(1);
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
            break;
        case 1:
            estado = PRODUCTO;
            render();
            break;
        case 2:
            estado = BUSCAR;
            render();
            break;
        case 3:
            estado = LISTA;
            render();
            break;
        case 4:
            estado = SALIR;
            render();
    }
}

void UX::pushMenu(){ //
    cout<<"..";
    sleepSeconds(1);
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

void UX::productoMenu(Producto* P){ //
    if(P == nullptr){
        P = inventario.buscarProducto();
    }
}

//funciones Auxiliares
/*
- void limpiarPantalla();
- void sleepSeconds();
*/

void limpiarPantalla(){
    cout << "\033[2J\033[H";
}

void sleepSeconds(int i){
    std::this_thread::sleep_for(std::chrono::seconds(i));
}