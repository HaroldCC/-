#ifndef STRING2_H_
#define STRING2_H_

#include<iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;                //字符串指针
    int len;                //字符串长度
    static int num_strings;        //对象个数
    static const int CINLIM = 80;      //输入限制
public:
    String();
    String(const char* s);
    ~String();
    int length () const {return len;}

    void Stringlow();            //将字符串中所有字符转换为小写
    void Stringup();             //将字符串中所有字符转换为大写
    int str_time(const char c);              //某一字符在字符串中出现的次数

    //重载运算符方法
    String & operator= (const String &st);
    String & operator= (const char*st);
    char & operator [] (int i);
    const char & operator[](int i) const;
    String operator+(const String &st) const;
    String operator+(const char * s) const;

    //友元重载方法
    friend bool operator<(const String &str1, const String &str2);
    friend bool operator>(const String &str1, const String &str2);
    friend bool operator==(const String &str1, const String &str2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    friend String operator+(const char * st1, const String & st2);


    //静态函数
    static int HowMany();
};

#endif