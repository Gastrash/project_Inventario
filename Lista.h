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

        Nodo 

        void Push(const Producto &P);

        void Pop(Nodo* borrar);
};
