#ifndef MACIERZ_HH
#define MACIERZ_HH
#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

class Macierz {

    Wektor tabM[ROZMIAR];

  public:

    Macierz(Wektor A, Wektor B, Wektor C);
    Macierz();

    Wektor  operator *(const Wektor & B) const;
    double wyznacznik(); //Sarrus
    Macierz transponuj() const;

    Wektor & operator [](int index); // W[2][0] - zerowy element drugiego wektora
 //   double & operator () (int ind1, int ind2); // M(2,0)

    Macierz  operator + (Macierz & B) const;
    Macierz  operator - (Macierz & B) const;
    Macierz  operator * (Macierz & B) const;
    Macierz  operator * (double B) const;

    bool operator == (Macierz & M2) const;
    bool operator != (Macierz & M2) const;


  //  Macierz odwroc() const;


};

std::istream& operator >> (std::istream &strm, Macierz &Mac);

std::ostream& operator << (std::ostream &strm, const Macierz &Mac);


#endif
