#include "fun2.h"
#include <iostream>
using namespace std;

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

fun2::fun2()
{

}

void fun2::menu(){
    int opcion = -1;
    //cout<<"Hola"<<endl;
    while(opcion!=0){
        cout<<"   Eliga una opcion"<<endl;
        cout<<" 1. crea"<<endl;
        cout<<" 0. cerrar \n ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
        case 1:
            crea();
            break;
        }
    }

}

void fun2::crea(){
    FILE *file;
    profesor pro1;
    int tamanio = sizeof(pro1);
    char bloque[1024];
    for (int i = 0; i < 1024; ++i) {
        bloque[i] = '\0';
    }
    int limite = 0;
    file = fopen("pro1.dsk", "w");
    while(limite!=tamanio){
        fwrite(&bloque, 1024, 1, file);
        limite++;
    }
    fclose(file);


}
