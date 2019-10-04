#include "mytime.h"
#include<iostream>

int main(void)
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    std::cout << "#1\n";
    std::cout << "aida:" << aida << std::endl;
    std::cout << "tosca:" << tosca << std::endl;
    std::cout << "temp:" << temp << std::endl;

    std::cout << "#2\n";
    temp = aida + tosca;
    std::cout << "aida + tosca:" << temp << std::endl;
    temp = aida * 1.17;
    std::cout << "aica * 1.17:" << temp << std::endl;
    temp = 10 * tosca;
    std::cout << "10 * tosca" << temp << std::endl;
    
    system("pause");
    return 0;
}