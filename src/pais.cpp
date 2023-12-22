/**
  * @file pais.cpp
  * @brief Fichero con definiciones de la clase Pais
  *
  */

#include "pais.h"

using namespace std;

Pais::Pais(){}

Punto Pais::GetPunto() const{
    return p;
}

string Pais::GetPais()const{
    return pais;
}

string Pais::GetBandera()const{
    return bandera;
}

bool Pais::operator<(const Pais &P)const{
    //Comparamos el punto de los paises
    return this->p < P.p;
}

bool Pais::operator==(const Pais &P)const{
    //Comparamos los paises por sus puntos
    return P.GetPunto() == this->p;
}

bool Pais::operator==(const Punto &P)const{
    //Comparamos el punto del pais con el punto
    return P == this->p;
}

istream & operator>>(istream & is, Pais & P){
    double lat,lng;
	
	is>>lat>>lng>>P.pais>>P.bandera;
	
	P.p=Punto(lat,lng,"");
	return is;
}

ostream & operator<<(ostream & os, const Pais &P){
    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
}
    