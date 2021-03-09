#ifndef T_MATRICEH
#define T_MATRICEH

#include <iostream>
using namespace std;

class matrice
{
    //===============
protected:
    unsigned _n, _m;                 // dimensions
    int **_pt;                       // matrice
    virtual void reserver_memoire(); // methode pour les allocations
    virtual void liberer_memoire();  // methode pour les desallocations
public:
    // constructeurs :
    matrice(unsigned nn = 1, unsigned mm = 1);
    matrice(const matrice &M);
    // destructeur :
    ~matrice();

    // methodes et operateurs
    void init(int valeur); // remplissage par une meme valeur

    matrice &operator=(const matrice &M);
    int *operator[](unsigned n); // l'operateur [] doit retourner une ligne
    matrice operator+(const matrice &M) const;
    matrice operator*(const matrice &M) const;
    friend matrice operator*(const matrice &M, int m); // M = M *2;
    friend matrice operator*(int m, const matrice &M);

    friend ostream &operator<<(ostream &o, const matrice &M);
    friend istream &operator>>(istream &i, matrice &M);

    unsigned nb_lignes();
    unsigned nb_colonnes();
};

#endif
