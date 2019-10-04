#include<iostream>
#include "bankaccount.h"

//无参构造函数声明
bankaccount::bankaccount() {
	name = "";
	account = "";
	money = 0.0;
}

//有参构造函数声明
bankaccount::bankaccount(const std::string & n, const std::string & a, double m) {
	name = n;
	account = a;
	money = m;
}

//析构函数声明
bankaccount::~bankaccount() {

}

void bankaccount::showBankaccount(void) const {
	std::cout << "储户姓名：" << name << std::endl;
	std::cout << "账号：" << account << std::endl;
	std::cout << "剩余存款：" << money << std::endl;
}

void bankaccount::deposit(double cash) {
	if (cash < 0)
	{
		std::cout << "存款金额不能为负！" << std::endl;
	}
	else
	{
		money += cash;
	}

}

void bankaccount::withdraw(double cash) {
	if (cash < 0)
	{
		std::cout << "取款金额不能为负！" << std::endl;
	}
	else
	{
		money -= cash;
	}

}