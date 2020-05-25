#include "Wektor.hh"
#include <iostream>
#include <cmath>
#include "LZespolona.hh"
using namespace std;

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR>::Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        tab[i]=0;
    }   
}


template <class TYP, int ROZMIAR>
TYP & Wektor <TYP,ROZMIAR>::operator[](int index) 
{
    if (index < 0 || index >= ROZMIAR) 
    {
        cerr << "Poza zakresem";
        exit(1);      
    }
    return tab[index];
}


template <class TYP, int ROZMIAR>
const TYP & Wektor <TYP,ROZMIAR>::operator[](int index) const
{
    if (index < 0 || index >= ROZMIAR) 
    {
        cerr << "Poza zakresem";
        exit(1);      
    }
    return tab[index];
}


template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> Wektor <TYP,ROZMIAR>::operator+ (const Wektor <TYP,ROZMIAR> & W2) const 
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = W2[i] + tab[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> Wektor <TYP,ROZMIAR>::operator- (const Wektor <TYP,ROZMIAR> & W2) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = tab[i] - W2[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
TYP Wektor <TYP,ROZMIAR>::operator* (const Wektor <TYP,ROZMIAR> & W2) const
{
    TYP Wynik;
    Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik = Wynik + tab[i] * W2[i];
    } 
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> Wektor <TYP,ROZMIAR>::operator* (TYP l2) const 
{
    Wektor <TYP,ROZMIAR> Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i] = tab[i] * l2;
    }
    return Wynik;
}


template <class TYP, int ROZMIAR>
bool Wektor <TYP,ROZMIAR>::operator==(const Wektor <TYP,ROZMIAR> & W2) const
{
    double epsilon=0.000000001;
    for(int i=0;i<ROZMIAR;i++)
    {
        if (abs((tab[i]-W2[i]) > epsilon)) // Wektor > double error
        return false;
    }
    return true;
}   

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> Wektor <TYP,ROZMIAR>::operator/ (TYP l2) const
{
    Wektor <TYP,ROZMIAR> Wynik;
    if(l2==0)
    {
        cerr << "Blad, dzielenie przez zero";
        exit(1);
    }
    else
    {
        for(int i=0;i<ROZMIAR;i++)
        {
            {   
                Wynik[i] = tab[i] / l2;
            }
        }
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const
{
    double dlugosc = 0;
    for (int i=0;i<ROZMIAR;i++)
    {
        LZespolona LZ = tab[i] * sprzezenie(tab[i]);
        dlugosc += tab[i].re;
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

template <> double Wektor<LZespolona,3>::dlugosc() const
{
    double dlugosc = 0;
    for (int i=0;i<3;i++)
    {
        LZespolona LZ = tab[i] * sprzezenie(tab[i]);
        dlugosc += tab[i].re;
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

template <> double Wektor<LZespolona,5>::dlugosc() const
{
    double dlugosc = 0;
    for (int i=0;i<5;i++)
    {
        LZespolona LZ = tab[i] * sprzezenie(tab[i]);
        dlugosc += tab[i].re;
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

template<> Wektor <LZespolona,3> Wektor <LZespolona,3>::operator/(LZespolona l2) const
{
    Wektor <LZespolona,3> Wynik;
    LZespolona LZ;
    LZ.re=0.0;
    LZ.im=0.0;
    if(l2==LZ)
    {
        cerr << "Blad, dzielenie przez zero";
        exit(1);
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            {   
                Wynik[i] = tab[i] / l2;
            }
        }
    }
    return Wynik;
}

template<> Wektor <LZespolona,5> Wektor <LZespolona,5>::operator/(LZespolona l2) const
{
    Wektor <LZespolona,5> Wynik;
    LZespolona LZ;
    LZ.re=0.0;
    LZ.im=0.0;
    if(l2==LZ)
    {
        cerr << "Blad, dzielenie przez zero";
        exit(1);
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            {   
                Wynik[i]=  tab[i]/  l2;
            }
        }
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
bool Wektor <TYP,ROZMIAR>::operator!= (const Wektor <TYP,ROZMIAR> & W2) const 
{
    return !(*this==W2);
}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor <TYP,ROZMIAR> &Wek)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}    

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor <TYP,ROZMIAR> &Wek)
{
    for (int i=0;i<ROZMIAR;i++)
    {
        Strm << Wek[i];
    }
    return Strm;
}    