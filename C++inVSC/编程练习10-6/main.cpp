#include "move.h"
#include<iostream>

int main(void)
{
    Move m1;
    m1.showmove();
    
    Move m2(23.4, 22);
    m2.showmove();

    Move m3(21.3, 24.5);
    m3.showmove();

    m3.add(m2);
    m3.showmove();
    m3.reset(11, 12);
    m3.showmove();

    system("pause");
    return 0;
}