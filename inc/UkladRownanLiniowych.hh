#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

template <class TYP,int ROZMIAR>
class UkladRownanLiniowych 
{   
Macierz <TYP,ROZMIAR> A;
Wektor <TYP,ROZMIAR> B;
public:

UkladRownanLiniowych() {}
UkladRownanLiniowych(Macierz <TYP,ROZMIAR> _A ,Wektor <TYP,ROZMIAR> _B) : A(_A), B(_B) {};
const Macierz <TYP,ROZMIAR> & get_A() const ;
const Wektor <TYP,ROZMIAR> & get_B() const ;
void set_A(Macierz <TYP,ROZMIAR> & N) ;
void set_B(Wektor <TYP,ROZMIAR> & N) ;
const Macierz <TYP,ROZMIAR> zamien(int i, Macierz <TYP,ROZMIAR> A, Wektor <TYP,ROZMIAR> B) const ;
const Wektor <TYP,ROZMIAR> rozwiaz(UkladRownanLiniowych <TYP,ROZMIAR> Ukl) const ; 
};

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);
template <class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);


#endif