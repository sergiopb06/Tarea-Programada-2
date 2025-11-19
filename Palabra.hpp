#ifndef PALABRA_HPP
#define PALABRA_HPP
//AQUI GUARDAN LAS PALABRAS COMO OBJETOS 
//SE CARGAN DESDE EL ANALIZADOR Y SE CREAN OBJETOS
//SE PODRIA HACER UNA LISTA ENLAZADA DE VOCABULARIO PARA COMPAR CON LA LISTA ENLAZADA DE LOS MENSAJES

class Palabra {
    private:
        char* palabra;
        char* categoria;

    public:
        Palabra(char* p, char* c);

        Palabra(const Palabra& p);

        ~Palabra();

        char* getPalabra();
           
        char* getCategoria();
       
        static bool comparar(const char* p1, const char* p2);
        

};

#endif //PALABRA_HPP