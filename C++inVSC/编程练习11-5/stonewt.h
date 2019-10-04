#ifndef STONEWT_H_
#define STONEWT_H_
#include<iostream>

class Stonewt
{
public:
    enum Mode{STN, INTPD, FLOPD};       //英石格式，整数磅格式，浮点磅格式
private:
    enum{Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    int pounds_int;
    Mode mode;

    void set_stn();
    void set_pds();
    void set_pds_int();
public:
    Stonewt(double lbs, Mode form);
    Stonewt(int stn, double lbs, Mode form);
    Stonewt();
    ~Stonewt();
    void stn_mode();
    void pds_mode();
    void int_pds_mode();

    //int转换将转换的值四舍五入，而不是去掉小数部分
    operator int() const;
    operator double() const;

    Stonewt operator+(const Stonewt & st) const;
    Stonewt operator-(const Stonewt & st) const;
    Stonewt operator*(double n) const;

    friend Stonewt operator*(double n, Stonewt & st);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};

#endif