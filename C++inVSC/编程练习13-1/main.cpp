#include "classic.h"
#include <iostream>

using namespace std;

void Bravo(const Cd & disk)
{
    disk.Report();
}

int main(void)
{
    Cd c1("Beatled", "Capital", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", 
                            "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;

    cout << "适用对象：\n";
    c1.Report();          //使用Cd
    c2.Report();         //使用classic

    cout << "使用Cd * 指针对象：\n";
    pcd->Report();      //Cd方法
    pcd = &c2;
    pcd->Report();       //classic方法

    cout << "使用传递Cd引用的函数：\n";
    Bravo(c1);
    Bravo(c2);

    cout << "测试赋值运算符：\n";
    Classic copy;
    copy = c2;
    copy.Report();
    
    return 0;
}