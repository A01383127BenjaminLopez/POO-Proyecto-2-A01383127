//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 2 POO
///HORA
//////////////////////////////
//#ifndef Included_NameModel_H
#pragma once
//#define Included_NameModel_H
/////////////////////////////
#include <iostream>
#include <string>

using namespace std;

class Hora{

private:
    int hh;
    int mm;

public:
    int publicHora;
    int publicMinutos;
    ///Constructor Default
    Hora();
    ///Constructor por Parametros
    HoraP(int hora, int minu);

    ///ACCESO
    int getHora();
    int getMinuto();

    ///MODIFICACION
    void setHora(int h);
    void setMinuto(int m);

    ///MUESTRA
    void muestraHora();
};
///Constructor Default
Hora::Hora(){
hh=00;
publicHora=hh;
mm=00;
publicMinutos=mm;
}
///Constructor por Parametros
Hora::HoraP(int hora, int minu){
if(hora>23 || hora<0)
    cout<<"Hora invalida! "<<endl<<endl;
else{
    hh=hora;
    publicHora=hh;
    }
if(minu>59 || minu<0)
    cout<<"Minutos Invalidos! "<<endl<<endl;
else{
    mm=minu;
    publicMinutos=mm;

}
}

///ACCESO
int Hora::getHora(){
return hh;
}

int Hora::getMinuto(){
return mm;
}

///MODIFICACION
void Hora::setHora(int h){
if(h>23 || h<0)
    cout<<"Hora invalida! "<<endl<<endl;
else{
    hh=h;
    publicHora=hh;
}
}

void Hora::setMinuto(int m){
if(m>59 || m<0)
    cout<<"Minutos Invalidos! "<<endl<<endl;
else{
    mm=m;
    publicMinutos=mm;
}
}

///MUESTRA
void Hora::muestraHora(){
//cout<<"Mostrando Hora... "<<endl;
cout<<hh<<":"<<mm;
}

///////////////////////
//#endif
