#ifndef ANALIZADOR_SIMPLE_HPP
#define ANALIZADOR_SIMPLE_HPP
#include "AnalizadorBase.hpp"

class AnalizadorSimple : public AnalizadorBase {
    public:
        AnalizadorSimple();
        virtual ~AnalizadorSimple();

        virtual int analizarFrase(Mensaje& m) override;
    };

    
#endif //ANALIZADOR_SIMPLE_HPP