#include "AnalizadorSimple.hpp"


AnalizadorSimple::AnalizadorSimple() {}

AnalizadorSimple::~AnalizadorSimple() {}

int AnalizadorSimple::analizarFrase(Mensaje& m) {

    if (!m.getCabeza()) {
        m.separadorPalabras(); // Si aun no se separaron las palabras, hacerlo
    }

    int puntaje = 0; // inicializamos el puntaje

    Nodo<char*>* actual = m.getCabeza();

    while (actual) {

        Palabra* pal = buscarEnVocabulario(actual->dato); // Buscamos la palabra en el vocabulario
        if (pal) {
            char* cat = pal->getCategoria();

            bool positiva = Palabra::comparar(cat, "positiva");
            bool negativa = Palabra::comparar(cat, "negativa"); // verificamos si es positiva o negativa

            if (positiva) puntaje += 1;  // se suma el puntaje o se resta dependiendo del resultado
            else if (negativa) puntaje -= 1;
        }

        actual = actual->siguiente;
    }

    return puntaje;
}