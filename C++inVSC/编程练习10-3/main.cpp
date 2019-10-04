#include<iostream>
#include "golf.h"        //这里的golf.h版本是“编程练习10-3中的版本”

int main(void)
{
    Golf g1 ("zhangsan", 20);
    g1.showgolf();

    Golf g2;
    g2.showgolf();
    g2.setgolf(g1);
    g2.showgolf();
    
    system("pause");
    return 0;
}