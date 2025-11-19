#ifndef MENSAJE_HPP
#define MENSAJE_HPP
#include "Palabra.hpp"
#include "Nodo.hpp"
//AQUI SE LEE MENSAJE.TXT Y SE GUARDA
//SE IMPLEMENTA LA LISTA ENLAZADA QUE GUARDE LAS PALABRAS ENCONTRADAS Y LUEGO SE LO MANDA AL ANALIZADOR


class Mensaje {
    private:
        Nodo<Palabra>* cabeza;

    public:
        Mensaje();
        ~Mensaje();

        void agregarPalabra(const Palabra& p);
        Palabra* buscar(const char* p);
        Nodo<Palabra>* getCabeza() const;
};

#endif //MENSAJE_HPP