#include"string2.h"
#include<iostream>

using namespace std;

int main(void)
{
     String s1(" ����ѧϰC++��һ��ѧ����");
     String s2 = "������������֣�";
     String s3;
     cout << s2;           //���� << �����
     cin >> s3;            //���� >> �����
     s2 = "�ҵ�������" + s3;
     cout << s2 << ".\n";
     s2 = s2 + s1;

     s2.Stringup();
     cout << "�ַ���\n" << s2 << "\n����" << s2.str_time('A') << "���ַ���A����\n";

     s1 = "red";    //String (const char*)
                    //then String & operator= (const String&)
     String rgb[3] = {String(s1), String ("green"), String("blue")};
     cout << "�����ϵƹ��ԭɫ����:";
     String ans;
     bool success = false;

     while (cin >> ans)
     {
          ans.Stringlow();
          for (int i = 0; i < 3; i++)
          {
               if (ans == rgb[i])             //���� == �����
               {
                    cout << "��ȷ��\n";
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
               cout << "�ٴγ��ԣ�" << endl;
          }
          
     }
     cout << "End!\n";
     return 0;
}