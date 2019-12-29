/*************************************************************************
    > File Name       : 7.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 10:17:16
 ************************************************************************/
#include<iostream>
#include<iomanip>

using namespace std;

int main(int argc,char *argv[])
{
    cout << "Enter your name:";
    string name;
    getline(cin, name);
    cout << "Enter your hourly wages:";
    double wages;
    cin >> wages;
    cout << "Enter number of hours worked:";
    double hours;
    cin >> hours;

    // 格式输出
    cout << "First fomat:\n";
    cout << showpoint << fixed << right;
    cout << setw(30) << name << ": $" << setprecision(2) << setw(10) << wages << setprecision(1) << setw(5) << hours << endl;

    cout << "Second format:\n";
    cout << left;
    cout << setw(30) << name << ": $" << setprecision(2) << setw(10) << wages << setprecision(1) << setw(5) << hours << endl;
     
    return 0;
}

