#ifndef ANALIZADOR_APRENDIZAJE_HPP
#define ANALIZADOR_APRENDIZAJE_HPP

#include "AnalizadorBase.hpp"
#include "Lista.hpp"


class AnalizadorAprendizaje : public AnalizadorBase {
private:
    Lista<Palabra*> aprendidas;

public:
    AnalizadorAprendizaje();
    virtual ~AnalizadorAprendizaje();

    
    virtual int analizarFrase(Mensaje& m) override;

    
    void guardarPalabras(const char* nombreArchivo);
    bool esArticulo(const char* p) const;
    Palabra* aprenderContexto(char** palabras, int total, int indice);

};

#endif //ANALIZADOR_APRENDIZAJE_HPP