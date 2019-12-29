/*************************************************************************
    > File Name       : main.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 18:07:59
 ************************************************************************/
#include"class.h"
#include <cstring>

using namespace std;

int main(int argc,char *argv[])
{
	int n = 4;
	Person *pPerson[n];

	int i;
	for ( i = 0; i < n; i++)
	{
		char choice;
		cout << "输入类别：" << endl
			<< "o: Person    g:Gunslinger"
			<< "p:PokerPlayer     b:baddude    q:quit \n";

		cin >> choice;
		while (strchr("ogpbq", choice) == NULL)
		{
			cout << "请输入o,g,p,b,或q:";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch(choice)
		{
			case 'o': pPerson[i] = new Person; break;
			case 'g': pPerson[i] = new Gunslinger; break;
			case 'p': pPerson[i] = new PokerPlayer; break;
			case 'b': pPerson[i] = new BadDude; break;
		}

		cin.get();
	}

	cout << "\n list:\n";
	for (int j = 0; j < i; j++)
	{
		cout << endl;
		pPerson[j] -> Show();
	}

	for (int j = 0; j < i; j++)
		delete pPerson[i];

	cout << "bye!" << endl;
     
    return 0;
}

