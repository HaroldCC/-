#include "dma.h"
#include <iostream>
#include <cstring>

ABC::ABC(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

ABC::ABC(const ABC & a)
{
	label = new char[std::strlen(a.label) + 1];
	std::strcpy(label, a.label);
	rating = a.rating;
}

ABC::~ABC()
{
	delete [] label;
}

ABC & ABC::operator= (const ABC & a)
{ 
	if (this == & a)
		return *this;

	delete [] label;
	label = new char[std::strlen(a.label) + 1];
	std::strcpy(label, a.label);
	rating = a.rating;
	return *this;
}

std::ostream & operator<< (std::ostream & os, const ABC & a)
{
	os << "Label:" << a.label << std::endl;
	os << "Rating:" << a.rating << std::endl;
	return os;
}




//baseDMA methods
baseDMA::baseDMA(const char * l, int r) : ABC(l, r)
{}

baseDMA::baseDMA(const baseDMA & a) : ABC(a)
{}

void baseDMA::view() const
{
  std::cout << "call baseDMA view\n";
  std::cout << *this << std::endl;
}

std::ostream & operator<< (std::ostream & os, const baseDMA & a)
{
	os << (const ABC &) a << std::endl;
	return os;
}




//lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABC(l, r)
{
  std::strcpy(color, c);
}

lacksDMA::lacksDMA(const lacksDMA & ld) : ABC(ld)
{
  std::strcpy(color, ld.color);
}

lacksDMA::~lacksDMA()
{}

void lacksDMA::view() const
{
  std::cout << "lacksDMA view:\n";
  std::cout << *this << std::endl;
}

lacksDMA & lacksDMA::operator= (const lacksDMA  & ld)
{

  ABC::operator= (ld);
  std::strcpy(color, ld.color);
  return *this;
}

std::ostream & operator<< (std::ostream & os, const lacksDMA & ld)
{
  os << (const ABC &) ld;
  os << "Color:" << ld.color << std::endl;
  return os;
}



//hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) : ABC(l, r)
{
  style = new char[std::strlen(s) + 1];
  std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hd) : ABC(hd)
{
  style = new char[std::strlen(hd.style) + 1];
  std::strcpy(style, hd.style);
}

hasDMA::~hasDMA()
{
  delete [] style;
}

void hasDMA::view() const
{
  std::cout << "call hasDMA view:\n";
  std::cout << *this << std::endl;
}

hasDMA & hasDMA::operator= (const hasDMA & hd)
{
  if (this == & hd)
    return *this;

  delete [] style;
  style = new char[std::strlen(hd.style) + 1];
  std::strcpy(style, hd.style);
  return *this;
}

std::ostream & operator<< (std::ostream & os, const hasDMA & hd)
{
  os << (const ABC &) hd;
  os << "Style:" << hd.style << std::endl;
  return os;
}
