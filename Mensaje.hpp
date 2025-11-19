#ifndef MENSAJE_HPP
#define MENSAJE_HPP
#include "Palabra.hpp"
#include "Nodo.hpp"
//AQUI SE LEE MENSAJE.TXT Y SE GUARDA
//SE IMPLEMENTA LA LISTA ENLAZADA QUE GUARDE LAS PALABRAS ENCONTRADAS Y LUEGO SE LO MANDA AL ANALIZADOR


class Mensaje {
    private:
        char* frase;          
        Nodo<char*>* cabeza;

    public:
        Mensaje(const char* f);
        ~Mensaje();

        void separadorPalabras();
        char* getFrase() const;
        Nodo<char*>* getCabeza() const;
};

#endif //MENSAJE_HPP