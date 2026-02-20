//Lista.h

class Lista{
    private:
        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;
        };
        Nodo* Cabeza;

    public:
        void Push(const Producto &P);
        void Pop();
};