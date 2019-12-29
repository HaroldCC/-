/*************************************************************************
    > File Name       : exc_mean.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 15:38:17
 ************************************************************************/
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include<iostream>
#include<stdexcept>

class bad_hmean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b),std::logic_error("hmean arguments:a = -b\n")  { }
};

class bad_gmean : public std::logic_error
{
	private:
		double v1;
		double v2;
	public:
		bad_gmean(double a = 0, double b = 0) : v1(a), v2(b), std::logic_error("amean arguments should be >= 0\n") { }
};

#endif
