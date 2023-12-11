/**
 * @file ruta.h
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

/**
 * @brief clase Ruta
 * 
 * Permite almacenar y gestionar objetos de tipo Ruta
 *
 * @param puntos  Lista de puntos que conforman una ruta
 * @param code Código de la ruta
 */
class Ruta{
 private:
    list<Punto> puntos;
    string code;
 public:

   /**
    * @brief Constructor por defecto de la clase ruta
    */
   Ruta();

   /**
    * @brief Función insertar de la clase Ruta
    * 
    * Inserta un elemento en la lista puntos en orden de menor a mayor
    *
    * @param n Punto para insertar
    */
   void Insertar(const Punto & n);

   /**
    * @brief Función borrar de la clase Ruta
    * 
    * Borra un punto de la lista las veces que esté repetido
    *
    * @param n Punto para borrar
    */
   void Borrar(const Punto & n);

   /**
    * @brief Función GetCode de la clase Ruta
    * 
    * Devuelve el código de la ruta
    *
    * @return code
    */
   string GetCode() const;

   /**
    * @brief Función SetCode de la clase Ruta
    * 
    * Establece un valor nuevo para code
    *
    * @param c Valor para code
    */
   void SetCode(const string & c);

   /**
    * @brief Función GetNPuntos de la clase ruta
    * 
    * @return Devuelve el número de puntos contenidos en la lista puntos
    */
   int GetNPuntos()const;

   /**
    * @brief operador == De la clase Ruta
    *
    * @return true si el numero de puntos, los puntos y el orden de los mismos
    *         es igual en ambas rutas
    */
   bool operator==(const Ruta &R)const;

   /**
    * @brief operador < de la clase Ruta
    * 
    * @return true si la distancia de la primera ruta es menor que la segunda
    */
   bool operator<(const Ruta &R)const;
   
   /**
    * @brief Clase iterator de la clase ruta
    * 
    * @param p Iterador de una lista de puntos
    */
   class iterator{
    private:
      list<Punto>::iterator p;
    public:
      friend class Ruta;
      friend class const_iterator;
   };

   /**
    * @brief Clase const_iterator de la clase Ruta
    * 
    * @param p Iterador constante de la clase Ruta
    */
   class const_iterator{
    private:
      list<Punto>::const_iterator p;
    public: 
      friend class Ruta;

   };

   /**
    * @brief Función begin de la clase ruta
    * 
    * @return iterador apuntando al primer elemento de la lista de puntos
    */
   iterator begin();

   /**
    * @brief Función begin de la clase ruta
    * 
    * @return iterador constante apuntando al primer elemento de la lista de puntos
    */
   const_iterator begin()const;

   /**
    * @brief Función end de la clase ruta 
    * 
    * @return iterador apuntando al último elemento de la lista de puntos
    */
   iterator end();

   /**
    * @brief Función end de la clase ruta
    * 
    * @return iterador constante apuntando al último elemento de la lista de puntos
    */
   const_iterator end() const;

   /**
    * @brief operador de extracción de flujo de la clase Ruta
    *
    * @param is Flujo de donde extraer los datos
    * @param R Ruta donde guardar
    *
    * @return is
    */
   friend istream & operator >>(istream & is, Ruta &R);

   /**
    * @brief operador de insercción de flujo de la clase Ruta
    *
    * @param is Flujo de donde insertar los datos
    * @param R Ruta que mostrar por pantalla
    *
    * @return os
    */
   friend ostream & operator <<(ostream & os, const Ruta & R);
};

#endif
 