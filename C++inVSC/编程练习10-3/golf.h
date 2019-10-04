#ifndef GOLF_H_
#define GOLF_H_
#include<iostream>

//声明golf类
class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf();
    Golf(const char * name, const int hc);
    const Golf & setgolf(const Golf & g);
    void showgolf() const;
    ~Golf();
};

#endif