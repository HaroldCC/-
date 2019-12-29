/*************************************************************************
    > File Name       : average_list.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-28 15:59:04
 ************************************************************************/
#include<iostream>
#include<initializer_list>

using namespace std;

template <typename T>
T average_list(initializer_list<T> i)
{
	T sum = 0;
	int num = 0;
	for (auto p = i.begin(); p != i.end(); p++, num++)
		sum += *p;
	return sum / num;
}

int main(int argc,char *argv[])
{
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	auto ad = average_list<double> ({ 'A', 70, 65.33 });
	cout << ad << endl;
     
    return 0;
}

