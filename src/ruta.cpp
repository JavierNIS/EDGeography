#include "ruta.h"

//-----------Funciones iterador de ruta------------------

bool Ruta::iterator::operator!=(const iterator& i){
    return this->p != i.p;
}

Punto& Ruta::iterator::operator*(){
    return *p;
}

void Ruta::iterator::operator++(){
	++p;
}

bool Ruta::const_iterator::operator!=(const const_iterator& i) const{
    return this->p != i.p;
}
const Punto& Ruta::const_iterator::operator*() const{
    return *p;
}
void Ruta::const_iterator::operator++(){
    ++p;
}

//------------------Funciones de ruta--------------------
Ruta::Ruta(){}

void Ruta::Insertar(const Punto & n){
    Ruta::iterator it = this->begin() ;
    
    while( (*it) < n && it != this->end() ){
        ++it;
    }
    puntos.insert( it.p, n );
}

void Ruta::Borrar(const Punto & n){
    Ruta::iterator it;
    for(it=this->begin(); it != this->end(); ++it ){
        if( n== (*it) ){
            puntos.erase( it.p );
        }
    }
}

string Ruta::GetCode()const{
    return code;
}

void Ruta::SetCode(const string & c){
    code = c;
}

int Ruta::GetNPuntos()const{
    return puntos.size();
}

bool Ruta::operator==(const Ruta &R)const{
    Ruta::const_iterator it1;
    Ruta::const_iterator it2;
    bool iguales = true;

    //Si el mismo numero de puntos, los mismos puntos, y estos siguen el mismo orden,
    //entonces la ruta es igual
    if( R.GetNPuntos() == this->GetNPuntos() ){
        for(it1 = this->begin(), it2 = R.begin(); it1 != this->end() && iguales; ++it1, ++it2){
            iguales = (*it1) == (*it2);
        }
    }
}

bool Ruta::operator<(const Ruta &R)const{
    //Seguiremos el criterio de la ruta más corta
    double r1 = 0.0;
    double r2 = 0.0;

    Ruta::const_iterator it = this->begin();
    Ruta::const_iterator ant;
    ++it;
    for(ant.p = prev(it.p); it != this->end(); ++it, ++ant ){
        r1 += (*it).Distancia(*ant);
    }

    it=R.begin();
    ++it;
    for(ant.p = prev(it.p); it != R.end(); ++it, ++ant ){
        r2 += (*it).Distancia(*ant);
    }

    return r1 < r2;
}

Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end() const{
    const_iterator it;
    it.p = puntos.end();
    return it;
}

