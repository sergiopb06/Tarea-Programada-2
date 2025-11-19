#ifndef NODO_HPP
#define NODO_HPP

template <typename T>
class Nodo {

public:
    T dato;
    Nodo* siguiente;
    Nodo(const T& p);
};

#include "Nodo.tpp"   

#endif //NODO_HPP