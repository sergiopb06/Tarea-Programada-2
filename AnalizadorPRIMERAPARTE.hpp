#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP

#include "Palabra.hpp"
#include "Mensaje.hpp"
#include "Lista.hpp"

//ANALIZA LA FRASE CON AYUDA DE MENSAJE Y PALABRA
//AYUDA A DEFINIR LAS PALABRAS
//CALCULA TODOS LOS RESULTADOS


class Analizador {
private:
    Lista<Palabra> vocabulario; 

public:
    Analizador();
    ~Analizador();

    
    void cargarPalabras(const char* nombreArchivo);

    Palabra* buscarEnVocabulario (const char* texto) const;

    int analizarFrase (Mensaje& m);

    const char* calcularSentimiento(int puntaje) const;

    int leerMensajes(const char* nombreArchivo, char frases[][200], int maxFrases);
};

#endif // ANALIZADOR_HPP