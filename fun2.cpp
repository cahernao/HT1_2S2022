#include "fun2.h"
#include <iostream>
using namespace std;

struct profesor{
    tipo int;
    id_profesor int;
    cui char[15];
    nombre char[25];
    curso char[25];
};

fun2::fun2()
{

}

void fun2::menu(){
    int opcion = -1;
    //cout<<"Hola"<<endl;
    while(opcion!=0){
        cout<<"   Eliga una opcion"<<endl;
        cout<<" 1. seguir"<<endl;
        cout<<" 0. cerrar"<<endl;
        cin>>opcion;
        cout<<endl;
    }

}

void busca(){

}
