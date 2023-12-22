#include "imagen.h"

using namespace std;

//Private:

void Imagen::Asignar( int f, int c, Pixel * buffer){
    nf = f;
    nc = c;

    data = new Pixel * [nf];

    if (buffer != 0){
        data[0] = buffer;
    }else{
        data[0] = new Pixel [ nf * nc];
    }
    for(int i=1; i< nf; i++){
        data[i] = data [i-1] + nc;
    }
}

//---------------------------------------

void Imagen::Inicializar( int f, int c, Pixel * buffer){
    if ((f == 0) || (c == 0)){
        nf = nc = 0;
        data = 0;
    }
    else Asignar(f, c, buffer);
}

//---------------------------------------

void Imagen::Copiar(const Imagen & I){
    Inicializar(I.nf , I.nc);

    for(int i=0; i < nf; i++){
        for(int j=0; j < nc; j++){
            data[i][j] = I(i, j);
        }
    }
    
}

//---------------------------------------

bool Imagen::Empty() const{
    return (nf == 0) || (nc == 0);
}

//---------------------------------------

void Imagen::Borrar(){
    if(!Empty() ){
        delete [] data[0];
        delete [] data;
    }
}

//Public::

Imagen::Imagen (){
    Inicializar();
}

//---------------------------------------

Imagen::Imagen(int f,int c){
    Inicializar(f, c);
    for (int i=0;i<nf;i++){ 
        for (int j=0;j<nc;j++){
            data[i][j].r=255;
            data[i][j].g=255;
            data[i][j].b=255;
            data[i][j].transparencia=255;
        }
    }  
}

//---------------------------------------

Imagen::Imagen(const Imagen &I){
    assert (this != &I);
    Copiar(I);
}

//---------------------------------------

Imagen & Imagen::operator=(const Imagen & I){
    if(this != &I){
        Borrar();
        Copiar(I);
    }
    return *this;
}

//---------------------------------------

Imagen::~Imagen(){
    Borrar();
}

//---------------------------------------

Pixel & Imagen::operator()(int i,int j){
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return data[i][j];
}

//---------------------------------------

const Pixel & Imagen::operator()(int i,int j)const{
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return data[i][j];
}

//---------------------------------------

void Imagen::EscribirImagen(const char * nombre){
    unsigned char * aux = new unsigned char [nf*nc*3];
    unsigned char * m = new unsigned char [nf*nc];
      
    int total = nf*nc*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(nc*3);
        int posj = (i%(nc*3))/3;
	    
	    aux[i]=data[posi][posj].r;
	    aux[i+1]=data[posi][posj].g;
	    aux[i+2]=data[posi][posj].b;
	    m[i/3]=data[posi][posj].transparencia;
	     
    }    
	
    if (!EscribirImagenPPM (nombre, aux,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
    }

    delete[]aux;
    string n_aux = "mascara_";
    n_aux =n_aux+nombre;
    std::size_t found =n_aux.find(".ppm");
    if (found!=std::string::npos){
	    n_aux =n_aux.substr(0,found);
    }
    n_aux =n_aux+".pgm";

      
    if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
    }	    
    delete []m;

}  

//---------------------------------------

void Imagen::LeerImagen(const char * nombre,const string &nombremascara){
    int f,c;
    unsigned char * aux,*aux_mask ;
      
    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char [f*c*3];
    LeerImagenPPM (nombre, f,c,aux);
    if (nombremascara!=""){
	    int fm,cm;
	    LeerTipoImagen(nombremascara.c_str(), fm, cm);
	    aux_mask = new unsigned char [fm*cm];
	    LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
    }
    else{
	    aux_mask=0;
    }	
      
      
    Imagen I(f,c);
    int total = f*c*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(c*3);
        int posj = (i%(c*3))/3;
	    //cout<<posi<<" " <<posj<<endl;
        I.data[posi][posj].r=aux[i];
        I.data[posi][posj].g=aux[i+1];
        I.data[posi][posj].b=aux[i+2];
        if (aux_mask!=0)
            I.data[posi][posj].transparencia=aux_mask[i/3];
        else  
            I.data[posi][posj].transparencia=255;
    }    
	  
    *this = I;   
    if (aux_mask!=0) delete[]aux_mask;
    delete []aux;
      
}

//---------------------------------------

void Imagen::LimpiarTransp(){
    for(int i =0; i< nf; i++){
        for(int j =0; j <nc; j++){
            data[i][j].transparencia = 255;
        }
    }
}

//---------------------------------------

int Imagen::num_filas()const
{
    return nf;
}

//---------------------------------------

int Imagen::num_cols()const
{
    return nc;
}

//---------------------------------------

void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++)
	        if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
	            if (I.data[i][j].transparencia!=0){
	                if (tippegado==OPACO)
	                    data[i+posi][j+posj]=I.data[i][j];
	                else{
	                    data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
	                    data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
	                    data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
                    }  
	  
	            }  
	        }	
	    
}

//---------------------------------------

Imagen Imagen::ExtraeImagen(int posi,int posj,int dimi,int dimj){
    assert (posi < nf && posj < nc);
    assert (posi+dimi < nf && posj+dimj < nc);

    Imagen imagensalida(dimi, dimj);
    for(int i = posi; i < posi+dimi; i++)
        for(int j = posj; j < posj+dimj; j++)
            imagensalida(i-posi, j-posj) = data[i][j];
    return imagensalida;
}

Imagen Rota(const Imagen & Io,double angulo){
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {
	    inter=rcorners[count]*coseno+ccorners[count]*seno;
	   
	    if(inter<new_row_min)
		    new_row_min=inter;
	    if(inter>new_row_max)
		    new_row_max=inter;
	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;
	   
	    if(inter1<new_col_min)
		    new_col_min=inter1;	
	    if(inter1>new_col_max)
		    new_col_max=inter1;
   }
    
    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);
   
    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++)
      {
        for(int cols=0;cols<newimgcols;cols++)
        {
            float oldrowcos=((float)rows+new_row_min)*cos(-rads);
            float oldrowsin=((float)rows+new_row_min)*sin(-rads);
            float oldcolcos=((float)cols+new_col_min)*cos(-rads);
            float oldcolsin=((float)cols+new_col_min)*sin(-rads);
            float old_row=oldrowcos+oldcolsin;
            float old_col=-oldrowsin+oldcolcos;
            old_row=ceil((double)old_row);
            old_col=ceil((double)old_col);
            if((old_row>=0)&&(old_row<Io.num_filas())&&
                (old_col>=0)&&(old_col<Io.num_cols()))
            {
                Iout(rows,cols)=Io(old_row,old_col);
                    
            }
            else{
                Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
                Iout(rows,cols).transparencia= 0;
            }
        }
    }
    return Iout;
	  
}

void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
    int fila,col;
    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
        if (c1!=c2){
            double a,b;
            a= double(f2-f1)/double(c2-c1);
            b= f1-a*c1;
            col = (int)(c1+c2)/2;
            fila = (int)rint(a*col+b);
        }  
        else{
            col = c1;
	        fila = (f1+f2)/2;
        }  
	  
	  
        double angulo = atan2((f2-f1),(c2-c1));
        Imagen Irota=Rota(avion,angulo);
	
        I.PutImagen(fila,col,Irota);//pensar si debe ser opaco o blending
	  
        angulo = atan2((f2-fila),(c2-col));
        Irota=Rota(avion,angulo);
	
	    I.PutImagen(f2,c2,Irota, OPACO);//pensar si debe ser opaco o blending
	    angulo = atan2((fila-f1),(col-c1));
	    Irota=Rota(avion,angulo);
	
	    I.PutImagen(f1,c1,Irota, OPACO);//pensar si debe ser opaco o blending
	 
      
    }
     
}