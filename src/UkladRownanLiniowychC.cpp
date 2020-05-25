#include "UkladRownanLiniowych.cpp"
#include "LZespolona.hh"




template class UkladRownanLiniowych<double,3>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<double,3> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<double,3> &UklRown);

template class UkladRownanLiniowych<double,4>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<double,3> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<double,3> &UklRown);

template class UkladRownanLiniowych<double,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<double,5> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<double,5> &UklRown);


template class UkladRownanLiniowych<LZespolona,3>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,3> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,3> &UklRown);

template class UkladRownanLiniowych<LZespolona,4>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,3> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,3> &UklRown);

template class UkladRownanLiniowych<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,5> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,5> &UklRown);
