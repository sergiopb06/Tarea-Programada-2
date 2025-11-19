#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP
#include "Nodo.hpp"
#include "Palabra.hpp"
#include "Mensaje.hpp"

//ANALIZA LA FRASE CON AYUDA DE MENSAJE Y PALABRA
//AYUDA A DEFINIR LAS PALABRAS
//CALCULA TODOS LOS RESULTADOS


class Analizador {
private:
    Nodo<Palabra>* vocabulario; 

public:
    Analizador();
    ~Analizador();

    
    void cargarPalabras(const char* nombreArchivo);
};

#endif // ANALIZADOR_HPP