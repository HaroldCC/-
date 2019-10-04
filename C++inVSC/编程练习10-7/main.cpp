#include"plorg.h"
#include<iostream>

int main(void)
{
    using namespace std;
    
    Plorg p1;
    p1.showPlorg();

    Plorg p2("test");
    p2.showPlorg();

    Plorg p3("test2", 20);
    p3.showPlorg();

    p3.resetCI(10);
    p3.showPlorg();
    
    system("pause");
    return 0;
}