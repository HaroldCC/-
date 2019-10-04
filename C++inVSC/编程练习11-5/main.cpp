#include "stonewt.h"
#include<iostream>

int main(void)
{
    Stonewt zhangsan(275, Stonewt::FLOPD);
    Stonewt lisi(285.7, Stonewt::STN);
    Stonewt wangwu(21, 8, Stonewt::INTPD);
    Stonewt temp;

    std::cout << "张三体重：";
    std::cout << zhangsan << std::endl;

    std::cout << "李四体重：";
    std::cout << lisi << std::endl;

    std::cout << "王五体重：";
    std::cout << wangwu << std::endl;

    std::cout << "temp = " << temp << std::endl;

    temp = zhangsan + lisi;
    std::cout << "张三体重 + 李四体重 = " << temp <<std::endl;

    temp = lisi - zhangsan;
    std::cout << "李四体重 - 张三体重 = " << temp << std::endl;

    temp = wangwu * 10.0;
    std::cout << "王五体重 * 10.0 = " << temp << std::endl;

    temp = 10.0 * wangwu;
    std::cout << "10.0 * 王五体重 = " << temp << std::endl;
    
    system("pause");
    return 0;
}