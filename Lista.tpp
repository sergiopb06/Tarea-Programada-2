#include "Lista.hpp"


template <typename T>
Lista<T>::Lista() : cabeza(nullptr) {}



template <typename T>
Lista<T>::~Lista() {
    Nodo<T>* actual = cabeza;
    while (actual) {
        Nodo<T>* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}


template <typename T>
void Lista<T>::agregarInicio(const T& dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}


template <typename T>
Nodo<T>* Lista<T>::getCabeza() const {
    return cabeza;
}

