////////////////�����ϰ�ڶ���/////////////////////////////
/*1*/
/*
#include<iostream>
int main()
{
	using namespace std;

	cout << "����";
	cout << "ס�ڱ���" << endl;

	return 0;
}
*/
/*2*/
/*
#include<iostream>
int main()
{
	using namespace std;

	cout << "����һ��longΪ��λ�ľ��룺";
	long distance;
	cin >> distance;
	cout << distance << "long����" << distance * 220 << "�롣\n";

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

	cout << "����������䣬����������������·�����";
	int age;
	cin >> age;
	cout << "����" << age * 12 << "���·ݡ�" << endl;

	return 0;
}
*/
/*5*/
/*
#include<iostream>

//�����¶�תΪ�����¶�
double Celsius_to_Fahrenheit(double Celsius)
{
	double Fahrenheit = 0;

	Fahrenheit = Celsius * 1.8 + 32.0;

	return Fahrenheit;

}

int main()
{
	using namespace std;

	cout << "����һ�����϶�:";
	double Celsius;
	cin >> Celsius;

	double Fahrenheit;
	//��������
	Fahrenheit = Celsius_to_Fahrenheit(Celsius);
	cout << Celsius << "���϶ȵ���" << Fahrenheit << "���϶�.\n";

	return 0;
}*/
/*6*/
/*#include<iostream>

using namespace std;

//����ת��Ϊ���ĵ�λ
double lightYear_to_astronomicalUnits(double light_year)
{
	double astronomicalUnits = 0;
	astronomicalUnits = light_year * 63240;

	return astronomicalUnits;
}

int main()
{
	cout << "����һ������ֵ��";
	double light_year;
	cin >> light_year;

	double astronomicalUnits;
	astronomicalUnits = lightYear_to_astronomicalUnits(light_year);

	cout << light_year << "���� = " << astronomicalUnits << "���ĵ�λ��\n";

	return 0;
}*/
/*7*/
#include<iostream>

using namespace std;

void Time(int hours, int minutes)
{
	cout << "ʱ�䣺" << hours << ":" << minutes << endl;
}

int main()
{
	int hours, minutes;

	cout << "����Сʱ����";
	cin >> hours;
	cout << "�����������";
	cin >> minutes;

	Time(hours, minutes);

	return 0;
}