/*************************************************************************
    > File Name       : .\class.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 17:27:46
 ************************************************************************/
#include<iostream>
#include "class.h"

Person & Person::operator= (const Person & p)
{
	if (this == &p)
		return *this;
	else{
		firstname = p.firstname;
		lastname = p.lastname;
		return *this;
	}
}

Card & Card::operator= (const Card & c)
{
	if (this == &c)
		return *this;
	else{
		cardColor = c.cardColor;
		value = c.value;
		return *this;
	}
}

//Card friend
std::ostream & operator<<  (std::ostream & os, const Card & c) {
	os << "his card is ";
	switch(c.cardColor){
	case Card::spade: os << " spade ";break;
	case Card::heart: os << " heart "; break;
	case Card::club: os << " club " ; break;
	case Card::diamond: os << " diamond "; break;
	}

	os << c.value;
	return os;
}

Gunslinger & Gunslinger::operator= (const Gunslinger & g){
	if (this == &g)
		return *this;
	else{
		Person::operator= (g);
		time = g.time;
		notches = g.notches;
		return *this;
	}
}

PokerPlayer & PokerPlayer::operator=(const PokerPlayer & p){
	if (this == &p)
		return *this;
	else{
		Person::operator= (p);
		myCard = p.myCard;
		return *this;
	}
}

