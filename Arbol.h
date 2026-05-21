//Arbol.h

#include "Lista.h"
#include "Producto.h"

class Arbol{
    private:
        struct Nodo_Arbol{
            Nodo* nodo;
	        Nodo_Arbol* izq;
	        Nodo_Arbol* der;
        };
        Nodo_Arbol* Raiz = nullptr;
    public:
        void Arbol::Insertar(Nodo* nodo);
        void Arbol::Pop(int id);
        void Arbol::Busqueda(int id);
};