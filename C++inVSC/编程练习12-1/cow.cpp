/*************************************************************************
    > File Name       : cow.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-13 19:43:28
 ************************************************************************/
#include"cow.h"
#include<iostream>
#include<cstring>                //for strcpy() 用于拷贝字符串

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{	
	strncpy(name, nm, 20);

	int len = strlen(ho);
	hobby = new char[len + 1];                  //为字符指针hobby申请内存

	strncpy(hobby, ho, 20);

	weight = wt;
}

Cow::Cow(const Cow & c)
{
	strncpy(name, c.name, 20);

	int len = strlen(c.hobby);
	hobby = new char[len  + 1];
	strncpy(hobby, c.hobby, 20);

	weight = c.weight;
}

Cow & Cow::operator= (const Cow & c)
{
	strncpy(name, c.name, 20);
	int len = strlen(c.hobby);
	hobby = new char[len+ 1];                          //再次申请空间
	strncpy(hobby, c.hobby, 20);

	weight = c.weight;
	
	delete [] hobby;
	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "Name:" << name << std::endl;
	std::cout << "Hobby:" << hobby << std::endl;
	std::cout << "Weight:" << weight << std::endl;
}

Cow::~Cow()
{

	delete [] hobby;
	hobby = nullptr;
}
