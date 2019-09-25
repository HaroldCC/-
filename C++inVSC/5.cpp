////////////////////第五章///////////////////////////////
/*1*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "输入两个整数，将会输出这两个整数中所有整数的和：\n";
	cout << "输入第一个较小的整数：";
	int num1;
	cin >> num1;
	cout << "输入第二个较大的整数：";
	int num2;
	cin >> num2;

	int sum = 0;

	for (int i = num1; i <= num2; i++)
	{
		sum += i;
	}

	cout << num1 << "到" << num2 << "之间所有整数的和为" << sum << endl;

	return 0;
}*/
/*2*/
/*#include<iostream>
#include<array>

const int ArSize = 100;

int main()
{
	using namespace std;

	array <long double, ArSize> factorials;
	factorials[1] = factorials[0] = 1.0;

	//计算阶乘
	for (int i = 2; i < ArSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}

	//输出
	for (int i = 0; i < ArSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}

	return 0;
}*/
/*3*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "请输入数字，将会计算所有输入数字的和（输入0结束））" << endl;
	cout << "输入一个数字：";
	int num, sum = 0;
	cin >> num;
	while (num != 0)
	{
		sum += num;
		cout << sum << endl;
		cout << "继续输入（输入0推出）：";
		cin >> num;
	}

	cout << "结束！\n";

	return 0;
}*/
/*4*/
/*#include<iostream>

const double DaphneRate = 10.0;
const double CleoRate = 1.05;

const double BaseMoney = 100.0;

int main()
{
	using namespace std;

	double Daphne = BaseMoney;
	double Cleo = BaseMoney;

	int year;

	for (year = 1; Daphne >= Cleo; year++)
	{
		Daphne += DaphneRate;
		Cleo *= CleoRate;
	}

	cout << year << "年后，Daphne的投资价值才能超过Cleo。\n";
	cout << "Daphne:" << Daphne << "美元。\n";
	cout << "Cleo:" << Cleo << "美元。\n";

	return 0;
}*/
/*5*/
/*#include<iostream>
int main()
{
	using namespace std;

	//声明string对象数组
	string months[12] = {
		"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December"
	};

	int sales[12];
	for (int i = 0; i < 12; i++)
	{
		cout << "输入" << months[i] << "月的图书销售量：";
		cin >> sales[i];
	}

	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << months[i] << ":" << sales[i] << endl;
		sum += sales[i];
	}

	cout << "全年图书销售总量为：" << sum << endl;

	return 0;
}*/
/*6*/
/*#include<iostream>
int main()
{
	using namespace std;

	//声明string对象数组
	string months[12] = {
		"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December"
	};

	int sales[3][12];
	for (int i = 0; i < 3; i++)
	{
		cout << "年份" << i << ":" << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << "输入" << months[j] << "月的图书销售量：";
			cin >> sales[i][j];
		}
	}

	//输出
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "年份：" << i << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << months[j] << ":" << sales[i][j] << endl;
			sum += sales[i][j];
		}
	}

	cout << "全年图书销售量为：" << sum << endl;

	return 0;
}*/
/*7*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{
	

	//结构声明
	struct Car
	{
		string manufacturer;
		int make_year;
	};

	cout << "输入你拥有的汽车数量：";
	int ncar;
	cin >> ncar;
	cin.get();                                     //不能省略，会处理掉输入数量后产生的换行符

	//创建结构组成的动态数组
	Car* cars = new Car[ncar];
	for (int i = 0; i < ncar; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "请输入汽车生产商：";
		getline(cin, cars[i].manufacturer);
		cout << "请输入汽车的制造年份：";
		cin >> cars[i].make_year;
		cin.get();                                 //不能省略，会处理掉输入数量后产生的换行符
	}

	//输出
	cout << "下面是收集的信息：\n";
	for (int i = 0; i < ncar; i++)
	{
		cout << cars[i].make_year << " " << cars[i].manufacturer << endl;
	}

	delete[] cars;

	return 0;
}*/
/*8*/
/*#include<iostream>
#include<cstring>               //for strcmp()

const int Strlen = 20;

int main()
{
	using namespace std;

	char word[Strlen];

	cout << "输入一段话，将会统计单词个数（输入单词done将会停止）：\n";

	int sum = 0;
	cin >> word;
	while (strcmp(word, "done"))
	{
		sum++;
		cin >> word;
	}

	cout << "你输入的单词总数为：" << sum << endl;

	return 0;
}*/
/*9*/
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;

	string word;

	cout << "输入一段话，将会统计单词个数（输入单词done将会停止）：\n";

	int sum = 0;
	cin >> word;
	while (word != "done")
	{
		sum++;
		cin >> word;
	}

	cout << "你输入的单词总数为：" << sum << endl;

	return 0;
}*/
/*10*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "输入要打印的行：";
	int rows;
	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (rows - j > i + 1)                          //to thinking
				cout << ".";
			else
				cout << "*";
		}
		cout << endl;
	}

	return 0;
}*/
