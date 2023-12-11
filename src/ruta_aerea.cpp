#include <iostream>
#include <string>

#include "imagen.h"
#include "Almacen_Rutas.h"

using namespace std;

int main(int argc , char *argv[]){
    
    if(argc != 7 ){
        cout<<"Los parámetros son:"<<endl;
        cout<<"1.- El nombre del fichero que contiene el conjunto de países"<<endl;
        cout<<"2.- El nombre del fichero de la imagen mapa"<<endl;
        cout<<"3.- El nombre del directorio donde están las banderas "<<endl;
        cout<<"4.- El nombre del fichero que contiene las rutas"<<endl;
        cout<<"5.- El nombre de la imagen del avión para usar"<<endl;
        cout<<"6.- El nombre de la imagen que contiene la máscara del avión"<<endl;
        return 0;
    }
    
    Almacen_Rutas almacen;
    Ruta r;
    string codigo;
    Imagen mapa, avion;


    mapa.LeerImagen(argv[2]);

    almacen.load( argv[4]);
    avion.LeerImagen(argv[5], argv[6]);
    
    return 0;
}