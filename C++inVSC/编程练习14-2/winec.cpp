/*************************************************************************
    > File Name       : .\winec.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-02 19:46:51
 ************************************************************************/
#include<iostream>
#include "winec.h"

void Wine::GetBottles()
{
	int year, bottles;
	std::cout << "Enter" << Label() << "data for " << numOfYear << " year(s)" << std::endl;
	for(int i = 0; i < numOfYear; i++)
	{
		std::cout << "请输入年份：";
		std::cin >> year;
		PairArray::first()[i] = year;
		std::cout << "输入生产的瓶数：";
		std::cin >> bottles;
		PairArray::second()[i] = bottles;
	}
}

void Wine::Show() const
{
	std::cout <<  "Wine:" << Label() << std::endl;
	for (int i = 0; i < numOfYear; i++)
	{
		std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i];
		std::cout << std::endl;
	}
}


