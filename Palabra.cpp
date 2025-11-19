#include "Palabra.hpp"

Palabra::Palabra(char* p, char* c) {
    //PALABRA
    int len = 0;

    while (p[len] != '\0') {
        len++;
    }

    palabra = new char[len + 1];

    for (int i = 0; i < len; i++){

        palabra[i] = p[i];
    }

    palabra[len] = '\0';


    //CATEGORIA
    int lenC = 0;

    while (c[lenC] != '\0') {
        lenC++;
    }

    categoria = new char[lenC + 1];

    for (int i = 0; i < lenC; i++){

        categoria[i] = c[i];
    }

    categoria[lenC] = '\0';

}

Palabra::Palabra(const Palabra& p) {
    //PALABRA
    int len = 0;
    while (p.palabra[len] != '\0') {
        len++;
    }

    palabra = new char[len + 1];
    for (int i = 0; i < len; i++) {
        palabra[i] = p.palabra[i];
    }

    palabra[len] = '\0';


    //CATEGORIA
    int lenC = 0;
    while (p.categoria[lenC] != '\0') {
        lenC++;
    }

    categoria = new char[lenC + 1];
    for (int i = 0; i < lenC; i++){
        categoria[i] = p.categoria[i];
    }
    
    categoria[lenC] = '\0';

}

           




Palabra::~Palabra() {
    delete[] palabra;
    delete[] categoria;
}



char* Palabra::getPalabra(){
    return palabra;
}


char* Palabra::getCategoria(){
    return categoria;
}

bool Palabra::comparar(const char* p1, const char* p2){
    int i = 0;

    while (p1[i] != '\0' && p2[i] != '\0') {
        if (p1[i] != p2[i]) {
            return false;
        }

        i++;
    }

    return p1[i] == '\0' && p2[i] == '\0';
}


