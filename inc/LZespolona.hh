#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
using namespace std;
#include <iostream>

struct  LZespolona 
{
  double   re;   
  double   im;    
  
  LZespolona(): re(0), im(0) {};
  LZespolona(double r, double i): re(r), im(i) {};
  LZespolona &operator=(double Skl2);
};

LZespolona sprzezenie(LZespolona LZ);
double modul(LZespolona LZ);

LZespolona  operator + (const LZespolona Skl1, const LZespolona Skl2);
LZespolona  operator - (const LZespolona Skl1, const LZespolona Skl2);
LZespolona  operator * (const LZespolona Skl1, const LZespolona Skl2);
LZespolona  operator * (const LZespolona Skl1, double l);
LZespolona  operator / (const LZespolona Skl1, const  LZespolona Skl2);
LZespolona  operator / (const LZespolona Skl1, double l);
LZespolona  operator += (const LZespolona Skl1, const LZespolona Skl2);
bool operator == (LZespolona Skl1, LZespolona Skl2);
bool operator == (LZespolona Skl1, double l);
bool operator != (LZespolona Skl1, LZespolona Skl2);
bool operator != (LZespolona Skl1, double l);

std::istream & operator >>(std::istream & strm, LZespolona & Skl);
std::ostream & operator << (std::ostream & strm, const LZespolona & Skl);

#endif
