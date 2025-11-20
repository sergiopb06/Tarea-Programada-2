
#include <iostream>
#include "Analizador.hpp"
#include "Mensaje.hpp"

int main() {

    Analizador a;
    a.cargarPalabras("palabras.txt");

    char frases[20][200];
    int cantidad = a.leerMensajes("mensajes.txt", frases, 20);

    for (int i = 0; i < cantidad; i++) {

        Mensaje m(frases[i]);
        m.separadorPalabras();

        int puntaje = a.analizarFrase(m);
        const char* sentimiento = a.calcularSentimiento(puntaje);

        std::cout << "Frase: " << frases[i] << std::endl;
        std::cout << "Puntaje: " << puntaje << std::endl;
        std::cout << "Resultado: " << sentimiento << std::endl << std::endl;
    }
}