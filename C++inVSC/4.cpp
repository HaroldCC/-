/////////////////////第四章//////////////////
/*1*/
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;

	cout << "输入你的第一个名字：";
	string first_name;
	getline(cin, first_name);
	cout << "输入你最后的名字：";
	string last_name;
	getline(cin, last_name);
	cout << "你的成绩等级是：";
	char level;
	cin >> level;
	level++;
	cout << "输入年龄：";
	int age;
	cin >> age;
	cout << "名字：" << last_name << "," << first_name << endl;
	cout << "等级:" << level << endl;
	cout << "年龄：" << age << endl;

	return 0;
}*/
/*2*/
/*#include<iostream>
#include<string>

int main()
{
	using namespace std;

	cout << "输入你的名字：\n";
	string name;
	getline(cin, name);

	cout << "输入你最喜欢的甜点：\n";
	string dessert;
	getline(cin, dessert);

	cout << name;
	cout << "，我这有一些为你准备的美味" << dessert << "。\n";

	return 0;
}*/
/*3*/
/*#include<iostream>
#include<cstring>

int main()
{
	using namespace std;

	const int StrSize = 20;

	cout << "输入你的名字：";
	char name[StrSize];
	cin.get(name, StrSize).get();

	cout << "输入你的姓氏：";
	char surname[StrSize];
	cin.get(surname, StrSize).get();

	cout << "你的全名为：";
	char fullname[StrSize * 2];
	strcpy_s(fullname, surname);
	strcat_s(fullname, ",");
	strcat_s(fullname, name);

	cout << fullname << endl;

	return 0;
}*/
/*4*/
/*#include<iostream>
#include<string>

int main()
{
	using namespace std;

	cout << "输入你的名字：";
	string name;
	getline(cin, name);

	cout << "输入你的姓氏：";
	string surname;
	getline(cin, surname);

	cout << "你的全名是：";
	string fullname;
	fullname = surname + "," + name;
	cout << fullname << endl;

	return 0;
}*/
/*5*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{
	//声明结构体
	struct CandyBar
	{
		string kind;
		float weight;
		int calories;
	};

	CandyBar snack = { "Mocha Munch", 2.3, 350 };

	cout << "kind:" << snack.kind << endl;
	cout << "weight:" << snack.weight << endl;
	cout << "calories:" << snack.calories << endl;

	return 0;
}*/
/*6*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{
		//声明结构体
		struct CandyBar
		{
			string kind;
			float weight;
			int calories;
		};

		CandyBar snack[2] = { {"Mocha Munch", 2.3, 350 },
		{"Mocha Munch", 2.3, 350 } };
		for (int i = 0; i < 2; i++)
		{
			cout << "kind:" << snack[i].kind << endl;
			cout << "weight:" << snack[i].weight << endl;
			cout << "calories:" << snack[i].calories << endl;
		}

		return 0;
}*/
/*7*/
/*#include<iostream>
#include<string>

using namespace std;

//结构体声明
struct Pizz
{
	string company;
	float diameter;
	float weight;

};

int main()
{
	//s声明结构体变量
	Pizz p;

	cout << "输入披萨公司的名称：";
	getline(cin, p.company);

	cout << "输入披萨的直径：";
	cin >> p.diameter;

	cout << "输入披萨的重量：";
	cin >> p.weight;

	//输出
	cout << "公司：";
	cout << p.company << endl;
	cout << "直径：" << p.diameter << endl;
	cout << "重量：" << p.weight << endl;


	return 0;
}*/
/*8*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{

	//结构体声明
	struct Pizz
	{
		string company;
		float diameter;
		float weight;
	};

	Pizz * p = new Pizz;

	cout << "输入披萨公司的名称：";
	getline(cin, p->company);

	cout << "输入披萨的直径：";
	cin >> p->diameter;

	cout << "输入披萨的重量：";
	cin >> p->weight;

	//输出
	cout << "公司：";
	cout << p->company << endl;
	cout << "直径：" << p->diameter << endl;
	cout << "重量：" << p->weight << endl;

	delete p;

	return 0;
}*/
/*9*/
/*#include<iostream>

using namespace std;

int main()
{
	//声明结构体
	struct CandyBar
	{
		string kind;
		float weight;
		int calories;
	};

	//创建动态数组
	CandyBar* snack = new CandyBar[2];

	//结构体数组赋值
	for (int i = 0; i < 2; i++)
	{
		snack[i] = {"Mocha Munch", 2.3, 350 };
	}

	//输出
	for (int i = 0; i < 2; i++)
	{
		cout << "kind:" << snack[i].kind << endl;
		cout << "weight:" << snack[i].weight << endl;
		cout << "calories:" << snack[i].calories << endl;
	}

	//释放空间
	delete[] snack;

	return 0;
}*/
/*10*/
//#include<iostream>
//#include<array>
//
//int main()
//{
//	using namespace std;
//
//	//声明array对象
//	array<double, 3>grades;
//
//	for (int i = 0, j = 1; i < 3 && j <=3; i++, j++)
//	{
//		cout << "输入你第" << j << "次的短跑成绩：";
//		cin >> grades[i];
//	}
//
//	double avg = (grades[0] + grades[1] + grades[2]) / 3;
//	cout << "你的平均成绩为：" << avg << endl;
//
//	return 0;
//}