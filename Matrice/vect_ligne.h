#ifndef VECTLIGNE_H
#define VECTLIGNE_H

#include "matrice.h"

#include <iostream>
using namespace std;

class vect_ligne : public matrice
{
public:
    vect_ligne(unsigned mm=1);
    vect_ligne(const vect_ligne &vect);

    vect_ligne &operator=(const vect_ligne &vect);
    
    int &operator[](unsigned indice); // l'operateur [] doit retourner une ligne
    int operator[](unsigned indice) const;
}

#endif