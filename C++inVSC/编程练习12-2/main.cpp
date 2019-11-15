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
     s2 = "我的名字是" + s3;
     cout << s2 << ".\n";
     s2 = s2 + s1;

     s2.Stringup();
     cout << "字符串\n" << s2 << "\n包含" << s2.str_time('A') << "个字符‘A’。\n";

     s1 = "red";    //String (const char*)
                    //then String & operator= (const String&)
     String rgb[3] = {String(s1), String ("green"), String("blue")};
     cout << "输入混合灯光的原色名称:";
     String ans;
     bool success = false;

     while (cin >> ans)
     {
          ans.Stringlow();
          for (int i = 0; i < 3; i++)
          {
               if (ans == rgb[i])             //重载 == 运算符
               {
                    cout << "正确！\n";
                    success = true;
                    break;
               }
               
          }

          if (success)
          {
               break;
          }
          else
          {
               cout << "再次尝试！" << endl;
          }
          
     }
     cout << "End!\n";
     return 0;
}