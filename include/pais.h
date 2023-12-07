/**
 * @file Pais.h
 * @brief fichero de cabecera de la clase Pais
 *
 * Permite el almacenamiento y la gestion de objetos Pais
 *
 */

#ifndef __PAIS_H
#define __PAIS_H

#include "punto.h"



/**
 * @brief Clase Pais
 * 
 * @param p Coordenadas de localizacion del pais
 * @param pais String que almacena el nombre del pais
 * @param bandera String que guarda la bandera del pais
 */
class Pais{
  private:

    Punto p;
    string pais;
    string bandera;
    
  public:

    /**
     * @brief Constructor por defecto de la clase pais
     *
     */  
    Pais();
    
    /**
     * @brief Funcion auxiliar para obtener las coordenadas de un pais
     *
     * @return p 
     */
    Punto GetPunto()const;

    /**
     * @brief Funcion auxiliar para obtener el nombre del pais
     *
     * @return pais
     */
    string GetPais()const;

    /**
     * @brief Funcion auxiliar para obtener la bandera del pais
     * 
     * @return bandera
     */
    string GetBandera()const;
    
    /**
     * @brief operador menor que de la clase pais
     * 
     * @param P pais para comparar
     */
    bool operator<(const Pais &P)const;

    /**
     * @brief operador igual de la clase pais
     * 
     * @param P pais para comparar
     */
    bool operator==(const Pais &P)const;
    
    /**
     * @brief operador igual de la clase pais 
     * 
     * @param P punto para comparar
     */
    bool operator==(const Punto &P)const;

    /**
     * @brief operador de extraccion de flujo de la clase pais
     * 
     * Recoge los datos necesarios para construir un objeto pais
     *
     * @param is Flujo de salida
     * @param P pais que almacenar
     *
     * @return is (Para poder concatenar el operador)
     */ 
    friend istream & operator>>(istream & is, Pais & P);

    /**
     * @brief operador de extraccion de flujo de la clase pais
     * 
     * Muestra por pantalla el objeto pais
     *
     * @param os Flujo de salida
     * @param P pais que imprimir por pantalla
     *
     * @return os (Para poder concatenar el operador)
     */ 
    friend ostream & operator<<(ostream & os, const Pais &P);
    
};

#endif