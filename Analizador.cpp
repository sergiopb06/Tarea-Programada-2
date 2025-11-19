
#include "Analizador.hpp"
#include <fstream>
#include <cctype>
#include <iostream>

Analizador::Analizador() : vocabulario(nullptr) {}

Analizador::~Analizador() {
    Nodo<Palabra>* actual = vocabulario;
    while (actual) {
        Nodo<Palabra>* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void Analizador::cargarPalabras(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::cout << "Cargando archivo..." << std::endl;

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


        //Se crea la palabra.
        Palabra p(palabra, categoria);

        delete[] palabra;
        delete[] categoria;

        Nodo<Palabra>* nuevo = new Nodo<Palabra>(p);
        nuevo->siguiente = vocabulario;
        vocabulario = nuevo;
    }

    archivo.close();

}

