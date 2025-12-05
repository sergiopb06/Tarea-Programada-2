#include "AnalizadorAprendizaje.hpp"
#include <fstream>


AnalizadorAprendizaje::AnalizadorAprendizaje() : AnalizadorBase() {}

AnalizadorAprendizaje::~AnalizadorAprendizaje() {}


bool AnalizadorAprendizaje::esArticulo(const char* p) const {
    const char* articulos[] = {"el", "la", "una", "un","los", "las", "unos", "unas", "eso", "esa", "esos", "esas" };

    int cantidad = 10;

    for (int i = 0; i < cantidad; i++) {
        if (Palabra::comparar(p, articulos[i])) {
            return true;
        }
    }

    return false;
}


Palabra* AnalizadorAprendizaje::aprenderContexto(char** palabras, int total, int indice) {

   //DISTANCIA
    for (int distancia = 1; distancia <= 2; distancia++) {
        int izquierda = indice - distancia;
        int derecha = indice + distancia;

        //IZQUIERDA
        if (izquierda >= 0 && !esArticulo(palabras[izquierda])) {
            Palabra* palabraContexto = buscarEnVocabulario(palabras[izquierda]);

            if (palabraContexto) {
                char* cat = palabraContexto->getCategoria();
                bool positiva = Palabra::comparar(cat, "positiva");
                bool negativa = Palabra::comparar(cat, "negativa");

                if (positiva || negativa) {
                    const char* categoria;

                    if (positiva) {
                        categoria = "positiva";
                    } 

                    else {
                        categoria = "negativa";
                    }       

                    




                    int lengthP = 0;
                    while (palabras[indice][lengthP] != '\0') {
                        lengthP++;
                    }

                    char* copiaP = new char[lengthP + 1];
                    for (int i = 0; i < lengthP; i++) {
                        copiaP[i] = palabras[indice][i];
                    }
                    copiaP[lengthP] = '\0';



                    //CATEGORIA
                    int lengtC = 0;
                    while (categoria[lengtC] != '\0') {
                        lengtC++;
                    }

                    char* copiaC = new char[lengtC + 1];
                    for (int i = 0; i < lengtC; i++) {
                        copiaC[i] = categoria[i];
                    }
                    copiaC[lengtC] = '\0';

                    //PALABRA
                    Palabra nueva(copiaP, copiaC);

                    delete[] copiaP;
                    delete[] copiaC;

                    
                    vocabulario.agregarInicio(nueva);

                    
                    Palabra* agregada = buscarEnVocabulario(palabras[indice]);
                    if (agregada) {
                        aprendidas.agregarInicio(agregada);
                    }

                    return agregada;
                }
            }
        }


        //DERECHA
        if (derecha < total && !esArticulo(palabras[derecha])) {
            Palabra* palabraContexto = buscarEnVocabulario(palabras[derecha]);

            if (palabraContexto) {
                char* cat = palabraContexto->getCategoria();
                bool positiva = Palabra::comparar(cat, "positiva");
                bool negativa = Palabra::comparar(cat, "negativa");

                if (positiva || negativa) {
                    const char* categoria;

                    if (positiva) {
                        categoria = "positiva";
                    } 

                    else {
                        categoria = "negativa";
                    }       

                    
                    int lengthP = 0;
                    while (palabras[indice][lengthP] != '\0') {
                        lengthP++;
                    }

                    char* copiaP = new char[lengthP + 1];
                    for (int i = 0; i < lengthP; i++) {
                        copiaP[i] = palabras[indice][i];
                    }
                    copiaP[lengthP] = '\0';



                    //CATEGORIA
                    int lengthC = 0;
                    while (categoria[lengthC] != '\0') {
                        lengthC++;
                    }

                    char* copiaC = new char[lengthC + 1];
                    for (int i = 0; i < lengthC; i++) {
                        copiaC[i] = categoria[i];
                    }
                    copiaC[lengthC] = '\0';

                    //PALABRA
                    Palabra nueva(copiaP, copiaC);

                    delete[] copiaP;
                    delete[] copiaC;

                    
                    vocabulario.agregarInicio(nueva);

                    
                    Palabra* agregada = buscarEnVocabulario(palabras[indice]);
                    if (agregada) {
                        aprendidas.agregarInicio(agregada);
                    }

                    return agregada;
                }
            }
        }
    }

    return nullptr;
}




int AnalizadorAprendizaje::analizarFrase(Mensaje& m) {

    if (!m.getCabeza()) {
        m.separadorPalabras(); // Si aun no se separaron las palabras, hacerlo
    }

    //Contar palabras
    int total = 0;
    Nodo<char*>* cabeza = m.getCabeza();
    while (cabeza) {
        total++;
        cabeza = cabeza->siguiente;
    }

    if (total == 0) {
        return 0;
    }


    //Convertir lista enlazada a un arreglo de char
    char** palabras = new char*[total];
    cabeza = m.getCabeza();
    int indice = 0;
    while (cabeza) {
        palabras[indice++] = cabeza->dato;
        cabeza = cabeza->siguiente;
    }

    int puntaje = 0; //Inicializar puntaje


    

    for (int i = 0; i < total; i++) {

        //Si encuentra un articulo, pasa al siguiente
        if (esArticulo(palabras[i])) {
            continue;
        }

       
        Palabra* pal = buscarEnVocabulario(palabras[i]);

        //Si la palabra no esta, la aprende por Contexto
        if (!pal) {
            pal = aprenderContexto(palabras, total, i);
        }

        //Si ya esta en el archivo, suma puntaje
        if (pal) {
            char* cat = pal->getCategoria();
            bool positiva = Palabra::comparar(cat, "positiva");
            bool negativa = Palabra::comparar(cat, "negativa");

            if (positiva) puntaje += 1;
            else if (negativa) puntaje -= 1;
        }
    }

    delete[] palabras;
    return puntaje;
}



//ESCRIBIR PALABRAS EN EL ARCHIVO
void AnalizadorAprendizaje::guardarPalabras(const char* nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app);

    if (!archivo.is_open()) {
        return;
    }

    Nodo<Palabra*>* actual = aprendidas.getCabeza();

    while (actual) {
        Palabra* p = actual->dato;
        if (p) {
            archivo << p->getPalabra() << "," << p->getCategoria() << "\n";
        }
        actual = actual->siguiente;
    }

    archivo.close();
}
