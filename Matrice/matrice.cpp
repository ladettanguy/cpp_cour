#include <stdlib.h>
#include "matrice.h"

void matrice::reserver_memoire()
{
    _pt = new int *[_n];
    for (int i = 0; i < _n; i++)
        _pt[i] = new int[_m];
}
void matrice::liberer_memoire()
{
    for (int i = 0; i < _n; i++)
        delete[] _pt[i];
    delete[] _pt;
}

// constructeur
matrice::matrice(unsigned nn, unsigned mm) : _n(nn), _m(mm)
{
    reserver_memoire();
    init(0);
}

matrice::matrice(const matrice &M) : _n(M._n), _m(M._m)
{
    reserver_memoire();
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
            _pt[i][j] = M._pt[i][j];
}

// destructeur
matrice::~matrice()
{
    liberer_memoire();
}

// methodes
void matrice::init(int val)
{
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
            _pt[i][j] = val;
}

matrice &matrice::operator=(const matrice &M)
{
    if (&M == this)
        return (*this); // M = M;
    if (_n != M._n || _m != M._m)
    {
        liberer_memoire();
        _n = M._n;
        _m = M._m;
        reserver_memoire();
    }
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
            _pt[i][j] = M._pt[i][j];
    return (*this);
}

matrice matrice::operator+(const matrice &M) const
{
    if (_n != M._n || _m != M._m)
    {
        cerr << "Addition des matrices de dimension diff. \n";
        exit(1);
    }
    matrice resultat(_n, _m);
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
            resultat._pt[i][j] = _pt[i][j] + M._pt[i][j];
    return resultat;
}

matrice matrice::operator*(const matrice &M) const
{
    if (_m != M._n)
    {
        cerr << "Multiplication des matrices de dimension incoherante. \n";
        exit(1);
    }
    matrice resultat(_n, M._m);
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < M._m; j++)
            for (int k = 0; k < _m; k++)
                resultat._pt[i][j] += _pt[i][k] * M._pt[k][j];
    return resultat;
}
matrice operator*(const matrice &M, int m)
{
    matrice resultat(M._n, M._m);
    for (int i = 0; i < M._n; i++)
        for (int j = 0; j < M._m; j++)
            resultat._pt[i][j] = M._pt[i][j] * m;
    return resultat;
}

matrice operator*(int m, const matrice &M)
{
    matrice resultat(M._n, M._m);
    for (int i = 0; i < M._n; i++)
        for (int j = 0; j < M._m; j++)
            resultat._pt[i][j] = M._pt[i][j] * m;
    return resultat;
}

int *matrice::operator[](unsigned indice)
{
    if (indice > _n)
    {
        cerr << " l'indice depasse les dimansions de la matrice \n";
        exit(1);
    }
    return _pt[indice];
}

unsigned matrice::nb_lignes()
{
    return _n;
}

unsigned matrice::nb_colonnes()
{
    return _m;
}

ostream &operator<<(ostream &os, const matrice &mat)
{
    int i, j;
    os << '[';
    for (i = 0; i < mat._n; i++)
    {
        for (j = 0; j < mat._m; j++)
            os << mat._pt[i][j] << " ";
        if (i == mat._n - 1)
            os << ']';
        os << "\n";
    }
    return os;
}

istream &operator>>(istream &is, matrice &mat)
{
    for (int i = 0; i < mat._n; i++)
        for (int j = 0; j < mat._m; j++)
            is >> mat[i][j];
    return is;
}
