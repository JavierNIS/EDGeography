#include "Almacen_Rutas.h"

Almacen_Rutas::Almacen_Rutas(){};

void Almacen_Rutas::Insertar(const Ruta& R){
    rutas.insert(pair<string, Ruta>(R.GetCode(), R));
}

void Borrar(const Ruta& R){
    rutas.erase(R.GetCode);
}

Ruta GetRuta(const string& a){
    iterator it=rutas.find(a);
    return *it;
}

iterator begin(){
    iterator it=rutas.begin();
    return it;
}
const iterator begin() const{
    iterator it=rutas.begin();
    return it;
}
iterator end(){
    iterator it=rutas.end();
    return it;
}
const iterator end() const{
    iterator it=rutas.end();
    return it;
}

bool save(const char* nombre){
    ofstream outfile(nombre);
    if(!outfile.is_open()){
        cerr << "Couldn't open the file to save the routes"<<endl;
        return false;
    }
    outfile << "#Rutas" << endl;
    outfile << *this;
    outfile.close();
    return true;
}
bool load(const char* nombre){
    ifstream infile(nombre);
    string magicstring;
    if(!infile.is_open()){
        cerr << "Couldn't open the file to load the routes"<<endl;
        return false;
    }
    infile >> magicstring;
    if(magicstring != "#Rutas"){
        cerr << "The file's format couldn't be interpreted" << endl;
        return false;
    }
    infile >> *this;
    infile.close();
    return true;
}

istream& operator>> (istream& is, Almacen_Rutas & AR){
    Ruta ruta;
    is >> ruta;
    AR.Insertar(ruta);
    return is;
}
ostream& operator<< (ostream& os, Almacen_Rutas & AR){
    for(auto it=AR.begin(); it != AR.end(); ++it)
        os << it->second;
    return os;
}