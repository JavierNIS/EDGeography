#include "imagen.h"

#include <iostream>

using namespace std;

//Private:
void Imagen::Borrar(){

}

void Imagen::Copiar(const Imagen & I){

}

//Public::
Imagen::Imagen(){

}

Imagen::Imagen (int f,int c){
    
}

Imagen::Imagen(const Imagen &I){

}

Imagen & Imagen::operator =(const Imagen & I){

}

Imagen::~Imagen(){

}

Pixel & Imagen::operator()(int i,int j){
    
}

const Pixel & Imagen::operator()(int i,int j)const{
    
}

void Imagen::EscribirImagen(const char * nombre){

}

void Imagen::LeerImagen (const char *nombre,const string &nombremascara){

}

void Imagen::LimpiarTransp(){
 
}

int Imagen::num_filas()const
{
    return nf;
}

int Imagen::num_cols()const
{
    return nc;
}

void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){

}

Imagen Imagen::ExtraeImagen(int posi,int posj,int dimi,int dimj){

}