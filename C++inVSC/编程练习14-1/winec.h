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

class Wine
{
	private:
		typedef std::valarray<int> ArrayInt;
		typedef Pair<ArrayInt, ArrayInt> PairArray;
		std::string label;
		PairArray wineDate;
		int numOfYear;               //年数
	public:
		Wine(const char * l, int y, const int yr[], const int bot[]);
		Wine(const char * l, int y);
		void GetBottles();
		void Show() const;
		int sum() const;
		const std::string & Label() const {
			return label;
		}
};


#endif
