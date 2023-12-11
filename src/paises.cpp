#include "paises.h"

Paises::Paises(){}

void Paises::Insertar( const Pais &P){
	datos.insert( P);
}

void Paises::Borrar( const Pais &P){
	datos.erase(P);
}

Paises::iterator Paises::begin(){
	iterator it;
	it.p = datos.begin();
	return it;
}  

Paises::const_iterator Paises::begin()const{
	const_iterator it;
	return it;
}
Paises::iterator Paises::end(){
	iterator it;
	it.p = datos.end();
	return it;
}
Paises::const_iterator Paises::end()const{
	const_iterator it;
	it.p = datos.end();
	return it;
}
Paises::iterator Paises::find(const Pais &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
		it.p=i;
	return it;
}
Paises::iterator Paises::find(const Punto &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i).GetPunto() ==p );++i);
		it.p=i;
	return it;
}

void Paises::const_iterator::operator++(){
	++p;
}
bool Paises::const_iterator::operator!=(const const_iterator& i){
	return i.p != this->p;
}
const Pais& Paises::const_iterator::operator*(){
	return *p;
}


istream & operator>>(istream & is, Paises & R){
	Paises rlocal;
	//leemos el comentario
	if (is.peek()=='#'){
		string a;
		getline(is,a);
	}	
	
	Pais P;
	while (is>>P){
		rlocal.Insertar(P);
	}
	R=rlocal;
	return is;
}
ostream & operator<<(ostream & os, const Paises &R){
    
    Paises::const_iterator it;
    for (it=R.begin(); it!=R.end(); ++it){
    	os<<*it<<"\t";
    }
    return os;
}