/**
  * @file punto.h
  * @brief Fichero cabecera de la clase Punto
  *
  * Permite la gestión de los objetos Punto
  */

#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
/**
  * @brief Clase Punto
  * 
  * Permite almacenar y gestionar objetos de tipo punto
  *
  * @param latitud Coordenada y del punto (desplazamiento vertical)
  * @param longitud Coordenada x del punto (desplazamiento horizontal)
  */
class Punto{
  private:
    double latitud, longitud;

  public:
    /**
     * @brief Constructor por defecto de la clase Punto
     */
    Punto();

    /**
     * @brief Constructor por parámetros de la clase Punto
     *
     * @param la Latitud del punto
     * @param lo Longitud del punto
     * @param d \\\\\\\\\\\\\\
     */
    Punto( double la, double lo, const string & d = "" );

    /**
     * @brief Función auxiliar para obtener la latitud del punto
     *
     * @return latitud
     */
    double GetLatitud()const;

    /**
     * @brief Función auxiliar para obtener la longitud del punto
     *
     * @return longitud
     */
    double GetLongitud() const;

    /**
     * @brief Función auxiliar para introducir el valor de la latitud
     * 
     * @param la El valor para la variable latitud que se desea guardar
     */
    void SetLatitud(double la);

    /**
     * @brief Función auxiliar para introducir el valor de la longitud
     * 
     * @param la El valor para la variable latitud que se desea guardar
     */
    void SetLongitud(double lo);

    /**
     * @brief funcion auxiliar para calcular la distancia entre un punto y otro
     *
     * @param p punto con el que calcular la distancia
     *
     * @return double con la distancias
     */
     double Distancia( const Punto &p) const;

    /**
     * @brief operador "menor que" de la clase Punto
     * 
     * @param p punto con el que comparar
     *
     * @return true si _____ false si no
     */
    bool operator < (const Punto & p) const;

    /**
     * @brief operador igual de la clase Punto
     * 
     * @param p punto con el que comparar
     *
     * @return true si los dos puntos tienen las mismas coordenadas, false si no
     */
    bool operator == (const Punto & p ) const;

    /**
     * @brief operador de extraccion de flujo la clase Punto
     * 
     * Recoge los datos necesarios para construir un objeto de la clase Punto
     * @param is Flujo de entrada
     * @param p punto que almacenar
     *
     * @return is (Para poder concatenar el operador)
     */  
    friend istream & operator >> (istream & is, Punto &p);

    /**
     * @brief operador de inserccion de flujo de la clase Punto
     * 
     * Muestra por pantalla el objeto punto
     * @param os Flujo de salida
     * @param p punto que imprimir por pantalla
     *
     * @return os (Para poder concatenar el operador)
     */ 
    friend ostream & operator << (ostream & os, const Punto &p );
};

#endif
/* Fin Fichero: punto.h */