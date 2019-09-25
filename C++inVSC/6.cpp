/////////////////////第六章////////////////////////
/*1*/
/*#include<iostream>
#include<cctype>
int main()
{
	using namespace std;

	char ch;
	cin.get(ch);
	while (ch != '@')
	{
		if (isupper(ch))
			ch = tolower(ch);
		else if (islower(ch))
			ch = toupper(ch);
		if (!(isdigit(ch)))
			cout << ch << endl;
		cin.get(ch);
	}

	return 0;
}*/
/*2*/
/*#include<iostream>
#include<cctype>
#include<array>
using namespace std;

int main()
{

	array<double, 10>donations;

	cout << "输入不超过10个数字，进行计算。（非数字输入将退出）：";

	double donation;
	double avg = 0;
	double sum = 0;

	int index = 0;

	//输入
	while (cin >> donation)
	{
		if (index < 10)
		{
			donations[index] = donation;
			sum += donation;
			index++;
		}
		else
		{
			break;
		}
	}
	avg = sum / index;
	cout << "平均值为：" << avg << endl;

	//输出
	int n = 0;
	for (int i = 0; i <= index; i++)
	{
		if (donations[i] > avg)
		{
			n++;
		}
	}
	cout << "有" << n << "个数字大于平均值。\n";

	return 0;
}*/
/*3*/
/*#include<iostream>

using namespace std;

//函数声明
void showMenu(void)
{
	cout << "请输入一个下列菜单的选项代号进行选择：\n";
	cout << "c)carnivore\tp)pianist"
		"\nt)tree\tg)game\nf)quite\n";
	cout << "请输入 c, p , t, g(或f退出):";
}

int main()
{
	//调用函数
	showMenu();

	char choice;
	cin >> choice;

	while (choice != 'f')
	{
		switch (choice)
		{
		case 'c': cout << "A maple is a carnivore."; break;
		case 'p': cout << "A maple is a pianist."; break;
		case 't': cout << "A maple is a tree."; break;
		case 'g': cout << "A maple is a game."; break;
		default:
			break;
		}

		cout << endl;
		cout << endl;
		cout << "请输入 c, p , t, g(或f退出):";
		cin >> choice;
	}

	return 0;
}*/
/*4*/
/*#include<iostream>

const int strsize = 20;

using namespace std;

//BOP参与者名字结构
struct bop
{
	char fullname[strsize];         //真实姓名
	char title[strsize];            //头衔
	char bopname[strsize];          //秘密姓名
	int premerence;                 //0 = fullname, 1 = title, 2 = bopname
};

//结构赋值
bop member[5] = {
		{"Wimp Macho", "Wimp Macho", "SB1", 0},
		{"Raki Rhodes", "Junior Programmer", "SB2", 1},
		{"Celia Laiter", "MIPS", "SB3", 2},
		{"Hoppy Hipman", "Analyst Trainee", "SB4", 1},
		{"Pat Hand", "LOOPY", "SB5", 1}
};

//菜单函数
void showMenu(void)
{
	cout << "程序员的仁慈秩序报告\n";
	cout << "a.按名字显示\tb.按头衔显示\n"
		"c.按秘密姓名显示\td.按偏好显示\n"
		"q.quite\n";
	cout << "输入你的选择代号：";
}

//按名字显示
void name(void) {
	for (int i = 0; i < 5; i++)
	{
		cout << member[i].fullname << endl;
	}
}

//按头衔显示
void title(void) {
	for (int i = 0; i < 5; i++)
	{
		cout << member[i].title << endl;
	}
}

//按秘密姓名显示
void bopname(void) {
	for (int i = 0; i < 5; i++)
	{
		cout << member[i].bopname << endl;
	}
}

//按偏好显示
void preference(void) {
	for (int i = 0; i < 5; i++)
	{
		switch (member[i].premerence)
		{
		case 0:cout << member[i].fullname << endl; break;
		case 1:cout << member[i].title << endl; break;
		case 2:cout << member[i].bopname << endl; break;
		default:;
		}
	}
}

int main()
{
	showMenu();

	char choice;
	cin >> choice;
	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a': name(); break;
		case 'b':title(); break;
		case 'c':bopname(); break;
		case 'd':preference(); break;
		default:;
			break;
		}
		cout << endl;
		cout << "输入你的选择代号：";
		cin >> choice;
	}
	cout << "done!\n";

	return 0;
}*/
/*5*/
/*#include<iostream>
const double Rate1 = 0.1;
const double Rate2 = 0.15;
const double Rate3 = 0.2;

int main()
{
	using namespace std;

	double money;
	double tax = 0;
	cout << "输入你的收入：";

	while (cin >> money && money >= 0)
	{
		if (money <= 5000)
		{
			cout << "所得税为" << tax << "tvarps" << endl;
		}
		else if (money > 5000 && money <= 15000)
		{
			tax = 5000 * 0.00 + (money - 5000) * Rate1;
			cout << "所得税为" << tax << "tvarps" << endl;
		}
		else if (money > 15000 && money <= 35000)
		{
			tax = 5000 * 0.00 + 10000 * Rate1 + (money - 5000 - 10000) * Rate2;
			cout << "所得税为" << tax << "tvarps" << endl;
		}
		else
		{
			tax = 5000 * 0.00 + 10000 * Rate1 + 20000 * Rate2 + (money - 5000 - 10000 - 20000) * Rate3;
			cout << "所得税为" << tax << "tvarps" << endl;
		}

		cout << "输入你的收入：";
	}

	return 0;
}*/
/*6*/
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;

	struct Patron
	{
		string name;
		double money;
	};

	int np;
	cout << "输入捐款者的数量：";
	cin >> np;

	Patron* pt = new Patron [np];

	for (int i = 0; i < np; i++)
	{
		cout << "输入捐款者的姓名：";
		cin >> (pt + i)->name;
		cout << "输入捐款数额：";
		cin >> (pt + i)->money;
	}

	cout << "重要捐款人：\n";
	for (int i = 0; i < np; i++)
	{
		if ((pt + i)->money > 10000)
		{
			cout << (pt + i)->name << endl;
		}
	}

	delete[] pt;

	return 0;
}*/
/*7*/
/*#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{

	cout << "输入单词（q退出）\n";
	string word;
	cin >> word;

	int vowel = 0, consonant = 0, other = 0;

	char first_ch;

	while (word != "q")
	{
		//判断是否字母开头
		first_ch = word[0];
		if (isalpha(first_ch))
		{
			//判断元音或辅音
			switch (first_ch)
			{
			case 'a':
				vowel++;
				break;
			case 'A':
				vowel++;
				break;
			case 'e':
				vowel++;
				break;
			case 'E':
				vowel++;
				break;
			case 'i':
				vowel++;
				break;
			case 'I':
				vowel++;
				break;
			case 'o':
				vowel++;
				break;
			case 'O':
				vowel++;
				break;
			case 'u':
				vowel++;
				break;
			case 'U':
				vowel++;
				break;
			default:
				consonant++;
			}
		}
		else
		{
			other++;
		}
		cin >> word;
	}

	cout << vowel << "个单词以元音打头。\n";
	cout << consonant << "个单词以辅音打头。\n";
	cout << other << "个其他音打头。\n";

	return 0;
}*/
/*8*/
/*#include<iostream>
#include<fstream>
int main()
{
	using namespace std;

	ifstream infile;
	infile.open("C:\\Users\\1921189869\\Desktop\\C++primer plus\\test.txt");

	char ch;
	int count = 0;
	while (infile >> ch)
	{
		count++;
	}

	infile.close();

	cout << "从文件中读取了" << count << "个字符。\n";

	return 0;
}*/
/*9*/
/*#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{

	struct Patron
	{
		string name;
		double money;
	};

	ifstream infile;
	infile.open("C:\\Users\\1921189869\\Desktop\\C++primer plus\\patrons.txt");

	if (!infile.is_open())
	{
		cout << "文件未打开，程序中止！" << endl;
		exit(EXIT_FAILURE);
	}
	int np;
	infile >> np;
	cout << np << endl;
	infile.get();
	Patron* pt = new Patron[np];

	for (int i = 0; i < np; i++)
	{
		getline(infile, (pt + i)->name);
		cout << (pt + i)->name << endl;
		infile >> (pt + i)->money;
		cout << (pt + i)->money << endl;
		infile.get();
	}

	cout << "重要捐款人：\n";
	for (int i = 0; i < np; i++)
	{
		if ((pt + i)->money > 10000)
		{
			cout << (pt + i)->name << endl;
		}
	}

	infile.close();

	delete[] pt;
	return 0;
}*/
#include<iostream>
using namespace std;
const int SLEN = 30;

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n) {
	int j = 1;                      //学生编号索引
	int i;
	for (i = 0; i < n; i++, j++)
	{
		cout << "输入学生#" << j << "的全名：";
		cin.getline(pa->fullname, SLEN);
		if (pa->fullname[0] == ' ')
		{
			break;
		}
		cout << "输入学生#" << j << "的爱好：";
		cin.getline(pa->hobby, SLEN);
		cout << "输入学生#" << j << "的ooplevel:";
		cin >> pa->ooplevel;
		cin.get();                        //清空缓冲区
	}
	return i;
}

void display1(student st) {
	cout << st.fullname << "的爱好是" << st.hobby;
	cout << "他的oop水平是" << st.ooplevel << "级。\n";
}

void display2(const student* ps) {
	cout << ps->fullname << "的爱好是" << ps->hobby;
	cout << "他的oop水平是" << ps->ooplevel << "级。\n";
}

void display3(const student pa[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << pa[i].fullname << "的爱好是" << pa[i].hobby;
		cout << "他的oop水平是" << pa[i].ooplevel << "级。\n";
	}

}

int main(void)
{
	cout << "输入班级人数：";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
	{
		continue;
	}

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;

	system("pause");
	return 0;
}