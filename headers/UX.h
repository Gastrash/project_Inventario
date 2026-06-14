//UX.h

#include "../headers/Inventario.h"
#include "../headers/Producto.h"
#include <iostream>

class UX{
    private:
        std::string release = "release 1.0";
        
        enum state{
            MENU,
            PUSH,
            POP,
            BUSCAR,
            LISTA,
            PRODUCTO,
            SALIR
        };
        
        state estado = MENU;
        Inventario inventario;
        
        bool render();
        void startMenu();
        void pushMenu();
        void popMenu();
        void buscarMenu();
        void listaMenu();
        void productoMenu(Producto* P);
    public:
        void run();
};