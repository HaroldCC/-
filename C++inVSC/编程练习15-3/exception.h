/*************************************************************************
    > File Name       : exception.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 16:16:09
 ************************************************************************/
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include<iostream>
#include<string>
#include<stdexcept>

class arg_error : public std::logic_error
{
	private:
		double v1;
		double v2;
		std::string funcName;
	public:
		arg_error(double a = 0, double b = 0, const std::string & f = "none", std::string msg = "非法参数\n") : logic_error(msg), v1(a), v2(b), funcName(f) { }
		void mesg() const{
			std::cout << v1 << "," << v2 << "," << funcName << std::endl;
		}
};

class hmean_error : public arg_error
{
	public:
		hmean_error(double a = 0, double b = 0, const std::string & f = "none", std::string msg = "非法参数\n") : arg_error(a, b, f, msg) { }
};

class gmean_error : public arg_error
{
	public:
		gmean_error(double a = 0, double b = 0, const std::string & f = "none", std::string msg = "非法参数\n") : arg_error(a, b, f, msg) { }
};

#endif
