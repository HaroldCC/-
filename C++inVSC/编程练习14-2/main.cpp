/*************************************************************************
    > File Name       : main.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-02 10:45:00
 ************************************************************************/
#include<iostream>
#include"winec.h"

using namespace std;

int main(int argc,char *argv[])
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "输入酒的名字：";
	char lab[50];
	cin.getline(lab, 50);
	cout << "输入数字：";
	int years;
	cin >> years;

	Wine holding(lab, years);
	holding.GetBottles();
	holding.Show();

	const int YEARS = 3;

	int y[YEARS] = {
		1993, 1995, 1998
	};

	int b[YEARS] = {
		48, 60, 72
	};

	Wine more("Gushing Grape Red", YEARS, y, b);
	more.Show();
	cout << "Total bootles for " << more.Label() << "：" << more.sum() << endl;

	cout << "Bye!\n";
     
    return 0;
}

