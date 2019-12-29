/*************************************************************************
    > File Name       : winec.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-02 11:08:01
 ************************************************************************/
#ifndef WINEC_H_
#define WINEC_H_

#include<iostream>
#include<string>
#include"pairs.h"
#include<valarray>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
	

class Wine : private std::string, private PairArray             //私有继承
{
	private:
		int numOfYear;               //年数
	public:
		Wine(const char * l, int y, const int yr[], const int bot[]) 
			: std::string(l), numOfYear(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)){}
		Wine(const char * l, int y) : std::string(l), numOfYear(y), PairArray(ArrayInt(y), ArrayInt(y)){}
		void GetBottles();
		void Show() const;
		int sum() const{
			return PairArray::second().sum();
		}
		const std::string & Label() const {
			return (const std::string &) *this;
		}
};


#endif
