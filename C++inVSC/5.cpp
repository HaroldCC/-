////////////////////������///////////////////////////////
/*1*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "������������������������������������������ĺͣ�\n";
	cout << "�����һ����С��������";
	int num1;
	cin >> num1;
	cout << "����ڶ����ϴ��������";
	int num2;
	cin >> num2;

	int sum = 0;

	for (int i = num1; i <= num2; i++)
	{
		sum += i;
	}

	cout << num1 << "��" << num2 << "֮�����������ĺ�Ϊ" << sum << endl;

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

	//����׳�
	for (int i = 2; i < ArSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}

	//���
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

	cout << "���������֣�������������������ֵĺͣ�����0��������" << endl;
	cout << "����һ�����֣�";
	int num, sum = 0;
	cin >> num;
	while (num != 0)
	{
		sum += num;
		cout << sum << endl;
		cout << "�������루����0�Ƴ�����";
		cin >> num;
	}

	cout << "������\n";

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

	cout << year << "���Daphne��Ͷ�ʼ�ֵ���ܳ���Cleo��\n";
	cout << "Daphne:" << Daphne << "��Ԫ��\n";
	cout << "Cleo:" << Cleo << "��Ԫ��\n";

	return 0;
}*/
/*5*/
/*#include<iostream>
int main()
{
	using namespace std;

	//����string��������
	string months[12] = {
		"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December"
	};

	int sales[12];
	for (int i = 0; i < 12; i++)
	{
		cout << "����" << months[i] << "�µ�ͼ����������";
		cin >> sales[i];
	}

	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << months[i] << ":" << sales[i] << endl;
		sum += sales[i];
	}

	cout << "ȫ��ͼ����������Ϊ��" << sum << endl;

	return 0;
}*/
/*6*/
/*#include<iostream>
int main()
{
	using namespace std;

	//����string��������
	string months[12] = {
		"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December"
	};

	int sales[3][12];
	for (int i = 0; i < 3; i++)
	{
		cout << "���" << i << ":" << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << "����" << months[j] << "�µ�ͼ����������";
			cin >> sales[i][j];
		}
	}

	//���
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "��ݣ�" << i << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << months[j] << ":" << sales[i][j] << endl;
			sum += sales[i][j];
		}
	}

	cout << "ȫ��ͼ��������Ϊ��" << sum << endl;

	return 0;
}*/
/*7*/
/*#include<iostream>
#include<string>

using namespace std;

int main()
{
	

	//�ṹ����
	struct Car
	{
		string manufacturer;
		int make_year;
	};

	cout << "������ӵ�е�����������";
	int ncar;
	cin >> ncar;
	cin.get();                                     //����ʡ�ԣ��ᴦ�����������������Ļ��з�

	//�����ṹ��ɵĶ�̬����
	Car* cars = new Car[ncar];
	for (int i = 0; i < ncar; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "���������������̣�";
		getline(cin, cars[i].manufacturer);
		cout << "������������������ݣ�";
		cin >> cars[i].make_year;
		cin.get();                                 //����ʡ�ԣ��ᴦ�����������������Ļ��з�
	}

	//���
	cout << "�������ռ�����Ϣ��\n";
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

	cout << "����һ�λ�������ͳ�Ƶ��ʸ��������뵥��done����ֹͣ����\n";

	int sum = 0;
	cin >> word;
	while (strcmp(word, "done"))
	{
		sum++;
		cin >> word;
	}

	cout << "������ĵ�������Ϊ��" << sum << endl;

	return 0;
}*/
/*9*/
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;

	string word;

	cout << "����һ�λ�������ͳ�Ƶ��ʸ��������뵥��done����ֹͣ����\n";

	int sum = 0;
	cin >> word;
	while (word != "done")
	{
		sum++;
		cin >> word;
	}

	cout << "������ĵ�������Ϊ��" << sum << endl;

	return 0;
}*/
/*10*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "����Ҫ��ӡ���У�";
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
