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

        Lista();

        void Push(const Producto&);

        void Pop(Nodo* borrar);
};