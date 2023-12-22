/**
 * @file Almacen_Rutas.h
 * @brief Fichero de cabecera de la clase almacen rutas
 *
 * Permite el almacenamiento y la gestión de objetos de tipo ruta
 */

#ifndef _ALMACEN_RUTAS_
#define _ALMACEN_RUTAS_
#include "ruta.h"
#include <map>
#include <fstream>
#include <cassert>

using namespace std;

/**
 * @brief Clase almacen rutas. Esta clase se encarga de almacenar y manejar varias rutas.
 * 
 * @param rutas Un diccionario de claves string y rutas
 */

class Almacen_Rutas{
    map<string, Ruta> rutas;

public:
    /**
    * @brief Constructor por defecto de la clase almacen ruta
    */
    Almacen_Rutas();

    const int getNRutas() const;

    /**
    * @brief Inserta una ruta en el almacen de rutas
    * 
    * No se sigue ningún criterio de ordenamiento
    *
    * @param R ruta a insertar
    */
    void Insertar(const Ruta& R);

    /**
    * @brief Borra una ruta del almacen de rutas
    *
    * @param R ruta a borrar
    */
    void Borrar(const Ruta& R);

    /**
    * @brief Devuelve una copia de la ruta
    *
    * Se busca en el almacen una ruta cuya clave sea @p a
    * 
    * @param a Clave de la ruta que se busca
    * 
    * @return Una copia a la ruta, si se encuentra.
    */
    Ruta GetRuta(const string& a);

    /**
    * @brief Clase iterator de la clase almacen ruta
    * 
    * @param p Iterador de un diccionario de claves string y rutas
    */
    class iterator{
        map<string, Ruta>::iterator p;
    public:
        friend class Almacen_Rutas;
        friend class const_iterator;
        bool operator!=(const iterator &i);
        pair<const string, Ruta>& operator*();
        void operator++();
    };
    
    /**
    * @brief Clase const_iterator de la clase almacen ruta
    * 
    * @param p Iterador constante de un diccionario de claves string y rutas
    */

    class const_iterator{
        map<string, Ruta>::const_iterator p;
    public:
        friend class Almacen_Rutas;
    };

    /**
     * @brief Función begin de la clase almacen rutas
     * 
     * Indica el primer elemento del diccionario
     * 
     * @return iterador que apunta al primer elemento del diccionario
     */
    iterator begin();

    /**
     * @brief Función begin de la clase almacen rutas
     * 
     * Indica el primer elemento del diccionario
     * 
     * @return iterador constante que apunta al primer elemento del diccionario
     */
    const_iterator begin() const;

    /**
     * @brief Función end de la clase almacen rutas
     * 
     * Indica el final del diccionario
     * 
     * @return iterador que apunta al final del diccionario
     */
    iterator end();

    /**
     * @brief Función end de la clase almacen rutas
     * 
     * Indica el final del diccionario
     * 
     * @return iterador constante que apunta al final del diccionario
     */
    const_iterator end() const;

    /**
     * @brief Guarda en un archivo de texto las rutas almacenadas en este objeto
     * 
     * @param nombre nombre del archivo en el que escribirá el almacen de rutas
     * 
     * @return true si se ha completado exitosamente, false en cualquier otro caso
     */
    bool save(const char* nombre);

    /**
     * @brief Lee de un archivo de texto las rutas almacenadas
     * 
     * @param nombre nombre del archivo del que se leerán las rutas
     * 
     * @return true si se ha completado exitosamente, false en cualquier otro caso
     */
    bool load(const char* nombre);

    /**
    * @brief operador de extracción de flujo de la clase almacen rutas
    *
    * @param is Flujo de donde extraer los datos
    * @param AR almacen rutas donde se guardarán los datos
    *
    * @return is, una referencia a la extracción de flujos para permitir concatenación
    */
    friend istream& operator>> (istream& is, Almacen_Rutas & AR);

    /**
    * @brief operador de insercción de flujo de la clase almacen rutas
    *
    * @param os Flujo donde se introducirán los datos
    * @param AR almacen rutas de donde se extraerán los datos
    *
    * @return os, una referencia a la insercción de flujos para permitir concatenación
    */
    friend ostream& operator<< (ostream& os, Almacen_Rutas & AR);
};

#endif
/* Fin Fichero: Almacen_Rutas.h */