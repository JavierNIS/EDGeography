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

bool Punto::operator < (const Punto & p )const{
    //Hay que preguntar como se implementa
    //voy a hacer una implementación, después me dices que te parece
    double difflat=0.0, difflong=0.0;
    //guardamos que tan próximos son los puntos en latitud y longitud
    difflat = this->GetLatitud() - p.GetLatitud();
    difflong = this->GetLongitud() - p.GetLongitud();

    //si son más próximos en latitud, entonces comparamos por longitudes
    if(abs(difflong) >= abs(difflat))
        return difflat < 0;
    else
        return difflong < 0;
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