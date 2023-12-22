/**
  * @file pruebarotacion.cpp
  * @brief Fichero que contiene un programa pequeño para comprobar la rotación de imágenes
  *
  */
#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


int main(int argc, char * argv[]){
  if (argc!=4){
    cout<<"Los parametros son :"<<endl;
    cout<<"1.-La imagen de entrada"<<endl;
    cout<<"2.-El angulo de rotación"<<endl;
    cout<<"3.-El nombre de la imagen de salida"<<endl;
    return 0;
  }
  Imagen I;
  I.LeerImagen(argv[1]);
  double angulo=atof(argv[2]);
  angulo = angulo*(M_PI)/180;
  Imagen Iout=Rota(I,angulo);
  Iout.EscribirImagen(argv[3]);
  
}  