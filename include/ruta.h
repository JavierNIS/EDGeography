/**
 * @file Ruta.h
 * @brief Fichero de cabecera de la clase ruta
 *
 * Permite el almacenamiento y la gestión de objetos de tipo ruta
 */

#ifndef __RUTAS_H
#define __RUTAS_H

#include <iostream>
#include <string>
#include <list>
#include "punto.h"

using namespace std;

class Ruta{
 private:
    list<Punto> puntos;
    string code;
 public:
    Ruta();
    void Insertar(const Punto & n);
    void Borrar(const Punto & n);

    string GetCode() const;
    void SetCode(const string & c);

    int GetNPuntos()const;

    bool operator==(const Ruta &R)const;
    bool operator<(const Ruta &R)const;

    class iterator{
     private:
        list<Punto>::iterator p;
     public:
        friend class Ruta;
		friend class const_iterator;
    };
    class const_iterator{
     private:
        list<Punto>::cons_iterator p;
     public: 
        friend class Ruta;

    };

    iterator begin();
    const_iterator begin()const;
    iterator end();
    const_iterator end() const;

    friend istream & operator >>(istream & is, Ruta &R);
    friend ostream & operator <<(ostream & os, const Ruta & R);
}
 