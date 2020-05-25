#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"
#include <iostream>
#include <cmath>
using namespace std;

template<class TYP, int ROZMIAR>
const Macierz<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_A() const 
{
  return A;
}

template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_B() const
{
  return B;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::set_A(Macierz<TYP,ROZMIAR> & N) 
{
  A=N;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::set_B(Wektor<TYP,ROZMIAR> & N) 
{
  B=N;
}

template<class TYP, int ROZMIAR>
const Macierz<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::zamien(int i, Macierz<TYP,ROZMIAR> A, Wektor<TYP,ROZMIAR> B) const
{
  A=A.transponuj();
  A[i]=B;
  A=A.transponuj();
  return A;
}

template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::rozwiaz(UkladRownanLiniowych<TYP,ROZMIAR> UklRown) const
{
  Wektor<TYP,ROZMIAR> Wynik;
  int ilosc_zer=0;
  TYP wyzn;
  int i;
  wyzn=A.wyznacznik();
  for(i=0;i<ROZMIAR;i++)
  {                 
    Wynik[i]=zamien(i,A,B).wyznacznik();
    if(Wynik[i]==0.0) 
    ilosc_zer++;
  }
  if(wyzn==0 && ilosc_zer==ROZMIAR)
  {
    cout <<"Nieskonczenie wiele rozwiazan \n";   
    exit(0);
  }
  if(wyzn==0 && ilosc_zer!=ROZMIAR)
  {
    cout <<"Brak rozwiazan \n"; 
    exit(0);  
  }
  for(i=0;i<ROZMIAR;i++)
  {
    Wynik[i] = Wynik[i] / wyzn;
  }
  return Wynik;  
}

template<class TYP, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,SWymiar> &UklRown)
{
  Macierz<TYP,ROZMIAR> A;
  Wektor<TYP,ROZMIAR> B;
  Strm >> A >> B;
  A=A.transpozycja(); 
  UklRown.set_A(A);
  UklRown.set_B(B);
  return Strm;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
  Macierz<TYP,ROZMIAR> A = UklRown.get_A();
  Wektor<TYP,ROZMIAR> B = UklRown.get_B();
  for(int i=0;i<ROZMIAR;i++)
  {
    Strm<<A[i]<<"["<<B[i]<<"]"<<endl;
  }
return Strm;
}