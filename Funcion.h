//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 2 POO
///FUNCION
//////////////////////////////
//#ifndef Included_NameModel_H

//#define Included_NameModel_H
/////////////////////////////

#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

class Funcion {

private:
    string cveFuncion;
    int numPeli;
    int sala;
    Hora hora;

public:

    ///Construtor Default
    Funcion();

    ///Constructor por Parametros
    FuncionP(string cveFun, int numP, int s, Hora h);

    ///Acceso
    string getCveFuncion();
    int getnumPeli();
    int getSala();
    Hora getHora();

    ///Modificacion
    void setCveFuncion(string cve);
    void setnumPeli(int numPe);
    void setSala(int sa);
    void setHora(Hora ho);

     ///MUESTRA
    void muestraFuncion();
    void muestraFuncionHora();
};

///Constructor Default
Funcion::Funcion(){
cveFuncion="XYZ";
numPeli=666;
sala=999;

Hora h1; //Al crear el objeto h1, automaticamente se crea con el constructor DEFAULT de la clase Hora
hora=h1;
}

///Constructor por Parametros
Funcion::FuncionP(string cveFun, int numP, int s, Hora h){
cveFuncion=cveFun;
numPeli=numP;
sala=s;
hora=h;
}

///ACCESO
string Funcion::getCveFuncion(){
return cveFuncion;
}

int Funcion::getnumPeli(){
return numPeli;
}

int Funcion::getSala(){
return sala;
}

Hora Funcion::getHora(){
return hora;
}

///MODIFICACION
void Funcion::setCveFuncion(string cve){
cveFuncion=cve;
}

void Funcion::setnumPeli(int numPe){
numPeli=numPe;
}

void Funcion::setSala(int sa){
sala=sa;
}

void Funcion::setHora(Hora ho){
hora=ho;
}

///MUESTRA
void Funcion::muestraFuncion(){
//cout<<"Mostrando Funcion... "<<endl;
cout<<"Clave de Funcion: "<<cveFuncion<<endl;
cout<<"Numero de Pelicula: "<<numPeli<<endl;
cout<<"Sala: "<<sala<<endl;
cout<<"Hora: "<<hora.getHora()<<":"<<hora.getMinuto()<<endl<<endl;
}

void Funcion::muestraFuncionHora(){
cout<<"Hora: "<<hora.getHora()<<":"<<hora.getMinuto()<<endl;
}

///////////////////////
//#endif
