//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 2 POO
///Pelicula
//////////////////////////////
//#ifndef Included_NameModel_H

//#define Included_NameModel_H
/////////////////////////////

#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula {
private:
    int numPeli;
    string titulo;
    int anio;
    int duracion;
    string genero;
    static int cantActores;
    int contA;//Variable que nos ayudará a verificar que no haya mas de 10 actores por pelicula.
    Actor listaActores[999];

public:
    ///Constructor DEFAULT
    Pelicula();

    ///ACCESO
    int getNumPeli();
    string getTitulo();
    int getAnio();
    int getDuracion();
    string getGenero();
    static int getcantActores();

    ///ACCESO ListaActores
    Actor getListaActores(int nA);

    ///Agregar un actor a la lista de actores
    bool agregarActor(Actor A);

    ///Modificacion
    void setNumPeli(int n);
    void setTitulo(string t);
    void setAnio(int a);
    void setDuracion(int d);
    void setGenero(string g);

    ///Muestra
    void muestraPelicula();
    void muestraListaActores();
};

int Pelicula::cantActores = 0;
int contA = 0;

///Constructor DEFAULT
Pelicula::Pelicula(){
numPeli=000;
titulo="XXXXX";
anio=001;
duracion=002;
genero="YYYYY";
cantActores=000;
///¿dejar listaActores vacìa?
}

///ACCESO
int Pelicula::getNumPeli(){
    return numPeli;
}

string Pelicula::getTitulo(){
    return titulo;
}

int Pelicula::getAnio(){
    return anio;
}

int Pelicula::getDuracion(){
    return duracion;
}

string Pelicula::getGenero(){
    return genero;
}

int Pelicula::getcantActores(){
return cantActores;
}

///ACCESO ListaActores
Actor Pelicula::getListaActores(int nA){
return listaActores[nA];
}

///Agregar un actor a la lista de actores
bool Pelicula::agregarActor(Actor A){
    if (contA>999){
        cout<<"Solo se pueden registrar 10 actores por pelicula!!! No se agrego el actor: "<<A.getID()<<" "<<A.getNombre()<<" a la lista"<<endl<<endl;
        return false;}
    else if (A.getID()==listaActores[0].getID() ||A.getID()==listaActores[1].getID() ||A.getID()==listaActores[2].getID() ||A.getID()==listaActores[3].getID() ||A.getID()==listaActores[4].getID() ||A.getID()==listaActores[5].getID() ||A.getID()==listaActores[6].getID() ||A.getID()==listaActores[7].getID() ||A.getID()==listaActores[8].getID() ||A.getID()==listaActores[9].getID())
        {cout<<"El ID del actor: "<<A.getID()<<" ya existe! no se agrego a la lista..."<<endl<<endl;
            return false;}

    else if (A.getNombre()==listaActores[0].getNombre() ||A.getNombre()==listaActores[1].getNombre() ||A.getNombre()==listaActores[2].getNombre() ||A.getNombre()==listaActores[3].getNombre() ||A.getNombre()==listaActores[4].getNombre() ||A.getNombre()==listaActores[5].getNombre() ||A.getNombre()==listaActores[6].getNombre() ||A.getNombre()==listaActores[7].getNombre() ||A.getNombre()==listaActores[8].getNombre() ||A.getNombre()==listaActores[9].getNombre())
        {cout<<"El Nombre del actor : "<<A.getNombre()<<" ya existe! No se agrego a la lista..."<<endl<<endl;
            return false;}


   else{
    listaActores[contA].setID(A.getID());
    listaActores[contA].setNombre(A.getNombre());
    contA++;
    cantActores=cantActores+1;
        return true;
        }
}

///Modificacion
void Pelicula::setNumPeli(int n){
numPeli=n;
}

void Pelicula::setTitulo(string t){
titulo=t;
}

void Pelicula::setAnio(int a){
anio=a;
}

void Pelicula::setDuracion(int d){
duracion=d;
}

void Pelicula::setGenero(string g){
genero=g;
}

///Muestra
void Pelicula::muestraPelicula(){
    cout<<"Numero de pelicula: "<<numPeli<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Duracion: "<<duracion<<" minutos. "<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Cantidad de Actores: "<<contA<<endl<<endl;;
}

void Pelicula::muestraListaActores(){
    cout<<"Mostrando Lista de Actores..."<<endl;
    int cont=0;
    while (cont<contA){
    cout<<listaActores[cont].getID()<<" "<<listaActores[cont].getNombre()<<endl;
    cont++;
    }
    cout<<endl;
}






///////////////////////
//#endif
