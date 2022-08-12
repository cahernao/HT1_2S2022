#include "fun2.h"
#include <iostream>
#include <fstream>
#include <cstdio>
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
    int opcion = 0;
    profesor pp;
    estudiante ee;
    crea();

    while(opcion!=4){
        cout<<"   Eliga una opcion"<<endl;
        cout<<" 1. Registro Profesor"<<endl;
        cout<<" 3. Ver Registros"<<endl;
        cout<<" 4. Salir \n >> ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
        case 1:
            registroProfesor();
            break;

        case 3:
            revisar(pp, ee);
            break;
        }
    }

}

void fun2::crea(){

    if(!archivo_existe("pro1.dsk")){
        //cout<<" no existe \n";

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

}

void fun2::registroProfesor(){
    profesor miP;
    FILE *archivoBin;
    cout<<"  Registro profesor: \n";
    cout<<" tipo: ";
    cin>>miP.tipo;
    cout<<" Escribio: "<<miP.tipo<<" \n";
    cout<<" id_profesor: ";
    cin>>miP.id_profesor;
    cout<<" Escribio: "<<miP.id_profesor<<" \n";

    cout<<" CUI: ";
    cin>>miP.cui;

    cout<<" nombre: ";
    cin>>miP.nombre;

    cout<<" curso: ";
    cin>>miP.curso;


    archivoBin = fopen("pro1.dsk", "rb+");
    fseek(archivoBin, sizeof(profesor), SEEK_SET);
    fwrite(&miP, sizeof(miP), 1, archivoBin);
    fclose(archivoBin);

}

void fun2::revisar(profesor pp, estudiante ee){
    FILE *abrir;
    abrir = fopen("pro1.dsk", "rb+");
    fseek(abrir, sizeof(profesor), SEEK_SET);
    fread(&pp, sizeof(pp), 1, abrir);
    imprime(pp, ee);

}

void fun2::imprime(profesor pp, estudiante ee){

    cout<<"     profesor\n";
    cout<<" tipo: "<<pp.tipo;
    cout<<" id: "<< pp.id_profesor;
    cout<<" cui: "<<pp.cui;
    cout<<" nombre: "<<pp.nombre;
    cout<<" curso: "<<pp.curso<<"\n";

}

bool fun2::archivo_existe(string nombre){
    ifstream archivo(nombre.c_str());
    return archivo.good();
}
