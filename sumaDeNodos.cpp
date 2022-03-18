#include <iostream>
using namespace std;

class cListaSimple {
private:
    class Nodo {
    public:
        int numero;
        Nodo* siguiente;
    };
    Nodo* lista;
public:
    void crearLista(int n);
    void print();
    void sumar();
};

void cListaSimple::print() {
    Nodo* aux;
    for (aux = lista; aux != NULL; aux = aux->siguiente) {
        cout << aux->numero << endl;
    }
}

void cListaSimple::sumar() {
    Nodo* aux;
    int res = 0;
    for (aux = lista; aux != NULL; aux = aux->siguiente) {
        res += aux->numero;
    }
    cout << "La suma de todos los valores de los nodos es:  " << res << endl;
}

void cListaSimple::crearLista(int n) {

    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->numero = n;

    Nodo* aux = lista;

    if (lista == NULL)
        lista = nuevoNodo;
    else {
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = nuevoNodo;
    }

    cout << "Elemento " << n << " insertado a lista correctamente a la lista \n";
}

int main() {

    cListaSimple* nuevaLista = new cListaSimple();
    int size, opcion;
    cout << "Cuantos elementos quieres en tu lista: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        int numero;
        cout << "Ingresa el numero: [ " << i << " ]: ";
        cin >> numero;
        nuevaLista->crearLista(numero);
        system("cls");
    }

    do {
        cout << "Que quieres hacer: \n(1) Para imprimir\n(2) Para sumar\n(3) Para salir\n: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            nuevaLista->print();
            break;
        case 2:
            nuevaLista->sumar();
            break;

        case 3:
            break;
        default:
            break;
        }
    } while (opcion != 3);

    return 0;
}

/*
class cLista {
public:
    int numero;
    cLista* siguiente;
    cLista* crearLista();
    void print(cLista*);
};

void cLista::print(cLista *lista) {
    cLista* aux = lista;
    while (lista!=NULL)
    {
        cout << lista->numero << endl;

        lista = lista->siguiente;
    }
}

cLista* cLista::crearLista(){
    cLista* lista = NULL, *aux = lista;
    int numero, size;
    cLista* nuevoNodo = new cLista();

    cout << "Dame el tama;o de la lista: " << endl;
    cin >> size;
    
    for (int i = 0; i < size; i++) {
    cout << "Dame el valor de la lista: ";
    cin >> numero;
    nuevoNodo->numero = numero;


    if (lista == NULL)
        lista = nuevoNodo;
    else {
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = nuevoNodo;
    }
    }



    return lista;
}

int main() {

    cLista* lista = new cLista();
    cLista* recuperarLista = lista->crearLista();
    lista->print(recuperarLista);


    return 0;
}*/
