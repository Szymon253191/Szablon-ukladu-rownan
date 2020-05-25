#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "LZespolona.hh"

template <class TYP, int ROZMIAR>
class Wektor
{
    TYP tab[ROZMIAR];
    public:

    Wektor();
    TYP & operator [] (int index) ;
    const TYP & operator [](int index) const ; 
    Wektor <TYP,ROZMIAR> operator + (const Wektor <TYP,ROZMIAR> &  W2) const ;
    Wektor <TYP,ROZMIAR> operator - (const  Wektor <TYP,ROZMIAR> & W2) const ;
    TYP operator * (const Wektor <TYP,ROZMIAR> & W2) const ;
    Wektor <TYP,ROZMIAR> operator * (TYP l2) const ; 
    Wektor <TYP,ROZMIAR> operator / (TYP l2) const ; 
    bool operator == (const Wektor <TYP,ROZMIAR> & W2) const;
    bool operator != (const Wektor <TYP,ROZMIAR> & W2) const;
    double dlugosc() const;
};

template <typename TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek);
template <typename TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek);

#endif