#include "Macierz.hh"
#include <algorithm>

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
    tabM[0] = A;
    tabM[1] = B;
    tabM[2] = C;
}

Macierz::Macierz()
{
    Wektor W; // (0,0,0)
    for(int i=0; i<ROZMIAR; i++)
    {
        tabM[i]=W;
    }
}

Wektor  Macierz::operator *(const Wektor & B) const
 {
    Wektor W;
    for (int i=0; i<ROZMIAR; i++)
    {
        W[i] = 0;
    }
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            W[i] += tabM[i][j] * B[j];
        }
    }
    return W;
 }

double wyznacznik() //Sarrus
{
    double wynik;
    wynik = ((tabM[0][0]*tabM[1][1]*tabM[2][2]) + (tabM[0][1]*tabM[1][2]*tabM[2][0]) + (tabM[0][2]*tabM[1][0]*tabM[2][1]) - (tabM[0][2]*tabM[1][1]*tabM[2][0]) - (tabM[0][1]*tabM[1][0]*tabM[2][2]) - (tabM[0][0]*tabM[1][2]*tabM[2][1]));
    return wynik;
}

Macierz Macierz::transponuj() const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; i<ROZMIAR; j++)
        {
            M[i][j] = tabM[j][i];
        }
    }
    return M;
}

Wektor & Macierz::operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabM[index];
}

/*double & Macierz::operator () (int ind1, int ind2) //w sumie nie uzywana
{
    if(ind1 < 0 || ind1 > ROZMIAR || ind2 < 0 || ind2 > ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabM[ind1][ind2];
}
*/
Macierz  Macierz::operator + (Macierz & B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i] + B[i];
    }
    return M;
}

Macierz  Macierz::operator - (Macierz & B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i] - B[i];
    }
    return M;
}

Macierz  Macierz::operator * (Macierz & B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i];
    }
    B = M.transponuj();
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            M[i][j] = tabM[i] * B[j];
        }
    }
    return M;
}

Macierz  Macierz::operator * (double B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i] * B;
    }
    return M;
}

bool Macierz::operator == (Macierz & M2) const
{
    for(int i=0;i<ROZMIAR;i++)
    {
        if(tabM[i]!=M2[i]) 
        {
            return false;
        }
    }
    return true;
    
}

bool Macierz::operator != (Macierz & M2) const
{
    double epsilon = 0.000001;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (!abs((tabM[i]-M2[i]) > epsilon))
        {
            return false;
        }
        else return true;
    }
}
/*Macierz & Macierz::odwroc() const
{
    Macierz M;
    double Wyz =
}
*/
std::istream& operator >> (std::istream &strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
       std::cin >> Mac[i];
    }
    return strm;
}

std::ostream& operator << (std::ostream &strm, const Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            strm << Mac.transponuj[i][j] <<" ";
        }
    }
    return strm;
}
