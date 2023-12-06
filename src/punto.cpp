#include "punto.h"

#include <iostream>

using namespace std;

Punto::Punto(){
    latitud = longitud = 0;
}

Punto::Punto( double la, double lo, const string & d  ){
    latitud = la;
    longitud = lo;
}

double Punto::GetLatitud() const{
    return latitud;
}

double Punto::GetLongitud() const{
    return longitud;
}

bool Punto::operator < (const Punto & p )const{
    //Hay que preguntar como se implementa
}

bool Punto::operator == (const Punto & p )const{
    return p.GetLatitud() == this->latitud && p.GetLongitud() == this->longitud;
}

friend istream & operator >> (istream & is, Punto &p){
    is>> latitud >> longitud;
	return is;
}

friend ostream & operator << (ostream & os, const Punto &p ){
    os<<"["<<latitud<<" "<<longitud<<"]";
	return os;
}