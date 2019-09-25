////////////////编程练习第二章/////////////////////////////
/*1*/
/*
#include<iostream>
int main()
{
	using namespace std;

	cout << "张三";
	cout << "住在北京" << endl;

	return 0;
}
*/
/*2*/
/*
#include<iostream>
int main()
{
	using namespace std;

	cout << "输入一个long为单位的距离：";
	long distance;
	cin >> distance;
	cout << distance << "long等于" << distance * 220 << "码。\n";

	return 0;
}
*/
/*3*/
/*
#include<iostream>

using namespace std;

void show_three(void)
{
	cout << "Three blind mice" << endl;
}

void show_see(void)
{
	cout << "See how run" << endl;
}

int main()
{
	show_three();
	show_three();
	show_see();
	show_see();

	return 0;
}
*/
/*4*/
/*
#include<iostream>
int main()
{
	using namespace std;

	cout << "输入你的年龄，输出你的年龄包含的月份数：";
	int age;
	cin >> age;
	cout << "包含" << age * 12 << "个月份。" << endl;

	return 0;
}
*/
/*5*/
/*
#include<iostream>

//摄氏温度转为华氏温度
double Celsius_to_Fahrenheit(double Celsius)
{
	double Fahrenheit = 0;

	Fahrenheit = Celsius * 1.8 + 32.0;

	return Fahrenheit;

}

int main()
{
	using namespace std;

	cout << "输入一个摄氏度:";
	double Celsius;
	cin >> Celsius;

	double Fahrenheit;
	//函数调用
	Fahrenheit = Celsius_to_Fahrenheit(Celsius);
	cout << Celsius << "摄氏度等于" << Fahrenheit << "华氏度.\n";

	return 0;
}*/
/*6*/
/*#include<iostream>

using namespace std;

//光年转换为天文单位
double lightYear_to_astronomicalUnits(double light_year)
{
	double astronomicalUnits = 0;
	astronomicalUnits = light_year * 63240;

	return astronomicalUnits;
}

int main()
{
	cout << "输入一个光年值：";
	double light_year;
	cin >> light_year;

	double astronomicalUnits;
	astronomicalUnits = lightYear_to_astronomicalUnits(light_year);

	cout << light_year << "光年 = " << astronomicalUnits << "天文单位。\n";

	return 0;
}*/
/*7*/
#include<iostream>

using namespace std;

void Time(int hours, int minutes)
{
	cout << "时间：" << hours << ":" << minutes << endl;
}

int main()
{
	int hours, minutes;

	cout << "输入小时数：";
	cin >> hours;
	cout << "输入分钟数：";
	cin >> minutes;

	Time(hours, minutes);

	return 0;
}