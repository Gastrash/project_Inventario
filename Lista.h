//Lista.h

class Lista {

    public: 
        struct Nodo{
            Producto P;
            Nodo* siguiente;
            Nodo* anterior;
        };
        
        void Push(const Producto&);  

        void Pop(Nodo* borrar);

        ~Lista();
    
    private:
    
        Nodo* Cabeza = nullptr;  
        Nodo* Ultimo_nodo = nullptr;

        void borrarLista();
};