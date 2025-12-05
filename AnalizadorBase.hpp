#ifndef ANALIZADORBASE_HPP
#define ANALIZADORBASE_HPP

#include "Palabra.hpp"
#include "Mensaje.hpp"
#include "Lista.hpp"

//ANALIZA LA FRASE CON AYUDA DE MENSAJE Y PALABRA
//AYUDA A DEFINIR LAS PALABRAS
//CALCULA TODOS LOS RESULTADOS


class AnalizadorBase {
    protected:
        Lista<Palabra> vocabulario; 

    public:
        AnalizadorBase();
        ~AnalizadorBase();

        
        void cargarPalabras(const char* nombreArchivo);

        Palabra* buscarEnVocabulario (const char* texto) const;

        virtual int analizarFrase (Mensaje& m) = 0; //Metodo virtual 

        const char* calcularSentimiento(int puntaje) const;

        int leerMensajes(const char* nombreArchivo, char frases[][200], int maxFrases);
    };

#endif // ANALIZADORBASE_HPP