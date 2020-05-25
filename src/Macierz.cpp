#include "Macierz.hh"
#include "Wektor.hh"
#include "LZespolona.hh"

using namespace std;

template <class TYP, int ROZMIAR>  
Macierz <TYP,ROZMIAR>::Macierz()
{
    Wektor <TYP,ROZMIAR> W;    
    for (int i;i<ROZMIAR;i++)
    {
      tab[i] = W;
    }
}

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> & Macierz <TYP,ROZMIAR>::operator [] (int index) 
{
    if (index < 0 || index >= ROZMIAR) 
    {
        cerr << "Poza zakresem";
        exit(1);      
    }
    return tab[index];
}
template <class TYP, int ROZMIAR>
const Wektor <TYP,ROZMIAR> & Macierz <TYP,ROZMIAR>::operator [] (int index) const
{
    if (index < 0 || index >= ROZMIAR) 
    {
        cerr << "Poza zakresem";
        exit(1);      
    }
    return tab[index];
}

template <class TYP, int ROZMIAR>
 Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator + (Macierz <TYP,ROZMIAR> M2) const 
{
    Macierz <TYP,ROZMIAR> M;
    for (int i=0;i<ROZMIAR;i++)
    {
        M[i] = tab[i] + M2[i];
    }
    return M;
}
template <class TYP, int ROZMIAR>
 Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator - (Macierz <TYP,ROZMIAR>  M2) const  
{
    Macierz <TYP,ROZMIAR> M;
    for (int i=0;i<ROZMIAR;i++)
    {
        M[i] = tab[i] - M2[i];
    }
    return M;
}

template <class TYP, int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator * (double L2) const
{
    Macierz <TYP,ROZMIAR> M;
    for (int i=0;i<ROZMIAR;i++)
    {
        M[i] = tab1[i] * L2;
    }
    return M;
}

template <class TYP, int ROZMIAR>
Wektor <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator * (const Wektor <TYP,ROZMIAR> & W2) const
{
    Wektor <TYP,ROZMIAR> W;
    for(int i=0;i<=2;i++)
    {
        W[i] = tab[i] * W2;
    }
    return W;
}

template <class TYP, int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator * (Macierz <TYP,ROZMIAR> M2) const
{
    Macierz <TYP,ROZMIAR> M;
    Macierz <TYP,ROZMIAR> MW;
    for (int i=0;i<ROZMIAR;i++)
    {
        for (int j=0;j<ROZMIAR;j++)
        {
            M[i][j] = tab[i][j];
        }
    }
    M = M.transponuj();
    for(int i=0;i<ROZMIAR;i++)
        {
            for (int j=0;j<ROZMIAR;j++)
            {
                MW[j][i] = M2[j] * M[i];
            }
        }
    return MW;              
}

template <class TYP, int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::transponuj() const
{
    Macierz <TYP,ROZMIAR> M;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            M[i][j] = tab[j][i];
        }
    }
    return M;
}


template <class TYP, int ROZMIAR>
TYP Macierz <TYP,ROZMIAR>::wyznacznik() const
{
    Macierz <TYP, ROZMIAR> M = *this;
     for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            M[i][j] = tab[i][j];
        }
    }
    TYP Wynik = M[0][0];

    for(int i=0;i<ROZMIAR-1;i++)
    {
        for(int j=0;j<ROZMIAR-(i+1);j++)
        {
            M[i+j+1] -= M[i] * (M[i+j+1][i] / M[i][i]);
        }
    }

    for(int i = 1; i < ROZMIAR; i++)
    { 
        Wynik *= M[i][i]; 
    }

    return Wynik;
}

template <class TYP, int ROZMIAR>
bool Macierz <TYP,ROZMIAR>::operator == (const Macierz <TYP,ROZMIAR> & M2) const
{
    for(int i=0;i<ROZMIAR;i++)
    {
        if (M2[i] != tab1[i])
        {
            return false;
        }
    }
    return true;
}

template <class TYP, int ROZMIAR>
bool Macierz <TYP,ROZMIAR>::operator != (const Macierz <TYP,ROZMIAR> & M2) const
{
    for(int i=0;i<ROZMIAR;i++)
    {
        if (M2[i] == tab1[i])
        {
            return false;
        }
    }
    return true;
}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz <TYP,ROZMIAR> &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
} 

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz <TYP,ROZMIAR> &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        Strm << Mac[i];
    }
    return Strm;
}