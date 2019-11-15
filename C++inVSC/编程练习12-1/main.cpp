/*************************************************************************
    > File Name       : main.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-13 20:12:41
 ************************************************************************/
#include<iostream>
#include"cow.h"

using namespace std;

int main(void)
{
	Cow c1;
	cout << "c1:" << endl;
//	c1.ShowCow();
	Cow c2("Tom", "code", 149.99);
	cout << "c2:" << endl;
	c2.ShowCow();
	Cow c3(c2);         //复制构造函数
	cout << "c3:" << endl; 
	c3.ShowCow();

	c1 = c3;
	cout << "c1:" << endl;
	c1.ShowCow();

    return 0;
}

