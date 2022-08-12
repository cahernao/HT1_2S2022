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
        cout<<"\n\n   Eliga una opcion"<<endl;
        cout<<" 1. Registro Profesor"<<endl;
        cout<<" 2. Registro Estudiante"<<endl;
        cout<<" 3. Ver Registros"<<endl;
        cout<<" 4. Salir \n >> ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
        case 1:
            registroProfesor();
            break;

        case 2:
            registroEstudiante();
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
    if(!archivo_existe("es.dsk")){
        //cout<<" no existe \n";

        FILE *file;
        estudiante pro1;
        int tamanio = sizeof(pro1);

        char bloque[1024];
        for (int i = 0; i < 1024; ++i) {
            bloque[i] = '\0';
        }
        int limite = 0;
        file = fopen("es.dsk", "w");
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
    cout<<" id_profesor: ";
    cin>>miP.id_profesor;

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
void fun2::registroEstudiante(){
    estudiante miP;
    FILE *archivoBin;
    cout<<"  Registro estudiante: \n";
    cout<<" tipo: ";
    cin>>miP.tipo;
    cout<<" id_estudiante: ";
    cin>>miP.id_estudiante;


    cout<<" CUI: ";
    cin>>miP.cui;

    cout<<" nombre: ";
    cin>>miP.nombre;

    cout<<" carnet: ";
    cin>>miP.carnet;


    archivoBin = fopen("es.dsk", "rb+");
    fseek(archivoBin, sizeof(profesor), SEEK_SET);
    fwrite(&miP, sizeof(miP), 1, archivoBin);
    fclose(archivoBin);

}

void fun2::revisar(profesor pp, estudiante ee){
    FILE *abrir;
    abrir = fopen("pro1.dsk", "rb+");
    fseek(abrir, sizeof(profesor), SEEK_SET);
    fread(&pp, sizeof(pp), 1, abrir);

    abrir = fopen("es.dsk", "rb+");
    fseek(abrir, sizeof(estudiante), SEEK_SET);
    fread(&ee, sizeof(ee), 1, abrir);
    imprime(pp, ee);

}

void fun2::imprime(profesor pp, estudiante ee){

    cout<<"     profesor\n";
    cout<<" tipo: "<<pp.tipo;
    cout<<" id: "<< pp.id_profesor;
    cout<<" cui: "<<pp.cui;
    cout<<" nombre: "<<pp.nombre;
    cout<<" curso: "<<pp.curso<<"\n";

    cout<<"     estudiante\n";
    cout<<" tipo: "<<ee.tipo;
    cout<<" id: "<< ee.id_estudiante;
    cout<<" cui: "<<ee.cui;
    cout<<" nombre: "<<ee.nombre;
    cout<<" carne: "<<ee.carnet<<"\n";

}

bool fun2::archivo_existe(string nombre){
    ifstream archivo(nombre.c_str());
    return archivo.good();
}
