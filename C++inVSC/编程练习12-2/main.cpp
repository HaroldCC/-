#include"string2.h"
#include<iostream>

using namespace std;

int main(void)
{
     String s1(" 我是学习C++的一个学生。");
     String s2 = "请输入你的名字：";
     String s3;
     cout << s2;           //重载 << 运算符
     cin >> s3;            //重载 >> 运算符
     s2 = s2 + s1;
