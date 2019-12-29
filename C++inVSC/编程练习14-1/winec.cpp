/*************************************************************************
    > File Name       : .\winec.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-02 19:46:51
 ************************************************************************/
#include<iostream>
#include "winec.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: label(l), numOfYear(y), wineDate(ArrayInt(yr, y), ArrayInt(bot, y))
{}

Wine::Wine(const char * l, int y)
	: label(l), numOfYear(y), wineDate(ArrayInt(y), ArrayInt(y))
{}

void Wine::GetBottles()
{
	int i = 0;
	int year, bottles;
	for(i = 0; i < numOfYear; i++)
	{
		std::cout << "请输入年份：";
		std::cin >> year;
		wineDate.first()[i] = year;
		std::cout << "输入生产的瓶数：";
		std::cin >> bottles;
		wineDate.second()[i] = bottles;
	}
}

void Wine::Show() const
{
	std::cout << label << std::endl;
	for (int i = 0; i < numOfYear; i++)
	{
		std::cout << "\t" << wineDate.first()[i] << "\t" << wineDate.second()[i];
		std::cout << std::endl;
	}
}


int Wine::sum() const
{
	std::cout << "total bootles for " << label << "is" << wineDate.second().sum() << ".\n";
	return wineDate.second().sum();
}
