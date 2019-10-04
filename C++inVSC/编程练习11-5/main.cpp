#include "stonewt.h"
#include<iostream>

int main(void)
{
    Stonewt zhangsan(275, Stonewt::FLOPD);
    Stonewt lisi(285.7, Stonewt::STN);
    Stonewt wangwu(21, 8, Stonewt::INTPD);
    Stonewt temp;

    std::cout << "�������أ�";
    std::cout << zhangsan << std::endl;

    std::cout << "�������أ�";
    std::cout << lisi << std::endl;

    std::cout << "�������أ�";
    std::cout << wangwu << std::endl;

    std::cout << "temp = " << temp << std::endl;

    temp = zhangsan + lisi;
    std::cout << "�������� + �������� = " << temp <<std::endl;

    temp = lisi - zhangsan;
    std::cout << "�������� - �������� = " << temp << std::endl;

    temp = wangwu * 10.0;
    std::cout << "�������� * 10.0 = " << temp << std::endl;

    temp = 10.0 * wangwu;
    std::cout << "10.0 * �������� = " << temp << std::endl;
    
    system("pause");
    return 0;
}