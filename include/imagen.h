/**
 * @file Imagen.h
 * @brief Fichero de cabecera de la clase imagen
 *
 * Permite el almacenamiento y gestion de una imagen 
 */

#ifndef __IMAGEN_H
#define __IMAGEN_H

#include <string>

enum Tipo_Pegado {OPACO, BLENDING};
/**
 * @brief struct que almacena los valores de un pixel
 *
 * @param r Valor entre 0 y 255 que muestra el valor de la componente roja
 * @param g Valor entre 0 y 255 que muestra el valor de la componente verde
 * @param b Valor entre 0 y 255 que muestra el valor de la componente azul
 * @param transparencia 0 si es transparente 255 si no
 */
struct Pixel{
unsigned char r,g,b;
unsigned char transparencia;
};

/**
 * @brief Clase imagen
 *
 * Permite almacenar y gestionar objetos de tipo imagen
 *
 * @param datos Puntero a puntero a pixel que constituirá la matriz para almacenar todos los pixeles
 * @param nf Numero de filas de la imagen
 * @param nc Numero de columnas de la imagen
 */

class Imagen{
 private:
    Pixel **datos; //donde se almacena la información de la imagen. Otra posible representación
    //Pixel*datos
    int nf,nc;

    /**
     * @brief 
     */
    void Borrar();

    /**
     * @brief 
     */
    void Copiar(const Imagen &I);
 public:
    
    /**
     * @brief Constructor por defecto de la clase Imagen
     */
    Imagen();

    /**
     * @brief Constructor por parametros de la clase imagen
     *
     * @param f Numero de filas de la imagen
     * @param c Numero de columnas de la imagen
     */
    Imagen (int f,int c); 

    /**
     * @brief Constructor de copia de la clase imagen
     *
     * @param I Imagen a partir de la cual construimos el objeto
     */
    Imagen(const Imagen &I);

    /**
     * @brief Operador de asignación de la clase Imagen
     */
    Imagen & operator =(const Imagen & I);

    /**
     * @brief Destructor de la clase imagen
     * 
     */
    ~Imagen();
    
    /**
     * @brief operador () de la clase imagen
     * 
     * Devuelve una referencia al pixel de la posicion i, j
     *
     * @param i Numero de fila del pixel
     * @param j Numero de columna del pixel
     */
    Pixel & operator()(int i,int j); 

    /**
     * @brief operador () de la clase imagen
     * 
     * Devuelve una referencia constante al pixel de la posicion i, j 
     *
     * @param i Numero de fila del pixel
     * @param j Numero de columna del pixel
     */
    const Pixel & operator()(int i,int j)const;

    /**
     * @brief Escribe en disco una imagen
     * 
     * @param nombre Puntero apuntando a la imagen
     */    
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee de disco una imagen
     * 
     * @param nomnre Puntero apuntando a la imagen
     * @param nombremascara //NO SE QUE ES
     */
    void LeerImagen (const char *nombre,const std::string &nombremascara="");
    
    /**
     * @brief 
     */
    void LimpiarTransp();

    /**
     * @brief Funcion auxiliar GetFilas de la clase Imagen
     * 
     * @return nf Numero de filas de la imagen
     */
    int num_filas()const;

    /**
     * @brief Funcion auxiliar GetCols de la clase Imagen
     * 
     * @return nc Numero de columnas de la imagen
     */
    int num_cols()const;

    /**
     * @brief 
     */
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
    
    /**
     * @brief 
     */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};

#endif