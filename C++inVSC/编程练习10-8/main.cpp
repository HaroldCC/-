#include "list.h"
#include<iostream>

void show_items(Item & item){
    std::cout << "列表中的数据有：" << std::endl;
    std::cout << item << std::endl;
}

int main(void)
{
    List lis;
    std::string str;
    std::cout << "#1" << std::endl;
    if (lis.isempty())
    {
        std::cout << "列表为空！" << std::endl;
    }
    if (lis.isfull())
    {
        std::cout << "列表已满！" << std::endl;
    }
    
    lis.additem(1);
    lis.additem(2);
    lis.additem(3);
    lis.additem(4);
    lis.additem(5);
    lis.additem(6);
    if (lis.isempty())
    {
        std::cout << "列表为空！" << std::endl;
    }
    if (lis.isfull())
    {
        std::cout << "列表已满！" << std::endl;
    }
    else
    {
        std::cout << "列表中已含有" << lis.itemcount() << "个数据！" << std::endl;
    }
    
    lis.additem(7);
    lis.additem(8);
    lis.additem(9);
    lis.additem(10);
    lis.additem(11);
    if (lis.isempty())
    {
        std::cout << "列表为空！" << std::endl;
    }
    if (lis.isfull())
    {
        std::cout << "列表已满！" << std::endl;
    }
    else
    {
        std::cout << "列表中已含有" << lis.itemcount() << "个数据！" << std::endl;
    }


    lis.visit(show_items);

    system("pause");
    return 0;
}