/*************************************************************************
    > File Name       : 4.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 15:26:26
 ************************************************************************/
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{
	if (argc != 4)
	{
		cerr << "输入参数有误!\n";
		exit(EXIT_FAILURE);
	}

    ifstream fin1(argv[1], ios_base::in);
	ifstream fin2(argv[2], ios_base::in);

	ofstream fout(argv[3], ios_base::out);
	
	// 判断文件打开失败
	if (!(fin1.is_open() || fin2.is_open() || fout.is_open()))
	{
		cerr << "文件打开失败！程序结束！\n";
		exit(EXIT_FAILURE);
	}

	string str1, str2;
	
	// 将文件1文件2内容交叉复制到文件3 
	while (!fin1.eof() && !fin2.eof())
	{
		getline(fin1, str1);
		getline(fin2, str2);
		fout << str1 + " " + str2 << endl;
	}
	
	// 继续将文件1文件2剩下的内容进行复制到文件3
	while (!fin1.eof())
	{
		getline(fin1, str1);
		fout << str1 << endl;
	}
	while (!fin2.eof())
	{
		getline(fin2, str2);
		fout << str2 << endl;
	}


	// 错误检测
	if (fin1.eof() && fin1.eof())
		cerr << "读取完毕！\n";
	else if (fin1.fail() || fin2.fail())
		cerr << "读取异常！\n";
	else if (fin1.bad() || fin2.bad())
		cerr << "硬件故障！\n";

	fin1.clear();
	fin2.clear();
	fin1.close();
	fin2.close();
	fout.close();

    return 0;
}

