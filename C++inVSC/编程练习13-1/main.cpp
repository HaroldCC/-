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

    cout << "���ö���\n";
    c1.Report();          //ʹ��Cd
    c2.Report();         //ʹ��classic

    cout << "ʹ��Cd * ָ�����\n";
    pcd->Report();      //Cd����
    pcd = &c2;
    pcd->Report();       //classic����

    cout << "ʹ�ô���Cd���õĺ�����\n";
    Bravo(c1);
    Bravo(c2);

    cout << "���Ը�ֵ�������\n";
    Classic copy;
    copy = c2;
    copy.Report();
    
    return 0;
}