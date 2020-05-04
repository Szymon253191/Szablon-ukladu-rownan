#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych(const Macierz & M, const Wektor & W)
{
    A = M;
    b = W;
}

Wektor & UkladRownanLiniowych::rozwiaz() 
{
    Wektor Wy;
    Macierz M = A;
    Wektor W(b);
    double Wyzn = M.wyznacznik();

    if ((Wyzn = 0))
    {
        std::cerr<<"Blad, wyznacznik = 0";
        exit(1);
    }
    else
    {
        for (int i=0; i<ROZMIAR; i++)
        {
            M[i] = W;
            Wy[i] = M.wyznacznik();
            M[i] = A[i];
        }
        for (int i=0; i<ROZMIAR; i++)
        {
            Wy[i] = Wy[i] / Wyzn;
        }
    }
    return Wy;
}

Wektor & UkladRownanLiniowych::Zwroc_wektor_wolny()
{
    return b;
}

void UkladRownanLiniowych::Zmien_wektor_wolny(const Wektor & W)
{
    b = W;
}

Macierz & UkladRownanLiniowych::Zwroc_macierz()
{
    return A;
}

void UkladRownanLiniowych::Zmien_macierz(const Macierz & M)
{
    A = M;
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Macierz M;
    Wektor W;
    Strm >> M >> W;
    UklRown.Zmien_macierz(M);
    UklRown.Zmien_wektor_wolny(W);
    return Strm;
}

std::ostream& operator << ( std::ostream                  &Strm,
                            UkladRownanLiniowych    &UklRown
                          )
{
    Strm << "Macierz A: " << UklRown.Zwroc_macierz().transponuj() << "Wektor B: " << UklRown.Zwroc_wektor_wolny() << endl;
    return Strm;
}
