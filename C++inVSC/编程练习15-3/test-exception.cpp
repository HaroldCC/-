/*************************************************************************
    > File Name       : test-exception.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 16:33:04
 ************************************************************************/
#include<iostream>
#include"exception.h"
#include<cmath>

using namespace std;

double hmean(double a, double b){
	if (a == -b)
		throw hmean_error(a, b, "hmean()");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b){
	if (a < 0 || b < 0)
		throw gmean_error(a, b, "gmean()");
	return std::sqrt(a * b);
}

int main(int argc,char *argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "输入两个数字:";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "调和平均数" << x << "和" << y << " is " << z << endl;
			cout << "几何平均值" << x << "和" << y << " is " << gmean(x, y)<< endl;
			cout << "输入下一组数<q退出>:";
		}
		catch(hmean_error & he)
		{
			he.mesg();
			cout << "再试一次！" << endl;
			continue;
		}
		catch(gmean_error & ge)
		{
			ge.mesg();
			cout << "Sorry,程序结束！" << endl;
			break;
		}
		catch(arg_error & ae)
		{
			ae.mesg();
			cout << "Sorry, 程序结束！\n";
			break;
		}
	}
	cout << "Bye!\n";
     
    return 0;
}

