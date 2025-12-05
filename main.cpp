
#include <iostream>
#include "AnalizadorAprendizaje.hpp"
#include "Mensaje.hpp"

int main() {

    AnalizadorAprendizaje analizador;  
    analizador.cargarPalabras("palabras.txt");

    char frases[20][200];
    int cantidad = analizador.leerMensajes("mensajes.txt", frases, 20);

    for (int i = 0; i < cantidad; i++) {

        Mensaje m(frases[i]);
        m.separadorPalabras();

        int puntaje = analizador.analizarFrase(m);
        const char* sentimiento = analizador.calcularSentimiento(puntaje);

        std::cout << "----------------------------------------\n";
        std::cout << "Frase: " << frases[i] << "\n";
        std::cout << "Puntaje: " << puntaje << "\n";
        std::cout << "Resultado: " << sentimiento << "\n\n";
    }

    // Guardamos las palabras aprendidas
    analizador.guardarPalabras("palabras.txt");

    std::cout << "Las palabras aprendidas han sido guardadas exitosamente.\n";

    return 0;

    /* Para los casos de prueba, tomaremos 3 oraciones como ejemplo, 
    en las que veremos la clasificacion de las palabras nuevas  esperadas vs la clasificacion real 
    hecha por el aprendizaje*/

    /*
        - Aveces es bueno ir lento.
        - Hoy fue un dia terrible porque sali reprobado aunque siento alivio de no tener mas examenes.
        - El trafico iba muy lento gracias al pesimo trabajo que han hecho en la carretera.

        Tomaremos las palabras como positivas o negativas segun el criterio del significado real de la palabra,
        por ejemplo, sentir que deriva la palabra siento, sentir puede ser bueno, pero tambien malo.

        Algunas como "de" pues tomaremos el siginificado segun 2 izq y 2 derecha de las palabras cercanas.
    */

    /*
        De estas oraciones tomaremos en cuenta las siguientes palabras: 

                        Esperado                Real
        - aveces        positivo                Positivo    Cerca de bueno
        - ir            positivo                Negativo    Por el orden de revision, revisa primero lento antes que bueno
        - aunque        positivo                Positivo    Cerca de alivio
        - siento        positivo/negativo       Positivo    Cerca de Alivio
        - de            positivo                Positivo    Cerca de Alivio
        - no            negativo                Positivo    Cerca de Alivio, fallo debido al sistema de aprendizaje
        - gracias       positivo                Negativo    Cerca de Pesimo, fallo debido al sistema de aprendizaje
        - al            negativo                Negativo    Creca de Pesimo
        - trabajo       negativo                Negativo    Cerca de Pesimo
        - en            ninguno                 Positivo    
        - hecho         ninguno                 Positivo    Segun la teoría, estos no deberian tener significado debido a que
        - carretera     ninguno                 Positivo    no tienen palabras registradas cerca, no obstante la palabra "en" fue registrada con anterioridad
                                                            y estaba cerca de la palabra "bien" por ende toma posicion positiva y afecta a las demás...

        "Sali bien en el examen ya estoy aprobado en este curso." oracion importante para explicar comportamiento de en, hecho y carretera...


        3 casos fallidos y 3 casos inesperados que en otro contexto posiblemente fallidos...
    */
}