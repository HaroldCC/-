/*************************************************************************
    > File Name       : 3.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 12:41:49
 ************************************************************************/
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{

    if(argc != 3)
    {
        cerr << "输入错误！" << endl;
        exit(EXIT_FAILURE);
    }
    
    ifstream fin(argv[1], ios_base::in);                  // 打开文件1，只读模式
    ofstream fout(argv[2], ios_base::out);                //打开文件2， 写入模式

    //finout.open("text.txt");
    if (!fin.is_open() || !fout.is_open())
    {
        cerr << "打开文件失败！程序结束" << endl;
        exit(EXIT_FAILURE);
    }

    string meg;
    while (getline(fin, meg))
    {
        fout << meg << endl;
    }
    
    if(fin.eof())
        cout << "读取完毕！\n";
    else if (fin.fail())
        cout << "读取异常！\n";
    else if (fin.bad())
		cout << "硬件故障!\n";

	fin.clear();
	fout.close();
	fin.close();

	return 0;
} 
