#include "pais.h"

using namespace std;

Pais::Pais(){

}

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
    //Hay que preguntar como se implementa
    //como para el operador == estamos usando los puntos, se puede considerar el punto como 
    //la característica más importante y más razonable, por lo que para este operador de comparación
    //se debería de usar los puntos también.
    return this->p < P.p;
}

bool Pais::operator==(const Pais &P)const{
    //QUERY:No sé si debería de ser así
    //A:La comparación tiene pinta de ser con los puntos, por lo que tienes que usar el valor del punto de P
    //Aunque el compilador no daba errores, creo que daría lugar a un comportamiento indefinido.
    return P.GetPunto() == this->p;
}

bool Pais::operator==(const Punto &P)const{
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
    