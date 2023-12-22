/**
  * @file punto.cpp
  * @brief Fichero con definiciones de la clase Punto
  *
  */
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

double Punto::Distancia( const Punto &p ) const{
    return sqrt( pow(this->latitud - p.GetLatitud() ,2) + pow( this->longitud - p.GetLongitud() ,2) );
}

bool Punto::operator < (const Punto & p )const{
    //El criterio que determinamos para que un punto sea menor que otro 
    //será en función a su distancia respecto al 0 0
    Punto p0; //Por defecto tiene latitud y longitud 0
    double distancia1 = this->Distancia( p0);
    double distancia2= p.Distancia(p0);

    return distancia1 < distancia2;
}

bool Punto::operator == (const Punto & p )const{
    return p.GetLatitud() == this->latitud && p.GetLongitud() == this->longitud;
}

istream & operator >> (istream & is, Punto &p){
    pair<double, double> input;
    char buffer;

    is>> buffer >> input.first >> buffer >> input.second >> buffer;
    p.SetLatitud(input.first);
    p.SetLongitud(input.second);
	return is;
}

ostream & operator << (ostream & os, const Punto &p ){
    os<<"("<<p.GetLatitud()<<","<<p.GetLongitud()<<")";
	return os;
}