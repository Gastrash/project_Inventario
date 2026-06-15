//UX.cpp

#include "../headers/UX.h"
#include <thread>
#include <chrono>

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
            productosMenu();
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
    std::cout<<"Iniciando Inventario..";
    sleepSeconds(1);
    limpiarPantalla();
    int i;

    std::cout<<"Inventario         "<<release<<"\n\n";
    std::cout<<"-------------------------------\n\n\n";
    std::cout<<"0 . Nuevo Producto\n\n";
    std::cout<<"1 . Ver Productos\n\n";
    std::cout<<"2 . Buscar Producto\n\n";
    std::cout<<"3 . Lista de Productos\n\n";    
    std::cout<<"4 . Salir\n\n";
    std::cout<<"--------------------------------\n\n";
    
    std::cin>>i;
    
    switch(i){
        case 0:
            estado = PUSH;
            break;
        case 1:
            estado = PRODUCTO;
            break;
        case 2:
            estado = BUSCAR;
            break;
        case 3:
            estado = LISTA;
            break;
        case 4:
            estado = SALIR;
            break;
    }
}

void UX::pushMenu(){ //
    limpiarPantalla();
    std::string name;
    int stock;

    std::cout<<"Agregar Producto                   ::";
    std::cout<<"-------------------------------\n\n";
    std::cout<<"Nombre:\n\n";
    std::cout<<"--------------------------------\n\n";
    std::cin.ignore();
    getline(cin, name);
    std::cout<<"Stock:\n\n";
    std::cout<<"--------------------------------\n\n";
    std::cin>>stock;
    
    limpiarPantalla();
    std::cout<<"-------------------------------\n\n";
    std::cout<<"Producto Agregado\n\n";
    std::cout<<"Nombre: "<<name<<".\n\n";
    std::cout<<"Stock: "<<stock<<".\n\n";
    std::cout<<"Confirmar? [Y/N]";
    std::cout<<"-------------------------------\n\n";
    
    if(yesOrNo()){
        inventario.pushProducto(name, stock);
        limpiarPantalla();
        std::cout<<"-------------------------------\n\n";
        std::cout<<"Producto agregado correctamente.\n\n";
        std::cout<<"-------------------------------\n\n";
        waitEnter();
    }
    else{
        std::cout<<"-------------------------------\n\n";
        std::cout<<"Proceso cancelado.\n\n";
        std::cout<<"-------------------------------\n\n";
        waitEnter();
    }
    estado = MENU;
}

void UX::popMenu(){

}

void UX::buscarMenu(){

}

void UX::listaMenu(){

}

void UX::productosMenu(){//
    //recorrido de la lista con función inventario
}

void UX::pMenu(){ //
    std::cout<<"-------------------------------\n\n";
    std::cout<<"Nombre: <<P.getName()<<".\n\n";
    std::cout<<"-------------------------------\n\n";
    std::cout<<"Stock: <<P.getStock<<".\n\n";
    std::cout<<"Id: <<P.getId<<".\n\n";
    std::cout<<"-------------------------------\n\n";
}

//funciones Auxiliares
/*
- void limpiarPantalla();
- void sleepSeconds();
*/

void limpiarPantalla(){
    std::cout<"\033[2J\033[H";
}

void sleepSeconds(int i){
    std::this_thread::sleep_for(std::chrono::seconds(i));
}

bool yesOrNo(){
    char answer;
    while(true){
        cin>>answer;
        switch(answer){
            case 'Y':
                return true;
            case 'y':
                return true;
            case 'N':
                return false;
            case 'n':
                return false;
            default:
        }
    }
}

void waitEnter(){
    std::cout<<"Enter para continuar.\n\n";
    std::cin.get();
}