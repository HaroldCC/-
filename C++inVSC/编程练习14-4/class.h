/*************************************************************************
    > File Name       : class.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 12:40:50
 ************************************************************************/

#ifndef CLASS_H_ 
#define CLASS_H_

#include <iostream>
#include <string>

class Person
{
	private:
		std::string firstname;
		std::string lastname;
	protected:
		virtual void fullname() const
		{
			std::cout << "fullname:" << firstname << " " << lastname << std::endl;
		}
	public:
        Person(const std::string & fn = "none", const std::string ln = "none")
			: firstname(fn), lastname(ln) {}
		Person(const Person & p) : firstname(p.firstname), lastname(p.lastname) {}
		Person & operator= (const Person & p);
		virtual ~Person() {}
		void virtual Show() const {	std::cout << "\n A person is here:\n:"; fullname();}
};

class Card
{
	public:
		enum color {spade, heart, club, diamond};          //扑克牌花色
	private:
		unsigned value;
		color cardColor;
	public:
		Card(color c1 = spade, int val = 10){cardColor = c1, value = val;}
		Card(const Card & c) : value(c.value), cardColor(c.cardColor) {}
		Card & operator= (const Card & c);

		friend std::ostream & operator<< (std::ostream & os, const Card & c);

		virtual ~Card() {}

};

class Gunslinger : public virtual Person
{
	private:
		double time;
		int notches;            //刻痕数

	protected:
		void displayGunslinger() const
		{
			std::cout << "hisGundata: time:" << time << "," << "noteches:" << notches << std::endl; 
		}

	public:
		Gunslinger(const std::string & fn = "Gunman", const std::string & ln = "none", double t = 0, int n = 0) : Person(fn, ln), time(t), notches(n) {}
		Gunslinger(const Person & p, double t, int n) : Person(p), time(t), notches(n) {}
		Gunslinger(const Gunslinger & g) : Person(g), time(g.time), notches(g.notches) {}
		Gunslinger & operator= (const Gunslinger & g);

		virtual void Show() const {std::cout << "\nA Gun slinger is here:\n"; fullname(); displayGunslinger();}
		virtual double Draw() const {return time;}
		virtual ~Gunslinger() {}
};

class PokerPlayer : virtual public Person 
{
	private:
		Card myCard;
	protected:
		void displayPokerPlayer() const {std::cout << "his card: " << myCard << std::endl;}
	public:
		PokerPlayer(const std::string & fn = "PokerPlayer", const std::string & ln = "none", Card::color cl = Card::heart, unsigned val = 10) : Person(fn, ln), myCard(cl, val) {}
		PokerPlayer(const Person & p, Card::color c1 = Card::heart, unsigned val = 10) : Person(p), myCard(c1, val) {}
		PokerPlayer(const PokerPlayer & p) : Person(p), myCard(p.myCard) {};
		virtual ~PokerPlayer() {}

		PokerPlayer & operator= (const PokerPlayer & p);
		virtual void Show() const {std::cout << "\nA pokerplayer is here:\n"; fullname(); displayPokerPlayer();}
		virtual const Card & Draw() const {return myCard;}
};

class BadDude : public Gunslinger, public PokerPlayer
{
	public:
		BadDude(const std::string & fn = "GunPokerman", const std::string & ln = "none", double t = 0, int n = 0, Card::color cl = Card::spade, unsigned val = 10) : Person(fn, ln), Gunslinger(fn, ln, t, n), PokerPlayer(fn, ln, cl, val) {}
		BadDude(const Person & p, double t = 0, int n = 0, Card::color cl = Card::spade, unsigned val = 10) : Person(p), Gunslinger(p, t, n), PokerPlayer(p, cl, val) {}
		BadDude(const BadDude & bd) : Person(bd), Gunslinger(bd), PokerPlayer(bd) {}

		virtual ~BadDude() {}
		BadDude & operator= (const BadDude & bd);
		virtual void Show() const {std::cout << "\n A baddude can shot and poker:\n"; displayPokerPlayer(); displayGunslinger();}

	double gDraw() const {return Gunslinger::Draw();}
	const Card & cDraw() const { return PokerPlayer::Draw();}
};

#endif
