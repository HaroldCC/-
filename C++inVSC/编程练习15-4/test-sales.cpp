/*************************************************************************
    > File Name       : test-sales.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 17:40:20
 ************************************************************************/
#include<iostream>
#include "sales.h"


int main(int argc,char *argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] = {
		1220, 1100, 1122, 2212, 1232, 2334, 
		2884, 2393, 3302, 2922, 3302, 3544
	};

	double vals2[12] = {
		12, 11, 22, 21, 32, 34, 
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch(std::logic_error & bad)
	{
		Sales::bad_index * pbd;
		LabeledSales::nbad_index * pnbd;
		if (pbd = dynamic_cast<LabeledSales::nbad_index *>(&bad))
				{
				cout << pbd->what();
				cout << "Company: " << pnbd->label_val() << endl;
				cout << "bad index: " << pnbd->bi_val() << endl;
				}
				else if (pbd = dynamic_cast<Sales::bad_index *>(&bad))
				{
					cout << pbd->what();
					cout << "bad index: " << pbd->bi_val() << endl;
				}
				else
					cout << "未确认的异常!" << endl;
	}

	 cout << "\nNext try block:\n";
	 try
	 {
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	 }
	 catch(LabeledSales::nbad_index & bad)
	 {
		cout << bad.what();
		cout << "company:" << bad.label_val() << endl;
		cout << "bad index:" << bad.bi_val() << endl;
	 }
	 catch(Sales::bad_index & bad)
	 {
		 cout << bad.what();
		 cout << "bad index: " << bad.bi_val() << endl;
	 }
	 cout << "done!\n";
     
    return 0;
}

