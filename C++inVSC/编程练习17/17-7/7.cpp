/*************************************************************************
    > File Name       : 7.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-24 8:50:20
 ************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

class Store
{
	private:
		std::ostream& os;
	public:
		Store(std::ostream& fout) : os(fout) { }
		void operator()(const std::string& str)
		{
			int len = str.size();
			os.write((char*) &len, sizeof(std::size_t));
			os.write(str.data(), len);
		}

};

using namespace std;

void ShowStr(const string& str)
{
	cout << str << endl;
}


void GetStr(ifstream& fin, vector<string>& vistr)
{
		int len;
		string temp;
		while (fin.read((char*) &len, sizeof(size_t)))
		{
			char* str = new char[len + 1];
			fin.read(str, len);
			str[len] = '\0';
			vistr.push_back(str);
			delete [] str;
		}
}

int main(int argc,char *argv[])
{
	vector<string> vostr;
	string temp;

	cout << "输入字符串（空行退出）:\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "这是你的输入：\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("Strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("Strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "打开输入文件失败！\n";
		exit(EXIT_FAILURE);
	}
	GetStr(fin, vistr);
	cout << "\n以下是文件中的字符串：\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
     
    return 0;
}

