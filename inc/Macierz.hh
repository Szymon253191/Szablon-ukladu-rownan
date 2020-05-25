#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

template <class TYP, int ROZMIAR>
class Macierz
{
    Wektor <TYP,ROZMIAR> tab[ROZMIAR];
    public:

    Macierz();
    Wektor <TYP,ROZMIAR> & operator [] (int index);
    const Wektor<TYP,ROZMIAR> & operator [] (int index) const;
    Macierz <TYP,ROZMIAR> operator + (Macierz <TYP,ROZMIAR> M2) const;
    Macierz <TYP,ROZMIAR> operator - (Macierz <TYP,ROZMIAR> M2) const;
    Wektor <TYP,ROZMIAR> operator * (const Wektor <TYP,ROZMIAR>  & W2) const;
    Macierz <TYP,ROZMIAR> operator * (Macierz <TYP,ROZMIAR>  M2) const ;
    Macierz <TYP,ROZMIAR> operator * (double L2) const; 
    Macierz <TYP,ROZMIAR> transponuj() const;
    TYP wyznacznik() const;
    bool operator == (const Macierz <TYP,ROZMIAR> & M2) const;
    bool operator != (const Macierz <TYP,ROZMIAR> & M2) const;
};

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const  Macierz <TYP,ROZMIAR> &Mac);
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz <TYP,ROZMIAR> &Mac);

#endif
