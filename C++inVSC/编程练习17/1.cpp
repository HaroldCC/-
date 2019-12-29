/*************************************************************************
    > File Name       : 1.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 10:38:54
 ************************************************************************/
#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    cout << "输入一串字符，将统计“$”字符之前的字符数目：\n";
    char ch[20];
    int ct = 0;
    while ((ch[ct] = cin.get()) != '$')
    {
        ct++;
    }
   cin.putback(ch[ct]);

    while (cin.get() != '\n')
    {
        continue;
    }
    
    return 0;
}

