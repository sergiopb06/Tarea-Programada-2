
#include "Analizador.hpp"
#include <fstream>
#include <cctype>
#include <iostream>

Analizador::Analizador(){}
Analizador::~Analizador() {}

void Analizador::cargarPalabras(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::cout << "\nCargando archivo..." << std::endl;

    if (!archivo.is_open()) {
        std::cout << "ERROR\nNo se puede abrir el archivo..." << std::endl;
        return;
    }

    char linea[150];
    while (archivo.getline(linea, 150)) {

        int length = 0;
        while (linea[length] != '\0' && linea[length] != '\n') { //Mientras no se acaben los caracteres o no haya un salto de linea, se cuentan los caracteres
            length++;
        }

        int indiceComa = -1;
        int i = 0;
        while( i < length && indiceComa == -1){
            if(linea[i] == ','){
                indiceComa = i; //Indice donde se encontro la ','
            }

            i++;
        }

        //Se guarda la palabra
        char* palabra = new char[indiceComa + 1];
        for (int i = 0; i < indiceComa; i++){
            palabra[i] = std::tolower(linea[i]);
        }

        palabra[indiceComa] = '\0';



        indiceComa++; //Se va al primer caracter despues de la coma



        //Se guarda la categoria
        int indiceCategoria = 0;
        while ((indiceComa + indiceCategoria < length) && (linea[indiceComa + indiceCategoria] != '\0')) {
            indiceCategoria++;
        }

        int lengthCategoria = indiceCategoria;


        char* categoria = new char[lengthCategoria + 1];
        for (int i = 0; i < lengthCategoria; i++) {
            categoria[i] = std::tolower(linea[indiceComa + i]);
        }

        categoria[lengthCategoria] = '\0';


        //Se crea la palabra
        Palabra p(palabra, categoria);

        delete[] palabra;
        delete[] categoria;

        vocabulario.agregarInicio(p);
    }

    archivo.close();

}

Palabra* Analizador::buscarEnVocabulario (const char* texto) const {
    Nodo<Palabra>* actual = vocabulario.getCabeza();
    while (actual) {
        if (Palabra::comparar(actual->dato.getPalabra(), texto)) {
            return &(actual->dato);
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

int Analizador::analizarFrase(Mensaje& m) {

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

const char* Analizador::calcularSentimiento(int puntaje) const {
    if (puntaje > 0) return "POSITIVO";
    if (puntaje < 0) return "NEGATIVO";
    return "NEUTRO";
}


int Analizador::leerMensajes(const char* nombreArchivo, char frases[][200], int maxFrases) { // se pide un arreglo y un maxFrases
                                                                                            
    std::ifstream archivo(nombreArchivo);                                            // para poder almacenar las frases en el arreglo correctamente
    if (!archivo.is_open()) {                                                     // cada frase tiene maximo 200 caracteres y el arreglo sera de maximo 20 frases
        std::cout << "ERROR: no se puede abrir mensajes.txt...\n";
        return 0;
    }

    char fraseTemp[200];
    int indice = 0;
    int total = 0;

    char c;
    while (archivo.get(c)) {

        if (c == '.') {         //fin de frase
            fraseTemp[indice] = '\0';

            if (indice > 0 && total < maxFrases) {
                int k = 0;
                while (fraseTemp[k] != '\0' && k < 199) {    // copiamos manualmente
                    frases[total][k] = fraseTemp[k];
                    k++;
                }
                frases[total][k] = '\0';

                total++;
            }

            indice = 0; // reiniciamos fraseTemp
        }
        else {
            if (indice < 199) {
                fraseTemp[indice++] = c;
            }
        }
    }

    archivo.close();
    return total;
}



