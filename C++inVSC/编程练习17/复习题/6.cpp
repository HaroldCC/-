/*************************************************************************
    > File Name       : 6.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 10:03:47
 ************************************************************************/
#include<iostream>
#include<iomanip>


using namespace std;

int main(int argc,char *argv[])
{
    cout << "输入一个整数：";
    int input;
    cin >> input;

    cout << setw(15) << "十进制" << setw(15) << "八进制" << setw(15) << "十六进制" << endl;
    cout << showbase;         //显示基数前缀
    cout << dec << setw(15) << input  << oct << setw(15) << input << hex << setw(15) << input << endl;
     
    return 0;
}

