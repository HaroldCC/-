//////////////////������//////////////////
/*1*/
/*#include<iostream>

//1Ӣ�� = 12 Ӣ��
const double inch_per_feet = 12.0L;

int main()
{
	using namespace std;

	cout << "���������ߣ���λ��Ӣ�磩��";

	double high_inch;
	cin >> high_inch;

	double high_feet = high_inch / inch_per_feet;

	cout << "������Ϊ" << high_feet << "Ӣ�ߡ�\n";

	return 0;
}*/
/*2*/
/*#include<iostream>

const double inch_per_feet = 12.0;
const double meter_per_inch = 0.0254;
const double pound_per_kilogram = 2.2;


int main()
{
	using namespace std;

	cout << "���������ߣ�����5Ӣ��3Ӣ�磩:";
	double high_feet = 0, high_inch = 0;
	cin >> high_feet >> high_inch;

	//Ӣ��Ϊ��λ�����ת��Ϊ����Ϊ��λ
	double high_meter = (high_inch + high_feet * inch_per_feet) * meter_per_inch;

	cout << "����������أ���λ��������";
	double weight_pound;
	cin >> weight_pound;

	//�԰�Ϊ��λ������ת��Ϊ��ǧ��Ϊ��λ
	double weight_kilogram = weight_pound / pound_per_kilogram;

	//����BMI
	double BMI = weight_kilogram / high_meter * high_meter;

	cout << "BMI:" << BMI << endl;

	return 0;
}*/
/*3*/
/*#include<iostream>

const int Seconds_per_Minuts = 60;
const int Minuts_per_Hours = 60;

int main()
{
	using namespace std;

	cout << "�Զȣ��֣���Ϊ��λ����һ��γ�ȡ�\n";
	cout << "���ȣ�����γ�ȵĶȣ�";
	double degrees;
	cin >> degrees;
	cout << "Ȼ������γ�ȵķ֣�";
	double minutes;
	cin >> minutes;
	cout << "�������γ�ȵ��룺";
	double seconds;
	cin >> seconds;

	double degrees_changed;
	degrees_changed = degrees + minutes / Minuts_per_Hours + seconds / Seconds_per_Minuts / Minuts_per_Hours;
	cout << degrees << "��" << minutes << "��" << seconds << "�� = " << degrees_changed << "�ȡ�\n";

	return 0;
}*/
/*4*/
/*#include<iostream>

const int Seconds_per_Minuts = 60;
const int Minuts_per_Hours = 60;
const int Hours_per_Days = 24;

int main()
{
	using namespace std;

	cout << "����һ����������ת��Ϊ�죬Сʱ�����ӣ�����ʾ��";
	long total_seconds;
	cin >> total_seconds;

	//��ȡ����
	int seconds = total_seconds % Seconds_per_Minuts;
	
	int total_minuts = total_seconds / Seconds_per_Minuts;

	//��ȡ������
	int minuts = total_minuts % Minuts_per_Hours;

	int total_hours = total_minuts / Minuts_per_Hours;

	//��ȡСʱ��
	int hours = total_hours % Hours_per_Days;

	//��ȡ����
	int days = total_hours / Hours_per_Days;

	//������
	cout << total_seconds << "�� = ";
	cout << days << "�죬";
	cout << hours << "Сʱ��";
	cout << minuts << "���ӣ�";
	cout << seconds << "�롣\n";

	return 0;
}*/
/*5*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "����ȫ���˿�����";
	long long world_populations;
	cin >> world_populations;
	cout << "���������˿�����";
	long long us_populations;
	cin >> us_populations;

	double usPop_of_worldPop = double(us_populations) / double(world_populations);
	cout << "�����˿�ռ�����˿�����" << usPop_of_worldPop << "%" << endl;

	return 0;
}*/
/*6*/
//pass