#include"golf.h"
#include<cstring>
#include<iostream>

//非交互版本
void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}

//交互版本
int setgolf(golf & g){
    std::cout << "输入完整的名字：" ;
    std::cin.getline(g.fullname, Len);
    if (g.fullname[0] == '\0')
    {
        return 0;
    }
    std::cout << "输入" << g.fullname<< "的handicap：";
    while (!(std::cin >> g.handicap))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
        {
            continue;
        }
        std::cout << "请输入一个整数。\n";
    }
    std::cin.get();
    return 1;
}

void handicap(golf & g, int hc){
    g.handicap = hc;
}

void showgolf(const golf & g){
    std::cout << "fullname:" << g.fullname << std::endl;
    std::cout << "handicap:" << g.handicap << std::endl;
}
