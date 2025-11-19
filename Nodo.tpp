#include "Nodo.hpp"

template <typename T>
Nodo<T>::Nodo(const T& p) : dato(p) {
        this->siguiente = nullptr;
    }