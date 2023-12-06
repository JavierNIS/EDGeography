/**
 * @file Punto.h
 * @brief Fichero cabecera de la clase Punto
 *
 * Permite la gestión de los objetos Punto
 */

#ifndef __PUNTO_H
#define __PUNTO_H

/**
  * @brief Clase punto
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
     * @brief Constructor por defecto de la clase punto
     */
    Punto();

    /**
     * @brief Constructor por parámetros de la clase punto
     *
     * @param la Latitud del punto
     * @param lo Longitud del punto
     * @param d \\\\\\\\\\\\\\
     */
    Punto( double la, double lo, const string & d );

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
     * @brief operador "menor que" de la clase punto
     * 
     * @param p punto con el que comparar
     *
     * @return true si _____ false si no
     */
    bool operator < (const Punto & p) const;

    /**
     * @brief operador igual de la clase punto
     * 
     * @param p punto con el que comparar
     *
     * @return true si los dos puntos tienen las mismas coordenadas, false si no
     */
    bool operator == (const Punto & p ) const;

    /**
     * @brief operador de inserccion de flujo la clase punto
     * 
     * Recoge los datos necesarios para construir un objeto de la clase punto
     * @param is Flujo de entrada
     * @param p punto que almacenar
     *
     * @return is (Para poder concatenar el operador)
     */  
    friend istream & operator >> (istream & is, Punto &p);

    /**
     * @brief operador de extraccion de flujo de la clase punto
     * 
     * Muestra por pantalla el objeto punto
     * @param os Flujo de salida
     * @param p punto que imprimir por pantalla
     *
     * @return os (Para poder concatenar el operador)
     */ 
    friend ostream & operator << (ostream & os, const Punto &p );
}

#endif