//Lista.h

class Lista{
    private:

        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;
        };
        Nodo* Cabeza;
	Nodo* Ultimo_nodo;

    public:

        void Push(const Producto &P);

        void Pop(Nodo* borrar);
};
