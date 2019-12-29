/*************************************************************************
    > File Name       : str_back.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-12 12:39:51
 ************************************************************************/
#include<iostream>
#include<string>

using namespace std;

bool is_str_back(string& str)
{
	string reverseStr(str.rbegin(), str.rend());

	return reverseStr == str;
}

int main(int argc,char *argv[])
{
    cout << "请输入一个字符串，将测试它是否是回文(quit(退出)：";

    string str;
    getline(cin, str);

    while(str != "quit")
    {
        if(is_str_back(str))
            cout << "这是一个回文！" << endl;
        else 
            cout << "这不是一个回文！" << endl;
        cout << "继续输入下一个字符串(\"quit\"退出):";
        getline(cin, str);
    }
     
    return 0;
}

