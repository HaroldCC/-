#ifndef STRING2_H_
#define STRING2_H_

#include<iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;                //�ַ���ָ��
    int len;                //�ַ�������
    static int num_strings;        //�������
    static const int CINLIM = 80;      //��������
public:
    String();
    String(const char* s);
    String(const String & st);
    ~String();
    int length () const {return len;}

    void Stringlow();            //���ַ����������ַ�ת��ΪСд
    void Stringup();             //���ַ����������ַ�ת��Ϊ��д
    int str_time(const char c);              //ĳһ�ַ����ַ����г��ֵĴ���

    //�������������
    String & operator= (const String &st);
    String & operator= (const char*st);
    char & operator [] (int i);
    const char & operator[](int i) const;
    String operator+(const String &st) const;
    String operator+(const char * s) const;

    //��Ԫ���ط���
    friend bool operator<(const String &str1, const String &str2);
    friend bool operator>(const String &str1, const String &str2);
    friend bool operator==(const String &str1, const String &str2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    friend String operator+(const char * st1, const String & st2);


    //��̬����
    static int HowMany();
};

#endif