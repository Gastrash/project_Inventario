#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<conio.h>
//#include<windows.h>

using namespace std;

//Base de datos

struct Productos{
    int id;
    string nombre;
    int cantidad;
    float precio;
    bool active=true;
    int índice = 0;
};

struct boludos{
    bool nombreB=false;
    bool cantidadB=false;
    bool precioB=false;
    bool idB=false;
    bool nuevo=false;
};

struct Estado{
    int totalproductos = 0;
    int índice = 0;
};

//Manipulación de inventario

void agregar(Productos P[], boludos& flags, Estado& actual);

void mostrar(Productos P[], bool band, int i);

bool menumostrar(Productos P[], Estado actual);

int buscar(Productos P[], Estado& actual);

bool modificar(Productos P[], boludos& flags, Estado actual);

bool venta(Productos P[], float& precio, int id, int cuanto);

//bool menuventa();

//  // 

void inicio();

void limpiarpantalla();

void pausa();

void limpiarbuffer();

int buscarSlot(Productos P[], Estado actual);

void pedirdatos(Productos P[], boludos& flags, Estado actual);

bool mostrartodo(Productos P[], Estado actual);

int generacionID(Productos P[], Estado actual);

bool comparacionID(Productos P[]);

bool Comparacion_String(Productos P[], Estado actual, string name);

void UX(int caso);

string Input_A(Productos* P, Estado actual);

//  //

void MenuPrincipal(Productos* P, boludos& flags, Estado& actual);

//  //

int main(){
    bool band = true;

    int max = 100;
    srand(time(nullptr));

    Productos* P = new Productos[max];
    boludos flags;
    Estado actual;

    inicio();

    MenuPrincipal(P, flags, actual);


    delete[] P;
    return 0;
}

void inicio(){
    UX(1);
    cin.ignore();
    cin.get();
}

void MenuPrincipal(Productos* P, boludos& flags, Estado& actual){

    do{
        limpiarpantalla();
        bool flag = false;
        int rta = 0;
        int i = 0;

        UX(2);

        cin>>rta;

        switch(rta){
            case 1 :

                limpiarpantalla();
                cout<<"Ha seleccionado la opción Agregar."<<endl;
                pausa();
                agregar(P, flags, actual);
                limpiarpantalla();
                cout<<"\nProducto agregado correctamente."<<endl;
                pausa();
                break;
            case 2 :

                limpiarpantalla();
                cout<<"Ha seleccionado la opción Mostrar"<<endl;
                pausa();
                flag = mostrartodo(P, actual);
                if(!flag) menumostrar(P, actual);
                pausa();
                break;
            case 3 :

                limpiarpantalla();
                cout<<"Ha seleccionado la opción Modificar"<<endl;
                pausa();
                limpiarpantalla();
                flag = modificar(P, flags, actual);
                if(flag) pedirdatos(P, flags, actual);
                pausa();
                break;
            case 4 :

                limpiarpantalla();
                cout<<"Ha seleccionado la opción Venta"<<endl;
                pausa();
                menuventa();
                pausa();
                    break;
            case 5 :

                limpiarpantalla();
                band = false;
                break;
            default:
                limpiarpantalla();
                UX(11);
            }
        }while(band);    
    }
}

void agregar(Productos P[], boludos& flags, Estado& actual){
    limpiarpantalla();
    actual.indice = buscarSlot(P);
    if(pos == -1){
        pos = actual.totalproductos;

        P[pos] > totalproductos++;

        actual.indice = pos;
        P[pos].active = true;
    }
    UX(3);
    cin.get();

    flags.nombreB=true;
    flags.cantidadB=true;
    flags.precioB=true;
    flags.idB=true;
    flags.nuevo=true;

    pedirdatos(P, flags, pos, totalproductos);
}

int buscarSlot(Productos P[], Estado actual){
    for(int i = 0; i < actual.totalproductos; i++){
        if (!P[i].active){
            return i;
        }

    }
    return -1;
}

void pedirdatos(Productos P[], boludos& flags, Estado actual){
    indice = actual.indice;

    string name,  estring;

    bool h = false;

    if(flags.idB){
        P[actual.indice].id = generacionID(P);
        flags.idB=false;
        h=true;
    }
    if(flags.nombre){
        do{
            if(flags.nuevo){
                cout<<"\nID:["<<P[actual.indice].id<<"]."<<endl;
                cout<<"\n\nNombre del Producto: ";
                getline(cin, P[actual.indice].nombre);//input()
                estring = P[actual.indice].nombre;
            }
            else{
                cout<<"\nModificar nombre del Producto id:[";
                cout<<P[actual.indice].id<<"].";
                cout<<"\n\nAntes:["<<P[actual.indice].nombre <<"]\nAhora: ";
                getline(cin, P[actual.indice].nombre); //input()
                estring = P[actual.indice].nombre;
            }
        }while(!comparacionstring(P, actual, estring));
        flags.nombre=false;
        h = true;
    }       
    if(flags.cantidad){
        if(flags.nuevo){
            cout<<"\nCantidad inicial del nuevo producto: ";
            cin>>P[actual.indice].cantidad;
        }
        else{
            cout<<"\nModificar cantidad de '"<<P[actual.indice].nombre<<"'";
            cout<<"\nid:["<<P[actual.indice].id<<"].";
            cout<<"\n\nAntes:["<<P[actual.indice].cantidad<<"]\nAhora: ";
            cin>>P[actual.indice].cantidad;
        }
        flags.cantidad=false;
        h=true;
    }
    if(flags.precioB){
        if(flags.nuevo){
            cout<<"\nPrecio del nuevo producto: ";
            cin>>P[actual.indice].precio;
        }
        else{
            cout<<"\nModificar Precio de '";
            cout<<P[actual.indice].nombre<<"'";
            cout<<"\nid:["<<P[actual.indice].id<<"].";
            cout<<"\n\nAntes:["<<P[actual.indice].precio<<"]\nAhora: ";
            cin>>P[actual.indice].precio;
        }
        flags.precioB=false;
        h=true;
    }
    flags.nuevo=false;
    if(h==false){
        limpiarpantalla();
        cout<<"ERROR: pedirdatos() no recibió datos."<<endl;
    }
}

bool Comparacion_String(Productos P[100], Estado actual, string name){

    for(int i=0; i< actual.totalproductos; i++){
        if(i == actual.indice) continue;

        if(P[i].active && P[i].nombre == name){
            UX(6);
            return false;
        }
    }
    return true;
}

int generacionID(Productos P[], Estado actual){
    int valorrand = 0;
    do{
        valorrand = 1000 + rand() % 9000;
    }while(comparacionID(P, actual.totalproductos, valorrand));
    return valorrand;
}

bool comparacionID(Productos P[], string name){
    bool repetido = false;

    for (int i = 0; i < actual.totalproductos; i++){
        if (P[i].id == id && P[i].active) {
        repetido = true;
        break;
        }
    }
    return repetido;
}

bool modificar(Productos P[], boludos& flags){

    bool band = false;
    bool flag = false;
    string name;

    do{
        limpiarpantalla();

        indice = buscar(P, actual);

    }while(!band);

    while(true){

        mostrar(P, true, indice, 1);

        cout<<" 0 . Nombre."; if(flags.nombreB) cout<<" <<";
        cout<<"\n\n 1 . Cantidad."; if(flags.cantidadB) cout<<" <<";
        cout<<"\n\n 2 . Precio."; if(flags.preciosB) cout<<" <<";
        cout<<"\n\n 3 . ID."; if(flags.idB) cout<<" <<";
        cout<<"\n\n 4 . Cancelar.\n\n"; 

        if(flag) cout<<"\n 5 . Modificar.\n\n";

        char a = _getch();

        switch(a){
            case '0' :
                flags.nombreB = true;
                flag = true;
                break;
            case '1' :
                flags.cantidadB = true;
                flag = true;
                break;
            case '2' :
                flags.precioB = true;
                flag = true;
                break;
            case '3' :
                flags.idB = true;
                flag = true;
                break;
            case '4' :
                return false;
            case '5' :
                return true;
            default:
                break;
        }
        limpiarpantalla();
    }
}


/*
bool menuventa(){
    limpiarpantalla();
    
    if(cuanto > 0 && cuanto <= P[i].cantidad){
        
    }
}
*/


bool venta(Productos P[], Estado actual, string id, int cuanto){
    float plata = 0;

    for(int i=0; i< actual.totalproductos; i++){
        if((P[i].id == id) && (P[i].active) && (P[i].cantidad > 0)){

            P[i].cantidad -= cuanto;
            plata += P[i].precio * cuanto;

            if(cuanto == 1){
                cout<<cuanto<<" Producto [id:"<<id<<"] vendido.";
            }
            else{
                cout<<cuanto<<" Productos [id:"<<id<<"] vendidos.";
            }
            if(P[i].cantidad == 0){
                P[i].active = false;
                cout<<"\n\nEl Producto "<<P[i].nombre<<" se ha acabado,";
                cout<<"\nha sido Eliminado del sistema.";
            }
            cout<<"\n$ "<<(P[i].precio*cuanto)<<" +"<<endl;
            return true;
        }
    }
    return false; 
}

bool menumostrar(Productos P[], Estado actual){
    limpiarpantalla();

    int j = 0, id;
    string name;
    bool flag = false;
    bool band = false;

    cout<<"Por favor, ID o Nombre del Producto:\n\n"<<endl;
    getline(cin, name);

    flag = buscar(P, band, name, actual.totalproductos, j);

    if(flag){
        limpiarpantalla();
        mostrar(P, band, actual, 0);
        return true;
    }
    else{
        if(band){
            cout<<"--> ID:["<<stoi(name)<<"] No encontrado.\n"<<endl;
        }
        else{
            cout<<"--> "<<name<<" No encontrado.\n"<<endl;
        }
        pausa();
        return false;
    }
}

int buscar(Productos P[], Estado actual){

    string name = Input_A(P, actual);

    for(int i=0; i< actual.totalproductos; i++){
        if(!P[i].active) continue;
        if(P[i].nombre == name){
            return i;
        }
        else if(P[i].id == name){
            return i;
        }
    }

    return -1;
}

void mostrar(Productos P[], int i){
    UX(i);
}

string Input_A(Productos* P, Estado actual){
    limpiarbuffer();

    bool band = false;
    do{
        //Sleep(250);
        cout<<"Nombre o ID del Producto\n\n\n";
        if(band) cout<<"Ya Existe:: (Vuelva a ingresar):\n\n";
        if(band) cout<<"Q . Quit:\n\n\n";

        getline(cin, name);

        if(name == "Q") break;

        band = true;

    }while(Comparacion_String(P, actual, name));
    return name;
}

bool mostrartodo(Productos P[]){
    int num = 0;
    int rta = 0, rta2 = 0;
    int limite = 1;
    string a;

    //input opciones impresion n°8

    UX(8);

    cin>>rta;
    limpiarbuffer();

    if(rta == 0){
        return false;
    }
    if(rta == 1){

        num = 0;

        while(true){
            limpiarpantalla();
            if(P[num].active){

                mostrar(P, 16);

                if(num > 0) cout<<"\n\n\n\n Anterior: [A]";
                if(num < actual.totalproductos - limite) cout<<"\n\n Siguiente: [D]";
                cout<<"\n\n Salir: [Q]";
                while(true){
                    getline(cin, a);
                    if(a == "A" && num > 0){
                        num--;
                        break;
                    }
                    if(a == "D" && num < actual.totalproductos - limite){
                        num++;
                        break;
                    }
                    if(a == "Q"){
                        limpiarpantalla();

                        UX(7);
                        while(true){
                            cin>>rta2;
                            if(rta2 == 1){
                                pausa();
                                return true;
                            }
                            else if(rta2 == 0){
                                break;
                            }
                            else{

                            }
                        }
                        limpiarbuffer();
                        if(rta2 == 0) break;
                    }

                }
            }
            else{
                if(num < totalproductos - limite){
                    num++;
                }    
                else if(num == totalproductos - limite){
                    limpiarpantalla();

                    UX(16);

                    cin.get();

                    limite++;
                    num--;
                }

            }

        }

    }
}

void limpiarpantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limpiarbuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void pausa(){
    cout << "\nPresione Enter para continuar...";
    limpiarbuffer();
    cin.get();
}

void UX(int caso){
    switch(caso){

        case 1 :
            cout<<"\n\n\n\nBienvenido\n"<<endl;
            cout<<"Enter para iniciar:\n\n"<<endl;
        case 2 :
            //Main Menu
            cout<<"Main menú.\n\n"<<endl;
            cout<<"1 . Agregar."<<endl;
            cout<<"2 . Mostrar."<<endl;
            cout<<"3 . Modificar.   "<<endl;
            cout<<"4 . Venta.   X\n\n"<<endl;
            cout<<"5 . Salir.\n\n";
        case 3 :
            cout<<"Producto creado, coloque sus datos:\n\n";
        //case 4 :

        case 6 :
            cout<<"'"<<P[i].nombre<<"' Ya existe.";
            cout<<"\nPor Favor, Introduzca nuevo nombre.";
        case 7 :
            cout<<"¿Seguro que quiere volver al Menu Principal?\n\n";
            cout<<" 1 . Salir.\n\n";
            cout<<"0 . Cancelar.\n\n";
        case 8 :
            cout<<"   ¿  ?";
            cout<<"\n\n [0] . Mostrar Uno\n\n";
            cout<<" [1] . Mostrar Todos\n\n";
        case 9 :
            limpiarpantalla();
            cout<<"Este Producto fue eliminado.\n"<<endl;
            cout << "Presione Enter para volver al Anterior...";
            pausa();
        //case 10 :

        case 11 :
            limpiarpantalla();
            cout<<"Respuesta invalida\n\n";
            cout<<"ingrese nuevamente\n\n";
            cin.get();
        //case 13 :

        //case 15 :

        case 16 :
            cout<<"::::::::::::::::::::::::::::::::::::::::::\n\n";
            cout<<"\n\nNombre: "<<P[actual.indice].nombre<<"."<<endl;
            cout<<"\nID: ["<<P[actual.indice].id<<"]."<<endl;
            cout<<"\nCantidad: "<<P[actual.indice].cantidad<<"."<<endl;
            cout<<"\nPrecio: "<<P[actual.indice].precio<<"."<<endl;
            cout<<"\n\n::::::::::::::::::::::::::::::::::::::::::";
        case 17 :
            cout<<"[Búsqueda por ID]\n";
            cout<<"\nID: ["<<P[actual.indice].id<<"]."<<endl;
            cout<<"\n\nNombre: "<<P[actual.indice].nombre<<"."<<endl;
            cout<<"\nCantidad: "<<P[actual.indice].cantidad<<"."<<endl;
            cout<<"\nPrecio: "<<P[actual.indice].precio<<"."<<endl;
        case 18 :
            cout<<"[Búsqueda por Nombre]\n";
            cout<<"\n\nNombre: "<<P[actual.indice].nombre<<"."<<endl;
            cout<<"\nID: ["<<P[actual.indice].id<<"]."<<endl;
            cout<<"\nCantidad: "<<P[actual.indice].cantidad<<"."<<endl;
            cout<<"\nPrecio: "<<P[actual.indice].precio<<"."<<endl;
            cin.get();
            break;
        //case 19 :   

    }
}

/*
ofstream file("inventario.txt");

for(int i = 0; i < totalproductos; i++){
    if(P[i].active){
        file << P[i].id << "|"
             << P[i].nombre << "|"
             << P[i].cantidad << "|"
             << P[i].precio << "|"
             << P[i].active << "\n";
    }
}
file.close();
/*