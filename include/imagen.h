/**
 * @file Imagen.h
 * @brief Fichero de cabecera de la clase imagen
 *
 * Permite el almacenamiento y gestion de una imagen 
 */

#ifndef __IMAGEN_H
#define __IMAGEN_H
#include <imagenES.h>
#include <iostream>
#include <cassert>

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
   Pixel **data; //donde se almacena la información de la imagen. Otra posible representación
   //Pixel*datos
   int nf,nc;
   
   void Asignar( int f, int c, Pixel * buffer=0);
   /**
    * @brief Función auxiliar
    *
    * Incializa las variables privadas
    */
   void Inicializar( int f = 0, int c=0, Pixel * buffer=0);

  /**
   * @brief Funcion auxiliar 
   *
   * Copia los datos de una imagen en los datos privados
   */
  void Copiar(const Imagen &I);
  
  bool Empty() const;

  /**
   * @brief Funcion auxiliar
   *
   * Borra los datos de la imagen
   */
  void Borrar();

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
    * @param nombremascara Mascara que indica donde se encuentran los objetos de una imagen
    */
   void LeerImagen (const char *nombre,const std::string &nombremascara="");
    
   /**
    * @brief Limpia la transparencia de la imagen
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

   class const_iterator;

	/**
	 * @brief Clase iterator de la clase Imagen
	 * 
	 * @param p Puntero apuntando a un pixel
	 */
	class iterator{
	  private:
      Pixel * p;
      Imagen *I;
	  public:
		  friend class Imagen;
		  friend class const_iterator;
      
      /**
       * @brief Constructor de la clase iterador
       */     
      iterator(){
        p = 0;
        I = 0;
      }

      /**
       * @brief Constructor de copia de la clase iterador
       */
      iterator(const const_iterator &it ){
        if ( *this != it ) {
          p = const_cast <Pixel *> ( it.p ) ;
          I = const_cast <Imagen *> ( it.I ) ;
        }
      }  
      /**
       * @brief Destructor de la clase iterador
       */
      ~iterator(){
        p = 0;
        I = 0;
      }

      /**
       * @brief Operador ++ de la clase iterador
       *
       * @return Devuelve un iterador apuntando al siguiente elemento
       */
      iterator & operator++(){
        if( p != I->end().p )
          p + 1;

        return *this;
      }
      
      Pixel & operator *(){
        return *p;
      }

      const Pixel & operator*() const{
        return *p;
      }

      /**
       * @brief Operador != de la clase iterador
       *
       * @return Devuelve un iterador apuntando al siguiente elemento
       */
      bool operator!=(const iterator & it){
        return  it.p != this->p && it.I != this->I;
      }

      /**
       * @brief Operador != de la clase iterador
       *
       * @return Devuelve un iterador apuntando al siguiente elemento
       */
      bool operator!=(const const_iterator & it){
        return  it.p != this->p && it.I != this->I;
      }

	}; 

	/**
	 * @brief Clase const_iterator de la clase Imagen
	 * 
	 * @param p Punto apuntando a un pixel
	 */
	class const_iterator{
	  private:
		  const Pixel * p;
      const Imagen * I;
	  public:
		  friend class Imagen;

      /**
       * @brief Constructor de la clase const_iterador
       */     
      const_iterator(){
        p = 0;
        I = 0;
      }

      /**
       * @brief Constructor de copia de la clase const_iterator
       */
      const_iterator & operator = (const iterator & it){
        this->p = it.p;
        this->I = it.I;
        return *this;
      }

      /**
       * @brief Destructor de la clase const_iterador
       */ 
      ~const_iterator(){
        p =0;
      }

    /**
       * @brief Operador != de la clase const_iterador
       *
       * @return Devuelve un iterador constante apuntando al siguiente elemento
       */
      bool operator!=(const iterator & it){
        return  it.p != this->p && it.I != this->I;
      }

      /**
       * @brief Operador != de la clase connst_iterador
       *
       * @return Devuelve un iterador constante apuntando al siguiente elemento
       */
      bool operator!=(const const_iterator & it){
        return  it.p != this->p && it.I != this->I;
      }
	};

	/**
	 * @brief Funcion begin de la clase imagen
	 *
	 * Devuelve un iterador que apunta al primer pixel de una imagen
	 *
	 * @return iterador apuntando al primer pixel de una imagen
	 */
	iterator begin();

	/**
	 * @brief Funcion begin de la clase paises
	 *
	 * Devuelve un iterador constante que apunta al primer pixel de una imagen
	 *
	 * @return iterador constante que apunta al primer pixel de una imagen
	 */
	const_iterator begin()const;

	/**
	 * @brief Funcion end de la clase paises
	 *
	 * Devuelve un iterador que apunta al último pixel de una imagen
	 *
	 * @return iterador apuntandoal último pixel de una imagen
	 */
	iterator end();

	/**
	 * @brief Funcion end de la clase paises
	 *
	 * Devuelve un iterador constante que apunta al último pixel de una imagen
   *
	 * @return iterador constante que apunta al último pixel de una imagen
	 */
	const_iterator end()const;
};

#endif