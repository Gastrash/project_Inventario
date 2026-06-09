//UX.h

#include "../headers/Inventario.h"
#include "../headers/Producto.h"
#include <iostream>

class UX{
    private:
        std::string release = "release 1.0";

        void startMenu();
        void pushMenu();
        void popMenu();
        void buscarMenu();
        void listaMenu();
        void productoMenu();
        void limpiarPantalla();
    public:
        void run();
};