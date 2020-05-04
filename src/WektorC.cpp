#include "Wektor.cpp"
#include "LZespolona.hh"

template class Wektor<double,3>;
template std::istream & operator >> (std::istream &Strm, Wektor <double,3> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor <double,3> &Wek);

template class Wektor <double,5>;
template std::istream & operator >> (std::istream &Strm, Wektor <double,5> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor <double,5> &Wek);

template class Wektor <LZespolona,3>;
template std::istream & operator >>(std::istream & strm, Wektor <LZespolona,3> & Skl);
template std::ostream & operator << (std::ostream & strm, const Wektor <LZespolona,3> & Skl);

template class Wektor <LZespolona,5>;
template std::istream & operator >>(std::istream & strm, Wektor <LZespolona,5> & Skl);
template std::ostream & operator << (std::ostream & strm, const Wektor <LZespolona,5> & Skl);
