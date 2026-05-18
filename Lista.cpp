#include <iostream>

#include "Lista.h"
#include "Producto.h"
#include "Arbol.h"

using namespace std;

void Lista::Push(const Producto &Pr){

	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->P = Pr;

	if(!Cabeza){
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;

		Ultimo_nodo = nuevo_nodo;
		Cabeza = nuevo_nodo;

		arbol::insertar(Ultimo_nodo);
		return;
        }

	Ultimo_nodo->siguiente = nuevo_nodo;
	nuevo_nodo->anterior = Ultimo_nodo;
	nuevo_nodo->siguiente = Cabeza;
	Cabeza->anterior = nuevo_nodo;

	Ultimo_nodo = nuevo_nodo;

	arbol::insertar(Ultimo_nodo);
}

void Lista::Pop(Nodo* borrar){
	if(!borrar) return false;

	int id = borrar->P.id;

	if(Cabeza == borrar && Ultimo_nodo == borrar){

		arbol::Pop(id);
		delete borrar;
		Cabeza = nullptr;
		Ultimo_nodo = nullptr;
		return true;
    }

	if(Cabeza == borrar){

		Cabeza = Cabeza->siguiente;
		Cabeza->anterior = Ultimo_nodo;
		Ultimo_nodo->siguiente = Cabeza;

		arbol::Pop(id);
		delete borrar;
		return true;
	}

	if(Ultimo_nodo == borrar){

		Ultimo_nodo = Ultimo_nodo->anterior;
		Ultimo_nodo->siguiente = Cabeza;

		arbol::Pop(id);
		delete borrar;
		return true;
	}

	Nodo* aux1 = borrar->siguiente;
	Nodo* aux2 = borrar->anterior;

	aux1->anterior = aux2;
	aux2->siguiente = aux1;

	arbol::Pop(id);
	delete borrar;
	return true;
}
