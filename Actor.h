//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 2 POO
///ACTOR
//////////////////////////////
//#ifndef Included_NameModel_H
#pragma once
//#define Included_NameModel_H
/////////////////////////////
#include <iostream>
#include <string>

using namespace std;

class Actor {

private:
    int id;
    string nombre;

public:
    int publicID;
    ///Contructor DEFAULT
    Actor();

    ///Constructor por parametros
    ActorP(int iID, string sNombre);

    ///Acceso
    int getID();
    string getNombre();

    ///Modificacion
    void setID(int iID);
    void setNombre(string sNombre);

    ///Muestra
    void muestraActor();
};

///Constructor DEFAULT:
Actor::Actor(){
id=0;
publicID=id;
nombre="SIN NOMBRE";
}

///Constructor por parametros:
Actor::ActorP(int iID, string sNombre){
id=iID;
publicID=id;
nombre=sNombre;
}


///Acceso:
int Actor::getID(){
return id;
}

string Actor::getNombre(){
return nombre;
}

///Modificacion:
void Actor::setID(int iID){
id=iID;
publicID=id;
}

void Actor::setNombre(string sNombre){
nombre=sNombre;
}

///Muestra:
void Actor::muestraActor(){
//cout<<"Mostrando Actores... "<<endl;
cout<<id<<" "<<nombre<<endl;
}

///////////////////////
//#endif
