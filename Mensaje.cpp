#include "Mensaje.hpp"
#include <cctype>

Mensaje::Mensaje(const char* f) : cabeza(nullptr) {
    int length = 0;

    while(f[length] != '\0') {
        length++;
    }

    frase = new char[length + 1];
    for(int i = 0; i < length; i++){
        frase[i] = f[i];
    }

    frase[length] = '\0';
}

Mensaje::~Mensaje() {
    Nodo<char*>* actual = cabeza;
    while (actual) {
        Nodo<char*>* temp = actual;
        actual = actual->siguiente;
        delete[] temp->dato;
        delete temp;
    }

    delete [] frase;
}

void Mensaje::separadorPalabras() {
    if (!frase) {
        return;
    }

    char* caracter = frase;

    while (*caracter && !std::isalnum(*caracter)) { //Mientras haya un caracter y NO sea alfanumerico, se va al siguiente
        caracter++;
    }

    while (*caracter) { //Empieza desde el primer caracter alfanumerico

        char* primero = caracter;
        int length = 0;
        while (caracter[length] && std::isalnum(caracter[length])) { //Mientras sea alfanumerico, se cuentan los caracteres de la palabra
            length++;
        }

        //Se crea la palabra en minuscula
        char* palabra = new char[length + 1];
        for (int i = 0; i < length; i++) {
            palabra[i] = std::tolower(primero[i]);
        }

        palabra[length] = '\0';


        //Agrega la palabra a la lista de palabras encontradas
        Nodo<char*>* nodo = new Nodo<char*>(palabra);
        nodo->siguiente = cabeza;
        cabeza = nodo;

       //Avanza hasta la siguiente palabra valida
        caracter = primero + length;
        while (*caracter && !std::isalnum(*caracter)) {
            caracter++;
        }
    }
}

Nodo<char*>* Mensaje::getCabeza() const {
    return cabeza;
}

char* Mensaje::getFrase() const {
    return frase;
}
