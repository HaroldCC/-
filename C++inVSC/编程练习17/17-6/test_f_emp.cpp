/*************************************************************************
    > File Name       : test_f_emp.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-28 13:13:29
 ************************************************************************/
#include<iostream>
#include"emp.h"
#include<fstream>

using namespace std;

inline void show_line(int n)
{
	cout.fill('-');
	cout.width(n);
	cout << "-" << endl;
	cout.fill(' ');
}

void show_menu(void)
{
	ios_base::fmtflags old_fmt = cout.setf(ios_base::left, ios_base::adjustfield);
	
	show_line(35);
	cout.width(20);
	cout << "a. employee";
	cout << "b. manager" << endl;
	cout.width(20);
	cout << "c. fink";
	cout << "d. highfink" << endl;
	cout << "q. quit" << endl;
	show_line(35);
	cout << "选择一种类型：" << endl;

	cout.setf(old_fmt);
}

inline void eatline(void)
{
	while (cin.get() != '\n')
			continue;
}

const int MAX = 10;

int main(int argc,char *argv[])
{
	abstr_emp* pc[MAX];
	int ct = 0;

	string fname, lname, job, reportsto;
	int inchargeof;

	ifstream fin("out.txt", ios_base::in);
	if (fin.is_open())
	{
		int kind;
		while (fin >> kind)
		{
			switch(kind)
			{
				case Employee:
					fin >> fname;
					fin >> lname;
					fin >> job;
					pc[ct] = new employee(fname, lname, job);
					break;
				case Manager:
					fin >> fname;
					fin >> lname;
					fin >> job;
					fin >> inchargeof;
					pc[ct] = new manager(fname, lname, job, inchargeof);
					break;
				case Fink:
					fin >> fname;
					fin >> lname;
					fin >> reportsto;
					pc[ct] = new fink(fname, lname, job, reportsto);
					break;
				case HighFink:
					fin >> fname;
					fin >> lname;
					fin >> job;
					fin >> reportsto;
					fin >> inchargeof;
					pc[ct] = new highfink(fname, lname, job, reportsto, inchargeof);
					break;
			}
			ct++;
		}

		// 显示文件内容
		cout << "文件out.txt内容如下：\n";
		for (int i = 0; i < ct; i++)
			pc[i]->ShowAll();
	}
	else 
	{
		cout << "打开输入文件失败！程序退出！\n";
		exit(EXIT_FAILURE);
	}


	show_menu();
	char choice;
	abstr_emp* p;
	while (cin >> choice && choice != 'q' && ct < MAX)
	{
		eatline();
		switch(choice)
		{
			case 'a':
				p = new employee;
				p->SetAll();
				pc[ct] = p;
				break;
			case 'b':
				p = new manager;
				p->SetAll();
				pc[ct] = p;
				break;
			case 'c':
				p = new fink;
				p->SetAll();
				pc[ct] = p;
				break;
			case 'd':
				p = new highfink;
				p->SetAll();
				pc[ct] = p;
				break;
		}
		ct++;
		show_menu();
	}


	// 显示所有的输入
	for (int i = 0; i < ct; i++)
		pc[i]->ShowAll();

	// 将数据写入文件
	ofstream fout("out.txt", ios_base::out);
	for (int i = 0; i < ct; i++)
	{
		pc[i]->WriteAll(fout);
		fout << endl;
	}
	fout.close();

	// 释放数组空间
	for (int i = 0; i < ct; i++)
		delete pc[i];
     
    return 0;
}

