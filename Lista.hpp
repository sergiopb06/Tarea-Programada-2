#ifndef LISTA_HPP
#define LISTA_HPP

#include "Nodo.hpp"


template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

public:

    Lista();               
    ~Lista();

    void agregarInicio(const T& dato);
    Nodo<T>* getCabeza() const;
    
};

#include "Lista.tpp"  

#endif //LISTA_HPP