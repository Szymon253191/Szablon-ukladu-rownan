#include "LZespolona.hh"
#include <iostream>
#include <math.h>
using namespace std;

double modul(LZespolona LZ)
{
  double LM;  
  LM=sqrt(pow(LZ.re,2)+pow(LZ.im,2));
  return LM;
}

LZespolona & LZespolona::operator = (double Skl2) 
{
  re = Skl2; 
  im = 0.0;
  return *this;
}

LZespolona sprzezenie (LZespolona LZ)
{
  LZ.im = LZ.im * (-1);
  return LZ;
}

LZespolona operator += (const LZespolona Skl1, const LZespolona Skl2) 
{
  LZespolona Wynik;
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator + (const LZespolona Skl1, const LZespolona Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (const LZespolona Skl1, const LZespolona Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (const LZespolona Skl1, const LZespolona Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator * (const LZespolona Skl1, double l)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re * l;
  Wynik.im = Skl1.im;
  return Wynik;
}

LZespolona  operator / (const LZespolona Skl1, const LZespolona Skl2)
{
  LZespolona  Wynik;
  if (Skl2.re != 0 && Skl2.im != 0)
  {
    LZespolona Wynik;
    Wynik = (Skl1 * sprzezenie(Skl2)) / (modul(Skl2) * modul(Skl2));
    return Wynik;
  }
  else 
  {
    cerr<<"Blad, dzielenie przez zero";
    exit (1);
  }
}

LZespolona  operator / (const LZespolona Skl1, double l)
{
  if (l != 0)
  {
    LZespolona  Wynik;
    Wynik.re = Skl1.re / l;
    Wynik.im = Skl1.im / l;
    return Wynik;
  }
  else
  {
    cerr<<"Blad, dzielenie przez zero";
    exit (1);
  }
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  double epsilon=0.0000000001;
  if(abs(Skl1.re-Skl2.re) < epsilon && abs(Skl1.im-Skl2.im) < epsilon)
  return true;
  else
  return false;
}

bool operator != (LZespolona Skl1,  LZespolona Skl2){
  return(!(Skl1==Skl2));
}

bool operator == (LZespolona Skl1, double l)
{
  double epsilon=0.000000001;
  if(abs(Skl1.re-l) < epsilon && abs(Skl1.im-l) < epsilon)
  return true;
  else
  return false;
}

bool operator != (LZespolona Skl1, double l)
{
  return(!(Skl1==l));
}

std::istream & operator >>(std::istream & strm, LZespolona & Skl)
{
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit); 
  strm >> Skl.re >> Skl.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit); 
  strm >> znak;
  if (znak != ')'){
    strm.setstate(std::ios::failbit); 
  }
    return strm;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & Skl)
{
  return strm << "(" << Skl.re << std::showpos << Skl.im << std::noshowpos << "i)";
}    