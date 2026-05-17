//Arbol.h
#include "Lista.h"

class Arbol{
    private:
        struct Nodo_Arbol{
            Nodo* nodo;
	           Nodo_Arbol* izq;
	           Nodo_Arbol* der;
        };
        Nodo_Arbol* Raiz = nullptr;
    public:
        void Insertar(Nodo_Arbol* raiz, Nodo* nodo);
        void Eliminar(Nodo_Arbol* raiz, );
}
