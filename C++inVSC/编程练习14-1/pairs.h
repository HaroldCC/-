/*************************************************************************
    > File Name       : pairs.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-02 19:16:38
 ************************************************************************/
#ifndef PAIRS_H_
#define PAIRS_H_
#include<iostream>
#include<string>

template <typename T1, typename T2>
class Pair
{
	private:
		T1 a;
		T2 b;
	public:
		T1 & first();
		T2 & second();
		T1 first() const {
			return a;
		}
		T2 second() const {
			return b;
		}
		Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
		Pair() {}
};


template<typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template<typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}

#endif
