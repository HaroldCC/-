/*************************************************************************
    > File Name       : 4.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-28 17:51:04
 ************************************************************************/
#include<iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;


auto outint_lambda = [](int n) { cout << n << " "; };

int main(int argc,char *argv[])
{

	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);
 
    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint_lambda);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint_lambda);
    cout << endl;
    yadayada.remove_if([](int n) { return n > 100; });
    etcetera.remove_if([](int n) { return n > 200; });
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint_lambda);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint_lambda);
    cout << endl;
     
    return 0;
}

