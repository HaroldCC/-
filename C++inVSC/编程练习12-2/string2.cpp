#include "string2.h"
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

int String::num_strings = 0; //��ʼ���ྲ̬��Ա

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
    //cout << "ʹ��(char* s)����" << str << endl;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    //cout << "\nʹ��(String &)����" <<str<< endl;
}

String::~String()
{
    --num_strings;
    //cout << "���ٶ���" << str << ", ʣ��������Ϊ" << num_strings << endl;
    delete[] str;
}

void String::Stringlow() //���ַ����������ַ�ת��ΪСд
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

void String::Stringup() //���ַ����������ַ�ת��Ϊ��д
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

int String::str_time(const char c) //ĳһ�ַ����ַ����г��ֵĴ���
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

//�������������
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

String String::operator+(const String &st) const //�������ܳ���2��
{
    int len = std::strlen(str) + std::strlen(st.str);
    char *str_sum = new char[len + 1];
    std::strcpy(str_sum, str);
    std::strcat(str_sum, st.str); //��st.str����str_sum�ĺ���
    String result = str_sum;      //����һ��String����󣬲���str_sum�Ľ����������
                                  //���������ͷ�str_sum���ڴ�
    delete[] str_sum;             //�ͷ�str_num���ڴ�

    return result;
}


String String::operator+(const char * s) const
{
    String temp = s;
    String sum = *this + temp;
    return sum;
}

//��Ԫ���ط���
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

//��̬����
int String::HowMany()
{
    return num_strings;
}
