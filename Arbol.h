//Arbol.h

#include "Lista.h"
#include "Producto.h"

class Arbol{
    private:
        struct Nodo_Arbol{
            Lista::Nodo* nodo;
            Nodo_Arbol* izq;
            Nodo_Arbol* der;
        };
        Nodo_Arbol* raiz = nullptr;
    public:
        void Insertar(Nodo* nodo);
        void Pop(int id);
        Lista::Nodo* Busqueda(int id);
};