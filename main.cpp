//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 2 POO
///Aplicacion
//////////////////////////////
//#ifndef Included_NameModel_H

//#define Included_NameModel_H
/////////////////////////////
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include "Actor.h"
#include "Hora.h"
#include "Funcion.h"
#include "Pelicula.h"

int main()
{
///Arreglos Actor, Pelicula y Funcion
Actor arrA[20];
Pelicula arrP[20];
Funcion arrF[20];

///Para abrir los archivos:
ifstream archActores;
ifstream archPeliculas;

///Asignando datos al arreglo de Actores.
int cont1=0; //cont auxiliar 1.
string linea1;
int temp1;
int id;//Auxiliar de lectura.
string nombre;//Auxiliar de lectura.
archActores.open("actores.txt");
while (getline(archActores, linea1)) {
    temp1 = linea1.find(" ");
    id =stoi(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    nombre =(linea1.substr(0));

    arrA[cont1].setID(id);
    arrA[cont1].setNombre(nombre);
    cont1++;

}
archActores.close();

///Asignando datos al arreglo de Peliculas.
string linea;//Pa la linea
int temp;//temporal para la posicion de lo que buscamos

int cont2=0; //cont auxiliar 2.
int pNum;//Auxiliar de lectura.
int pAnio;//Auxiliar de lectura.
int pDuracion;//Auxiliar de lectura.
string pGenero;//Auxiliar de lectura.
int pCantActores;//Auxiliar de lectura.
//int pIDactor[10];//Auxiliar de lectura.
int pIDactor;
string pTitulo;//Auxiliar de lectura.
archPeliculas.open("peliculas.txt");

while (getline(archPeliculas, linea)) {

    temp = linea.find(" ");
    pNum =stoi(linea.substr(0, temp));
   // cout<<pNum<<endl;
    linea=linea.erase(0, temp+1);

    temp = linea.find(" ");
    pAnio = stoi(linea.substr(0, temp));
   // cout<<pAnio<<endl;
    linea=linea.erase(0, temp+1);

    temp = linea.find(" ");
    pDuracion = stoi(linea.substr(0, temp));
  //  cout<<pDuracion<<endl;
    linea=linea.erase(0, temp+1);

    temp = linea.find(" ");
    pGenero =(linea.substr(0, temp));
   // cout<<pGenero<<endl;
    linea=linea.erase(0, temp+1);

    temp = linea.find(" ");
    pCantActores = stoi(linea.substr(0, temp));
    //cout<<pCantActores<<endl;
    linea=linea.erase(0, temp+1);

    ////////////////////////////////////////////////////////
    for(int contaux=0; contaux<pCantActores; contaux++){
        temp = linea.find(" ");
        pIDactor = stoi(linea.substr(0, temp));

    for(int contaux1=0; contaux1<20; contaux1++){
        if(arrA[contaux1].getID() == pIDactor){
            arrP[cont2].agregarActor(arrA[contaux1]);
        }

    }
    linea=linea.erase(0, temp+1);
    }

    temp = linea.find(" ");
    pTitulo=(linea.substr(0));
  //  cout<<pTitulo<<endl;

    arrP[cont2].setNumPeli(pNum);
    arrP[cont2].setAnio(pAnio);
    arrP[cont2].setDuracion(pDuracion);
    arrP[cont2].setGenero(pGenero);
    arrP[cont2].setTitulo(pTitulo);
    cont2++;
}

///Usuario tecleando Funciones:
int n;
string clave;
int nP;
int s;
int h;
int m;

cout<<"Por favor teclee las funciones del dia de hoy: "<<endl<<endl;
cout<<"Cuantas funciones habra el dia de hoy ? ";
cin>>n;
if(n<0)
    cout<<"ERROR! DEBE TECLEAR UN ENTERO positivo...";
else
cout<<endl;

for(int i=0; i<n; i++){
cout<<"Para la funcion: "<<i+1<<" dame..."<<endl;
cout<<endl;
cout<<"La clave de la funcion: ";
cin>>clave;
cout<<"El numero de la Pelicula: ";
cin>>nP;
cout<<"El numero de la Sala: ";
cin>>s;
cout<<"La hora de la funcion... "<<endl;
cout<<"Horas: ";
cin>>h;
cout<<"Minutos: ";
cin>>m;
cout<<endl;

Hora h1;
h1.HoraP(h, m);
arrF[i].FuncionP(clave, nP, s, h1);

}
///Menu principal:
char opcion;
while (opcion != 'g') {
cout<<endl;
cout<<"---MENU PRINCIPAL---"<<endl<<endl;
cout<<"a) Consultar todos los Actores en la lista. "<<endl;
cout<<"b) Consultar todas las Peliculas en la lista. "<<endl;
cout<<"c) Consultar de todas las Funciones del dia. "<<endl;
cout<<"d) Consultar Funciones por HORA. "<<endl;
cout<<"e) Consultar Funciones por CLAVE. "<<endl;
cout<<"f) Consultar Peliculas por ACTOR.. "<<endl;
cout<<"g) Terminar. "<<endl<<endl;
cout<<"QUE DESEA HACER? ";
cin>>opcion;


///OPCION A.
if (opcion=='a' || opcion=='A'){
cout<<endl<<endl;
cout<<"Desplegando LISTA de Actores..."<<endl;

int x=0;
while(cont1>x){
    arrA[x].muestraActor();
    x++;
}


}

///OPCION B.
if (opcion=='b' || opcion=='B'){
cout<<endl<<endl;
cout<<"Desplegando LISTA de PELICULAS..."<<endl;

int x=0;
while(cont2>x){
    arrP[x].muestraPelicula();
    arrP[x].muestraListaActores();
    x++;
}

}

///OPCION C.
if (opcion=='c' || opcion=='C'){
cout<<endl<<endl;

int f=0;
if (n<1){
    cout<<"NO hay Funciones REGISTRADAS para el dia de hoy!"<<endl;
}
else{
    cout<<"Desplegando FUNCIONES del dia..."<<endl;
    while(n>f){
            cout<<"Clave FUNCION: "<<arrF[f].getCveFuncion()<<endl;
            for(int i=0; i<cont2; i++){
            if(arrF[f].getnumPeli()==arrP[i].getNumPeli()){
            cout<<"Nombre de la Pelicula: "<<arrP[i].getTitulo()<<endl;
            }
            }
            cout<<"SALA: "<<arrF[f].getSala()<<endl;
            cout<<"Hora: ";
            arrF[f].muestraFuncionHora();
            cout<<endl;
            f++;
    }
}
}

///Opcion D.
if (opcion=='d' || opcion=='D'){
Hora h2;
cout<<"En que horario deseas consultar?"<<endl;
cout<<"Dame HORAS:";
cin>>h;
cout<<"Dame Minutos:";
cin>>m;
h2.HoraP(h, m);
int f=0;
for(int i=0; i<n; i++)
{
    if(h2.getHora()==arrF[i].getHora().getHora() && h2.getMinuto()==arrF[i].getHora().getMinuto()){
           cout<<"La funcion a la hora ";
            h2.muestraHora();
            cout<<" es..."<<endl;
            for(int x=0; x<cont2; x++){
            if(arrF[i].getnumPeli()==arrP[x].getNumPeli()){
            cout<<"Titulo PELICULA: "<<arrP[x].getTitulo()<<endl;
            break;}
            }
            cout<<"Sala: "<< arrF[i].getSala()<<endl;
            cout<<endl;
            break;
    }


}

}


///Opcion E.
if (opcion=='E' || opcion=='e'){
string clv;
cout<<endl<<endl;
cout<<"Dame la CLAVE de la Funcion: ";
cin>>clv;
for(int i=0; i<n; i++)
{
    if(clv==arrF[i].getCveFuncion()){
            cout<<"La clave "<<clv<<" pertenece a la funcion..."<<endl;
            cout<<"Sala: "<<arrF[i].getSala()<<endl;
            for(int x=0; x<cont2; x++){
            if(arrF[i].getnumPeli()==arrP[x].getNumPeli()){
            cout<<"Titulo PELICULA: "<<arrP[x].getTitulo()<<endl;
            cout<<"Duracion: "<<arrP[x].getDuracion()<<endl;
            cout<<"Genero: "<<arrP[x].getGenero()<<endl;
            arrP[x].muestraListaActores();
            break;}
            }
            cout<<"Hora: ";
            arrF[i].muestraFuncionHora();
            cout<<endl;
            break;
    }


}
/*while(n>f){
    if(clv==arrF[f].getCveFuncion()){
            for(int x=0; x<cont2; x++){
            if(arrF[f].getnumPeli()==arrP[x].getNumPeli()){
            cout<<"La clave "<<clv<<" pertenece a la funcion..."<<endl;
            cout<<"Sala: "<<arrF[f].getSala()<<endl;
            cout<<"Titulo PELICULA: "<<arrP[x].getTitulo()<<endl;
            cout<<"Hora: ";
            arrF[f].muestraFuncionHora();
            cout<<"Duracion: "<<arrP[x].getDuracion()<<endl;
            cout<<"Genero: "<<arrP[x].getGenero()<<endl;
            arrP[x].muestraListaActores();
            cout<<endl;
            break;
            }

    }
    }
    else  {
            f++;
          }

*/
}





///Opcion f.
if (opcion=='f' || opcion=='F'){
int IDA;
cout<<endl<<endl;
cout<<"Dame el ID del Actor que quieras consultar: ";
cin>>IDA;
for(int x=0; x<20; x++){
if(IDA==arrA[x].getID())
cout<<"El actor: <"<<arrA[x].getNombre()<<"> participa en las siguientes PELICULAS: "<<endl;

}
for(int f=0; f<cont2; f++){
for(int y=0; y<10; y++){
if(IDA == arrP[f].getListaActores(y).getID()){
        cout<<"Titulo: "<<arrP[f].getTitulo()<<endl;
        cout<<"Anio: "<<arrP[f].getAnio()<<endl;

}
}
}

}

///Opcion E.
if (opcion=='g' || opcion=='G'){
cout<<endl<<endl;
cout<< "Gracias por utilizar nuestro programa!"<<endl;
    return 0;
}
archPeliculas.close();



}
}

