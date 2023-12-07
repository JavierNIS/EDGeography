#include "paises.h"

Paises::Paises(){}

void Paises::Insertar( const Pais &P){
	datos.insert( P);
}

void Paises::Borrar( const Pais &P){
	datos.erase(P);
}

Paises::iterator begin(){
	iterator it;
	it.p = datos.begin();
	return it;
}  

Paises::const_iterator begin()const{
	const_iterator it;
	it.p = datos.begin();
	const_iterator i = it;
	return i;
}
Paises::iterator end(){
	iterator it;
	it.p = datos.end();
	return it;
}
Paises::const_iterator end()const{
	iterator it;
	it.p = datos.end();
	const_iterator i = it;
	return i;
}
Paises::iterator find(const Pais &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
		it.p=i;
	return it;
}
Paises::iterator find(const Punto &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i).GetPunto() ==p );++i);
		it.p=i;
	return it;
}

friend istream & operator>>(istream & is, Paises & R){
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
friend ostream & operator<<(ostream & os, const Paises &R){
    
    Paises::const_iterator it;
    for (it=R.begin(); it!=R.end(); ++it){
    	os<<*it<<"\t";
    }
    return os;
}