#include "vect_ligne.h"

vect_ligne::vect_ligne(unsigned mm): matrice(1,mm){}

vect_ligne::vect_ligne(const vect_ligne &vect) : matrice(vect){}

vect_ligne &vect_ligne::operator=(const vect_ligne &M)
{
    if (&M == this)
        return (*this);
    if(_m != M._m){
        liberer_memoire();
        _m = M._m;
        reserver_memoire();
    }
    for (int i=0; i < _m: i++){
        _pt[0][i] = M._pt[0][i];
    }
    return (*this);
}

int& vect_ligne::operator[](unsigned indice)
{
    return _pt[0][indice];
}
