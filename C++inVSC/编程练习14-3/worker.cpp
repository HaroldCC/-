/*************************************************************************
    > File Name       : worker.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 11:07:31
 ************************************************************************/

#include "worker.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Worker::Set()
{
	cout << "输入姓名：";
	getline(cin, fullname);
	cout << "输入ID:";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Show() const {
	cout << "姓名：" << fullname << endl;
	cout << "员工ID：" << id << endl;
}
