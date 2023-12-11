#include "Almacen_Rutas.h"

Almacen_Rutas::Almacen_Rutas(){};

void Almacen_Rutas::Insertar(const Ruta& R){
    rutas.insert(pair<string, Ruta>(R.GetCode(), R));
}

void Almacen_Rutas::Borrar(const Ruta& R){
    rutas.erase(R.GetCode());
}

Ruta Almacen_Rutas::GetRuta(const string& a){
    return rutas[a];
}

Almacen_Rutas::iterator Almacen_Rutas::begin(){
    iterator it;
    it.p=rutas.begin();
    return it;
}
Almacen_Rutas::const_iterator Almacen_Rutas::begin() const{
    const_iterator it;
    it.p=rutas.begin();
    return it;
}
Almacen_Rutas::iterator Almacen_Rutas::end(){
    iterator it;
    it.p=rutas.end();
    return it;
}
Almacen_Rutas::const_iterator Almacen_Rutas::end() const{
    const_iterator it;
    it.p=rutas.end();
    return it;
}



bool Almacen_Rutas::iterator::operator!=(const iterator &i){
    return this->p != i.p;
}

pair<const string, Ruta>& Almacen_Rutas::iterator::operator*(){
    return *p;
}

void Almacen_Rutas::iterator::operator++(){
    ++p;
}

bool Almacen_Rutas::save(const char* nombre){
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
bool Almacen_Rutas::load(const char* nombre){
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
        os << (*it).second;
    return os;
}