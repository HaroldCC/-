/////////////////////������//////////////////
/*1*/
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;

	cout << "������ĵ�һ�����֣�";
	string first_name;
	getline(cin, first_name);
	cout << "�������������֣�";
	string last_name;
	getline(cin, last_name);
	cout << "��ĳɼ��ȼ��ǣ�";
	char level;
	cin >> level;
	level++;
	cout << "�������䣺";
	int age;
	cin >> age;
	cout << "���֣�" << last_name << "," << first_name << endl;
	cout << "�ȼ�:" << level << endl;
	cout << "���䣺" << age << endl;

	return 0;
}*/
/*2*/
/*#include<iostream>
#include<string>

int main()
{
	using namespace std;

	cout << "����������֣�\n";
	string name;
	getline(cin, name);

	cout << "��������ϲ������㣺\n";
	string dessert;
	getline(cin, dessert);

	cout << name;
	cout << "��������һЩΪ��׼������ζ" << dessert << "��\n";

	return 0;
}*/
/*3*/
/*#include<iostream>
#include<cstring>

int main()
{
	using namespace std;

	const int StrSize = 20;

	cout << "����������֣�";
	char name[StrSize];
	cin.get(name, StrSize).get();

	cout << "����������ϣ�";
	char surname[StrSize];
	cin.get(surname, StrSize).get();

	cout << "���ȫ��Ϊ��";
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

	cout << "����������֣�";
	string name;
	getline(cin, name);

	cout << "����������ϣ�";
	string surname;
	getline(cin, surname);

	cout << "���ȫ���ǣ�";
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
	//�����ṹ��
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
		//�����ṹ��
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

//�ṹ������
struct Pizz
{
	string company;
	float diameter;
	float weight;

};

int main()
{
	//s�����ṹ�����
	Pizz p;

	cout << "����������˾�����ƣ�";
	getline(cin, p.company);

	cout << "����������ֱ����";
	cin >> p.diameter;

	cout << "����������������";
	cin >> p.weight;

	//���
	cout << "��˾��";
	cout << p.company << endl;
	cout << "ֱ����" << p.diameter << endl;
	cout << "������" << p.weight << endl;


	return 0;
}*/
/*8*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{

	//�ṹ������
	struct Pizz
	{
		string company;
		float diameter;
		float weight;
	};

	Pizz * p = new Pizz;

	cout << "����������˾�����ƣ�";
	getline(cin, p->company);

	cout << "����������ֱ����";
	cin >> p->diameter;

	cout << "����������������";
	cin >> p->weight;

	//���
	cout << "��˾��";
	cout << p->company << endl;
	cout << "ֱ����" << p->diameter << endl;
	cout << "������" << p->weight << endl;

	delete p;

	return 0;
}*/
/*9*/
/*#include<iostream>

using namespace std;

int main()
{
	//�����ṹ��
	struct CandyBar
	{
		string kind;
		float weight;
		int calories;
	};

	//������̬����
	CandyBar* snack = new CandyBar[2];

	//�ṹ�����鸳ֵ
	for (int i = 0; i < 2; i++)
	{
		snack[i] = {"Mocha Munch", 2.3, 350 };
	}

	//���
	for (int i = 0; i < 2; i++)
	{
		cout << "kind:" << snack[i].kind << endl;
		cout << "weight:" << snack[i].weight << endl;
		cout << "calories:" << snack[i].calories << endl;
	}

	//�ͷſռ�
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
//	//����array����
//	array<double, 3>grades;
//
//	for (int i = 0, j = 1; i < 3 && j <=3; i++, j++)
//	{
//		cout << "�������" << j << "�εĶ��ܳɼ���";
//		cin >> grades[i];
//	}
//
//	double avg = (grades[0] + grades[1] + grades[2]) / 3;
//	cout << "���ƽ���ɼ�Ϊ��" << avg << endl;
//
//	return 0;
//}