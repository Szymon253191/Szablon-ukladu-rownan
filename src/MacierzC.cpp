#include "Macierz.cpp"
#include "LZespolona.hh"

template class Macierz <double,3>;
template std::istream & operator >> (std::istream &Strm, Macierz <double,3> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Macierz< double,3> &Wek);

template class Macierz <double,4>;
template std::istream & operator >> (std::istream &Strm, Macierz <double,4> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Macierz <double,4> &Wek);

template class Macierz <double,5>;
template std::istream & operator >> (std::istream &Strm, Macierz <double,5> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Macierz <double,5> &Wek);


template class Macierz <LZespolona,3>;
template std::istream & operator >>(std::istream & strm, Macierz <LZespolona,3> & Skl);
template std::ostream & operator << (std::ostream & strm, const Macierz <LZespolona,3> & Skl);

template class Macierz <LZespolona,4>;
template std::istream & operator >>(std::istream & strm, Macierz <LZespolona,4> & Skl);
template std::ostream & operator << (std::ostream & strm, const Macierz <LZespolona,4> & Skl);

template class Macierz <LZespolona,5>;
template std::istream & operator >>(std::istream & strm, Macierz <LZespolona,5> & Skl);
template std::ostream & operator << (std::ostream & strm, const Macierz <LZespolona,5> & Skl);
