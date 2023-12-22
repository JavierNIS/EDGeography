#include <iostream>
#include <string>

#include "imagen.h"
#include "Almacen_Rutas.h"
#include "paises.h"

using namespace std;
typedef pair<int, int> pixels;




pixels traslacionCoords(const Punto& P, int maxfil, int maxcol){
    pixels colyfila;
    colyfila.second=abs((maxcol/360)*(180+P.GetLongitud()));
    colyfila.first=abs((maxfil/180)*(90-P.GetLatitud()));
    return colyfila;
}
//./datos/paises.txt ./datos/imagenes/mapas/mapa1.ppm ./datos/imagenes/banderas/ ./datos/almacen_rutas.txt ./datos/imagenes/aviones/avion1.ppm ./datos/imagenes/aviones/mascara_avion1.pgm

//g++ -g -o ruta_aerea ./rutas_aereas/src/Almacen_Rutas.cpp ./rutas_aereas/src/imagen.cpp ./rutas_aereas/src/imagenES.cpp ./rutas_aereas/src/pais.cpp ./rutas_aereas/src/paises.cpp ./rutas_aereas/src/punto.cpp ./rutas_aereas/src/ruta_aerea.cpp ./rutas_aereas/src/ruta.cpp -I./rutas_aereas/include

int main(int argc , char *argv[]){
    

    if(argc != 7 ){
        cout<<"Los parámetros son:"<<endl;
        cout<<"1.- El nombre del fichero que contiene el conjunto de países"<<endl;
        cout<<"2.- El nombre del fichero de la imagen mapa"<<endl;
        cout<<"3.- El nombre del directorio donde están las banderas "<<endl;
        cout<<"4.- El nombre del fichero que contiene las rutas"<<endl;
        cout<<"5.- El nombre de la imagen del avión para usar"<<endl;
        cout<<"6.- El nombre de la imagen que contiene la máscara del avión"<<endl;
        return 1;
    }
    
    Paises paises;
    Almacen_Rutas almacen;
    Ruta ruta;
    string codigo;
    Imagen mapa, avion;

    if(paises.load(argv[1])){
        cerr << "Error al cargar los paises" << endl;
        return 1;
    }
    if(!almacen.load(argv[4])){
        cerr << "Error al cargar las rutas" << endl;
        return 1;
    }
    mapa.LeerImagen(argv[2]);
    avion.LeerImagen(argv[5], argv[6]);

    char bufferc;
    int bufferint;
    string buffertext;

    cout << "Elija una de las siguientes rutas: " << endl << almacen << endl << endl;
    
    cout << "Inserte la ruta que desea imprimir en la imagen: ";
    cin >> bufferc >> bufferint;

    while(bufferc != 'R' || bufferint >= almacen.getNRutas()+1){
        cout << "Formato de ruta incorrecto, vuelva a intentarlo: ";
        cin >> bufferc >> bufferint;
    }

    buffertext+=bufferc;
    buffertext+=to_string(bufferint);
    ruta = almacen.GetRuta(buffertext);

    Ruta::const_iterator rutait;
    Paises::iterator paisesit;
    rutait = ruta.begin();

    string direccionbandera;
    pixels pixeles[2];
    short int numpais=0;
    Imagen bandera[2];


    direccionbandera=argv[3];
    paisesit=paises.find(*rutait);
    assert(paisesit != paises.end());

    direccionbandera+=(*paisesit).GetBandera();
    pixeles[numpais]=traslacionCoords(*rutait, mapa.num_filas(), mapa.num_cols());
    bandera[0].LeerImagen(direccionbandera.c_str());
    ++numpais;
    ++rutait;

    for(; rutait != ruta.end(); ++rutait, ++numpais){
        
        direccionbandera=argv[3];
        paisesit=paises.find(*rutait);
        assert(paisesit != paises.end());

        direccionbandera+=(*paisesit).GetBandera();
        pixeles[numpais%2]=traslacionCoords(*rutait, mapa.num_filas(), mapa.num_cols());
        bandera[numpais%2].LeerImagen(direccionbandera.c_str());

        Pintar(pixeles[numpais%2].first, pixeles[(numpais+1)%2].first, pixeles[numpais%2].second, pixeles[(numpais+1)%2].second, 
        mapa, avion, (pixeles[(numpais+1)%2].first-pixeles[numpais%2].first)/2, (pixeles[(numpais+1)%2].second-pixeles[numpais%2].second)/2);
        mapa.PutImagen(pixeles[numpais%2].first, pixeles[numpais%2].second, bandera[numpais%2], BLENDING);
        if(numpais == 1)
            mapa.PutImagen(pixeles[0].first, pixeles[0].second, bandera[0], BLENDING);
        
    }

    cout << "Hecho" << endl;
    mapa.EscribirImagen("mapaconrutas");
    
    return 0;
}