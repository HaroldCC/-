/*************************************************************************
    > File Name       : pe14-5.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 22:15:58
 ************************************************************************/
#include<iostream>
#include "emp.h"

using namespace std;

int main(int argc,char *argv[])
{
	employee em("Trip",  "Harros", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Ogga", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << "按任意键继续:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "使用一个abstr_rmp指针:\n";
	abstr_emp * tri[4] = { &em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
     
    return 0;
}

