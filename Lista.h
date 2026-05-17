//Lista.h

class Lista{
    private:
        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;
        };
        Nodo* Cabeza = nullptr;
	       Nodo* Ultimo_nodo = nullptr;

    public:

        void Push(Nodo* Cabeza, Nodo* Ultimo_nodo, const Producto&);

        void Pop(Nodo* Cabeza, Nodo* Ultimo_nodo, Nodo* borrar);
};