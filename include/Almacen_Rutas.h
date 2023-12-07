#ifndef _ALMACEN_RUTAS_
#define _ALMACEN_RUTAS_
#include "Ruta.h"
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Almacen_Rutas{
    map<string, Ruta> rutas;

public:
    Almacen_Rutas();

    void Insertar(const Ruta& R);
    void Borrar(const Ruta& R);

    Ruta GetRuta(const string& a);

    class iterator{
        map<string, Ruta>::iterator p;
    public:
        friend class Almacen_Rutas;
        friend class const_iterator;
    };
    class const_iterator{
        map<string, Ruta>::const_iterator p;
    public:
        friend class Almacen_Rutas;
    };

    iterator begin();
    const iterator begin() const;
    iterator end();
    const iterator end() const;

    bool save(const char* nombre);
    bool load(const char* nombre);

    friend istream& operator>> (istream& is, Almacen_Rutas & AR);
    friend ostream& operator<< (ostream& os, Almacen_Rutas & AR);
};

#endif