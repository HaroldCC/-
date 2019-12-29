#include<iostream>
#include<string>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool is_str_back_2(const string& str)
{
   string reverse(str.rbegin(), str.rend());

   return str == reverse; 
}

//思想：将用户输入的字符串放在一个函数中进行处理
// 当判断是字母时将字母转换为小写，并将结果放在一个容器中
// 供判断回文函数使用
string process_str(const string& str)
{
    string s;            
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        char ch = *iter;
        if (isalpha(ch))
        {
            if (isupper(ch))
                ch = tolower(ch);
            s.push_back(ch);
        }
    }
    return s;
}

int main(void)
{
    cout << "请输入一串字符，将判断是否为回文：";
    string input;
    string str;
    getline(cin, input);

    while (input != "quit")
    {
        str = process_str(input);
        cout << input << "处理后为" << str << endl;
        if (is_str_back_2(str))
            cout << input << "是回文！" << endl;
        else 
            cout << input << "不是回文！" << endl;
        
        cout << "继续输入一个字符串(\"quit\"退出):" << endl;
        getline(cin, input);
    }
    
    return 0;
}