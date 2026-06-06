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

        Nodo_Arbol* BuscarNodoArbol(int id);
        void borrarArbol();
        
    public:
        void Insertar(Lista::Nodo* nodo);
        void Pop(int id);
        Lista::Nodo* BuscarNodo(int id);
        ~Arbol();
};