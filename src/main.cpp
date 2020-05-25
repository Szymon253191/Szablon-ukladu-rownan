#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
using namespace std;





int main()
{  

    UkladRownanLiniowych <double,5> UklR;
    UkladRownanLiniowych <LZespolona,5> UklZ;
    char typ;

    cin>>typ;
    if(typ!='r' && typ!='z')
    {
        cerr<<"Wprowadz poprawny typ zmiennych"<<endl;
        exit(1);
    }
    if(typ=='r') 
    {
        cin>>UklR;
    }
    else cin>>UklZ;
    if(typ=='r') 
    {
        cout<<UklR.rozwiaz(UklR)<<endl;
    }
    else cout<<UklZ.rozwiaz(UklZ)<<endl;

    return 0;
}