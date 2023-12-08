Ruta::Ruta(){}

void Ruta::Insertar(const Punto & n){
    uta::iterator it = this->puntos.begin() ;
    
    while( (*it) < n && it != this->puntos.end() ){
        ++it;
    }
    it = puntos.insert( it, n );
}

void Ruta::Borrar(const Punto & n){
    Ruta::iterator it;
    for(it=this->puntos.begin(); it != this->puntos.end(); ++it ){
        if( n== (*it) ){
            it = puntos.erase( it );
        }
    }
}

string Ruta::GetCode()const{
    return code;
}

void Ruta::SetCode(const string & c){
    code = c;
}

int Ruta::GetNPuntos()const{
    return puntos.size();
}

bool Ruta::operator==(const Ruta &R)const{
    Ruta::iterator it1;
    Ruta::iterator it2
    bool iguales = true;

    //Si el mismo numero de puntos, los mismos puntos, y estos siguen el mismo orden,
    //entonces la ruta es igual
    if( R.GetNPuntos() == this->GetNPuntos() ){
        for(it1 = this->puntos.begin(), it2 = R.puntos.begin(); it1 != this->end() && iguales; ++it1, ++it2){
            iguales = (*it1) == (*it2);
        }
    }
}

bool operator<(const Ruta &R)const{
    //Seguiremos el criterio de la ruta más corta
    double r1 = 0.0;
    double r2 = 0.0;

    for( Ruta::iterator it = this->begin(); it != this->end() - 1; ++it ){
        Ruta::iterator sig = next(it);
        r1 += (*it).Distancia(*sig);
    }

    for( Ruta::iterator it = R.begin(); it != R.end() - 1; ++it ){
        Ruta::iterator sig = next(it);
        r2 += (*it).Distancia(*sig);
    }

    return r1 < r2;
}

iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}

const_iterator Ruta::begin(){
    const_iterator it;
    it.p = puntos.begin();
    return it;
}

iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}

const_iterator Ruta::end(){
    const_iterator it;
    it.p = puntos.end();
    return it;
}

