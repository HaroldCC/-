#include "port.h"
#include <iostream>
#include <cstring>

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strcpy(style, st);
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator= (const Port & p)
{
	if (this == & p)
		return *this;

	delete [] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+= (int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-= (int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "Brand:" << brand << std::endl;
	std::cout << "Kind:" << style << std::endl;
	std::cout << "Bottles:" << bottles << std::endl;
}

std::ostream & operator<< (std::ostream & os, const Port & p)
{
	os << p.brand << ","  << p.style << "," << p.bottles;
	return os;
}





//VintagePort methods
VintagePort::VintagePort() : Port()
{
	nickname = new char[std::strlen("null") + 1];
	std::strcpy(nickname, "null");
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nn)+ 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator= (const VintagePort & vp)
{
	if (this == & vp)
		return *this;

	Port::operator= (vp);
	delete [] nickname;
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const 
{
	Port::Show();
	std::cout << "Nickname:" << nickname << std::endl;
	std::cout << "Year:" << year << std::endl;
}

std::ostream & operator<< (std::ostream & os, const VintagePort & vp)
{
	os << (const Port &) vp << "," << vp.nickname << "," << vp.year;
	return os;
}
