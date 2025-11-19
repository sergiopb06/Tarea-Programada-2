#include "Mensaje.hpp"

Mensaje::Mensaje() : cabeza(nullptr) {}

Mensaje::~Mensaje() {
    Nodo<Palabra>* actual = cabeza;
    while (actual) {
        Nodo<Palabra>* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void Mensaje::agregarPalabra(const Palabra& p) {

    Nodo<Palabra>* nuevo = new Nodo<Palabra>(p);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

Palabra* Mensaje::buscar(const char* texto) {
    Nodo<Palabra>* actual = cabeza;
    while (actual) {
        if (Palabra::comparar(actual->dato.getPalabra(), texto)){
            return &(actual->dato);
        }
        
        actual = actual->siguiente;
    }

    return nullptr;
}


Nodo<Palabra>*  Mensaje::getCabeza() const{
    return cabeza;
}