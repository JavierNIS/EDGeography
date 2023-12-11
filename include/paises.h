/**
 * @file paises.h
 * @brief Fichero de cabecera de la clase Paises
 *
 * Permite el almacenamiento y gestion de muchos objetos de tipo Pais
 */

#ifndef __PAISES_H
#define __PAISES_H

#include <iostream>
#include <string>
#include <fstream>
#include "pais.h"
#include <set>

using namespace std;

/**
 * @brief Clase Paises
 *
 * @param datos Conjunto de Paises
 */
class Paises{
  private:

    set<Pais> datos;

  public:

	/**
	 * @brief Constructor por defecto de la clase paises
	 */
	Paises();

	/**
	 * @brief Funcion Insertar de la clase Paises
	 *
	 * Permite insertar el pais P en nuestro conjunto de paises
	 * 
	 * @param P Pais para insertar
	 */
	void Insertar(const Pais &P);

	/**
	 * @brief Funcion Borrar de la clase Paises
	 *
	 * Permite borrar el pais P de nuestro conjunto de paises
	 * 
	 * @param P Pais para borrar
	 */
	void Borrar(const Pais &P);
	
	class const_iterator;

	/**
	 * @brief Clase iterator de la clase Paises
	 * 
	 * @param p Iterador de un set de paises
	 */
	class iterator{
	  private:
		set<Pais>::iterator p;
	  public:
		friend class Paises;
		friend class const_iterator;
		void operator++();
		bool operator!=(const iterator& i);
		const Pais& operator*();
	}; 

	/**
	 * @brief Clase const_iterator de la clase Paises
	 * 
	 * @param p Iterador constante de un set de paises
	 */
	class const_iterator{
	  private:
		set<Pais>::const_iterator p;
	  public:
		friend class Paises;
		void operator++();
		bool operator!=(const const_iterator& i);
		const Pais& operator*();
	};

	/**
	 * @brief Funcion begin de la clase paises
	 *
	 * Devuelve un iterador que apunta al primer elemento del conjunto de paises
	 *
	 * @return iterador apuntando al primer pais del conjunto 
	 */
	iterator begin();

	/**
	 * @brief Funcion begin de la clase paises
	 *
	 * Devuelve un iterador constante que apunta al primer elemento del conjunto de paises
	 *
	 * @return iterador constante que apunta al primer pais del conjunto 
	 */
	const_iterator begin()const;

	/**
	 * @brief Funcion end de la clase paises
	 *
	 * Devuelve un iterador que apunta al último elemento del conjunto de paises
	 *
	 * @return iterador apuntando al último pais del conjunto 
	 */
	iterator end();

	/**
	 * @brief Funcion end de la clase paises
	 *
	 * Devuelve un iterador constante que apunta al último elemento del conjunto de paises
	 *
	 * @return iterador constante que apunta al último pais del conjunto 
	 */
	const_iterator end()const;
	
	/**
	 * @brief Funcion find de la clase paises
	 *
	 * Devuelve un iterador apuntando al pais buscado
	 * 
	 * @param p Pais para buscar 
	 */
	iterator find(const Pais &p);

	/**
	 * @brief Funcion find de la clase paises
	 *
	 * Devuelve un iterador apuntando al pais buscado
	 * 
	 * @param p Punto del pais para buscar 
	 */
	iterator find(const Punto &p);
	
	/**
     * @brief Guarda en un archivo de texto los paises almacenados en este objeto
     * 
     * @param nombre nombre del archivo en el que escribirán los paises
     * 
     * @return true si se ha completado exitosamente, false en cualquier otro caso
     */
    bool save(const char* nombre);

    /**
     * @brief Lee de un archivo de texto los paises almacenados
     * 
     * @param nombre nombre del archivo del que se leerán los paises
     * 
     * @return true si se ha completado exitosamente, false en cualquier otro caso
     */
    bool load(const char* nombre);

	/**
     * @brief operador de extraccion de flujo de la clase paises
     * 
     * Recoge un conjunto de paises
     *
     * @param is Flujo de salida
     * @param R paises que almacenar
     *
     * @return is (Para poder concatenar el operador)
     */ 
	friend istream & operator>>(istream & is, Paises & R);

	/**
     * @brief operador de inserccion de flujo de la clase paises
     * 
     * Muestra por pantalla el objeto Paises (un conjunto de paises)
     *
     * @param os Flujo de salida
     * @param R paises que imprimir por pantalla
     *
     * @return os (Para poder concatenar el operador)
     */ 
	friend ostream & operator<<(ostream & os, const Paises &R);
};

#endif