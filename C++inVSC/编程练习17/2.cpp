/*************************************************************************
    > File Name       : 2.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 11:05:57
 ************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

/********************须事先创建好要保存的文件*****************************************/

int main(int argc,char *argv[])
{
    if (argc == 1)      //如果命令行只输入一个参数，即可能只输入命令，而未输入文件名，或只输入文件名而未输入命令
        {
            cerr << "用法：" << argv[0] << "filename[s]\n";
            exit(EXIT_FAILURE);
        }

    
    fstream fout(argv[1]);
    if(!fout.is_open())
    {
        cerr << "打开文件" << argv[1] << "失败！" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "从键盘输入一些信息（空行结束）：";
    string meg;
    while (getline(cin, meg) && meg.size() > 0)
    {
        fout << meg << endl;
    }

    fout.close();
     
    return 0;
}

