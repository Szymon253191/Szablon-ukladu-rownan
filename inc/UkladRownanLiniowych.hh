#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Macierz.hh"
#include <iostream>
#include "rozmiar.h"
class UkladRownanLiniowych {

    Macierz A; // Ax = b
    Wektor b;

  public:

    Wektor & rozwiaz();
    UkladRownanLiniowych(){};
    UkladRownanLiniowych(const Macierz & M, const Wektor & W);
    UkladRownanLiniowych(Macierz _A, Wektor _b): A(_A), b(_b){};
    Wektor & Zwroc_wektor_wolny();
    void Zmien_wektor_wolny(const Wektor & W);
    Macierz & Zwroc_macierz();
    void Zmien_macierz(const Macierz & M);
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream                  &Strm,
                            UkladRownanLiniowych    &UklRown
                          );


#endif
