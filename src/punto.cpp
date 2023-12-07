#include "punto.h"

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

void Punto::SetLatitud(double la){
    latitud=la;
}

void Punto::SetLongitud(double lo){
    longitud=lo;
}

bool Punto::operator < (const Punto & p )const{
    //El criterio que determinamos para que un punto sea menor que otro 
    //será en función a su distancia respecto al 0 0

    double distancia1 = sqrt( this->latitud * this->latitud + this->longitud * this->longitud );
    double distancia2= sqrt( p.GetLatitud() * p.GetLatitud() + p.GetLongitud() * p.GetLongitud() );

    return distancia1 < distancia2;
}

bool Punto::operator == (const Punto & p )const{
    return p.GetLatitud() == this->latitud && p.GetLongitud() == this->longitud;
}

istream & operator >> (istream & is, Punto &p){
    double input;
    is>> input;
    p.SetLatitud(input);
    is >> input;
    p.SetLongitud(input);
	return is;
}

ostream & operator << (ostream & os, const Punto &p ){
    os<<"["<<p.GetLatitud()<<" "<<p.GetLongitud()<<"]";
	return os;
}