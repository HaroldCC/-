/*************************************************************************
    > File Name       : friends.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-23 19:58:10
 ************************************************************************/
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main(int argc,char *argv[])
{
	vector<string> mat;
	vector<string> pat;
	vector<string> all;
	


	ifstream fmat("mat.dat", ios_base::in);
	ifstream fpat("pat.dat", ios_base::in);
	if (!fmat.is_open() && !fpat.is_open())
	{
		cerr << "打开读取文件失败！程序退出！\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout("matnpat.dat", ios_base::out);
	if(!fout.is_open())
	{
		cerr << "打开输出文件失败！程序退出！\n";
		exit(EXIT_FAILURE);
	}

	string name;

	while (!fmat.eof())
	{
		fmat >> name;
		mat.push_back(name);
	}
	cout << "mat's friends: " << endl;
	for (auto it = mat.begin(); it != mat.end(); it++)
		cout << *it << "\t";
	cout << endl;

	while (fpat >> name)
		pat.push_back(name);
	cout << "pat's friends: " <<  endl;
	for (auto it = pat.begin(); it != pat.end(); it++)
		cout << *it << "\t";
	cout << endl;

	// 合并mat与pat的朋友，放到新文件中
	all.reserve(mat.size() + pat.size());           // 分配空间
	all.insert(all.end(), mat.begin(), mat.end());
	all.insert(all.end(), pat.begin(), pat.end());

	sort(all.begin(), all.end());
	unique(all.begin(), all.end());

	cout << "all friends: " << endl;
	for (auto it = all.begin(); it != all.end(); it++)
	{
		cout << *it << "\t";
		fout << *it << "\t";
	}
	cout << endl;

	fmat.clear();
	fpat.clear();
	fout.close();
	fmat.close();
	fpat.close();

    return 0;
}

