#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
#include<string>

#include<iostream>

//定义银行账户类
class bankaccount
{
private:
	std::string name;               //储户姓名
	std::string account;                //账号
	double money;                      //存款
public:
	bankaccount();                 //无参构造函数声明
	bankaccount(const std::string & n, const std::string & a, double m = 0.0);           //有参构造函数声明
	~bankaccount();                          //析构函数声明
	void showBankaccount(void) const;           //显示类
	void deposit(double cash);                 //存款
	void withdraw(double cash);               //取款
};

#endif