/*************************************************************************
    > File Name       : Cpmv.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-28 17:04:41
 ************************************************************************/
#include<string>
#include<iostream>

class Cpmv
{
	public:
		struct Info
		{
			std::string qcode;
			std::string zcode;
		};

	private:
		Info* pi;
	public:
		Cpmv();
		Cpmv(std::string q, std::string z);
		Cpmv(const Cpmv& cp);
		Cpmv(Cpmv && mv);
		~Cpmv();
		Cpmv& operator= (const Cpmv& cp);
		Cpmv& operator= (Cpmv && mv);
		Cpmv operator+ (const Cpmv& obj) const;
		void Display() const;
};


Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "qcode";
	pi->zcode = "zcode";
	std::cout << "默认构造函数。\n";
}
Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	std::cout << "字符串构造函数。\n";
}
Cpmv::Cpmv(const Cpmv& cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "复制构造函数。\n";
}
Cpmv::Cpmv(Cpmv && mv)
{
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	std::cout << "移动构造函数。\n";
}
Cpmv::~Cpmv()
{
	delete pi;
	std::cout << "析构函数。\n";
}
Cpmv& Cpmv::operator= (const Cpmv& cp)
{
	std::cout << "复制赋值运算符。\n";
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}
Cpmv& Cpmv::operator= (Cpmv && mv)
{
	std::cout << "移动赋值运算符。\n";
	if (this == &mv)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	return *this;
}
Cpmv Cpmv::operator+ (const Cpmv& obj) const
{
	std::cout << "加号运算符。\n";
	Cpmv sum;
	sum.pi->qcode = this->pi->qcode + obj.pi->qcode;
	sum.pi->zcode = this->pi->zcode + obj.pi->zcode;
	return sum;
}
void Cpmv::Display() const
{
	std::cout << "qcode: " << this->pi->qcode << std::endl;
	std::cout << "zcode: " << this->pi->zcode << std::endl;
	std::cout << std::endl;
}


int main(int argc,char *argv[])
{
	using std::cout;
	using std::endl;


	Cpmv temp;
	cout << "O 1:\n";
	temp.Display();

	Cpmv temp1("number one", "number two");
	cout << "O 2:\n";
	temp1.Display();

	Cpmv temp2(temp);
	cout << "O 3:\n";
	temp2.Display();

	cout << "O 3 = O 1:\n";
	Cpmv temp3;
	temp3 = temp1;
	cout << "O 3:\n";
	temp3.Display();
	cout << "O 1:\n";
	temp1.Display();

	cout << "O 4 = move(O 2):\n";
	Cpmv temp4;
	temp4 = temp2;
	cout << "O 4:\n";
	temp4.Display();
	cout << "O 2:\n";
	temp2.Display();

	cout << "O 5 = O 3 + O 4:\n";
	Cpmv temp5 = temp3 + temp4;
	cout << "O 5:\n";
	temp5.Display();
     
    return 0;
}

