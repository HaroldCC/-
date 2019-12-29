#include "string2.h"
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

int String::num_strings = 0; //初始化类静态成员

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    //cout << "使用(char* s)构建" << str << endl;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    //cout << "\n使用(String &)构建" <<str<< endl;
}

String::~String()
{
    --num_strings;
    //cout << "销毁对象" << str << ", 剩余对象个数为" << num_strings << endl;
    delete[] str;
}

void String::Stringlow() //将字符串中所有字符转换为小写
{
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (std::isupper(ch))
        {
            str[i] = tolower(ch);
        }
    }
}

void String::Stringup() //将字符串中所有字符转换为大写
{
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (std::islower(ch))
        {
            str[i] = toupper(ch);
        }
    }
}

int String::str_time(const char c) //某一字符在字符串中出现的次数
{
    int show_time = 0;

    for (int i = 0; i < len; i++)
    {
        if (c == str[i])
        {
            show_time++;
        }
    }
    return show_time;
}

//重载运算符方法
String & String::operator=(const String &st)
{
    if (this == &st)
    {
        return *this;
    }

    delete[] str;

    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char *st)
{
    delete[] str;
    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, st);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String String::operator+(const String &st) const //参数不能超过2个
{
    int len = std::strlen(str) + std::strlen(st.str);
    char *str_sum = new char[len + 1];
    std::strcpy(str_sum, str);
    std::strcat(str_sum, st.str); //将st.str接在str_sum的后面
    String result = str_sum;      //声明一个String类对象，并将str_sum的结果赋给它，
                                  //以免忘记释放str_sum的内存
    delete[] str_sum;             //释放str_num的内存

    return result;
}


String String::operator+(const char * s) const
{
    String temp = s;
    String sum = *this + temp;
    return sum;
}

//友元重载方法
bool operator<(const String &str1, const String &str2)
{
    return (std::strcmp(str1.str, str2.str) == 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str2 < str1;
}

bool operator==(const String &str1, const String &str2)
{
    return (std::strcmp(str1.str, str2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

String operator+(const char * st1, const String & st2)
{
    return String(st1) + st2;
}

//静态函数
int String::HowMany()
{
    return num_strings;
}
