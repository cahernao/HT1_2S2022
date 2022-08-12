#ifndef FUN2_H
#define FUN2_H
#include <iostream>
using namespace std;


class fun2
{

    struct profesor{
        int tipo;
        int id_profesor;
        char cui[15];
        char nombre[25];
        char curso[25];
    };

    struct estudiante{
        int tipo;
        int id_estudiante;
        char cui[15];
        char nombre[25];
        char carnet[25];
    };


public:
    fun2();
    void menu();
    void crea();


private:
    bool archivo_existe(string nombre);
    void registroProfesor();
    void revisar(profesor pp, estudiante ee);
    void imprime(profesor pp, estudiante ee);
};

#endif // FUN2_H
