#include "stonewt.h"
#include<iostream>

//私有方法
void Stonewt::set_stn(){
    stone = int(pounds) / Lbs_per_stn;
    pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);
}

void Stonewt::set_pds(){
    pounds = stone * Lbs_per_stn + pds_left;
}

void Stonewt::set_pds_int(){
    pounds_int = int(pounds);
 }

//公有方法
Stonewt::Stonewt(double lbs, Mode form){
    mode = form;
    if (form == STN)
    {
        stone = int(lbs) / Lbs_per_stn;
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        set_pds();
        set_pds_int();
    }
    else if (form == INTPD)
    {
        pounds_int = int(lbs);
        pounds = lbs;
        set_stn();
    }
    else if (form == FLOPD)
    {
        pounds = lbs;
        set_pds_int();
        set_stn();
    }
    else
    {
        std::cout << "Stonewt() 对象的第三个参数出错 --Stonewt设置为0。\n";
        stone = pounds_int = pounds = 0;
        mode = STN;
    }
    
}

Stonewt::Stonewt(int stn, double lbs, Mode form){
    mode = form;
    if (form == STN)
    {
        stone = stn;
        pds_left = lbs;
        set_pds();
        set_pds_int();
    }
    else if (form == INTPD)
    {
        pounds_int = int(stn * Lbs_per_stn);
        pounds = stn * Lbs_per_stn;
        set_stn();
    }
    else if (form == FLOPD)
    {
        pounds = stn * Lbs_per_stn + lbs;
        set_pds_int();
        set_stn();
    }
    else
    {
        std::cout << "Stonewt() 对象的第三个参数出错 --Stonewt设置为0。\n";
        stone = pounds_int = pounds = 0;
        mode = STN;
    }
    
}

Stonewt::Stonewt(){
    stone = pounds = pounds_int = 0;
    mode = STN;
}

Stonewt::~Stonewt(){

}

void Stonewt::stn_mode(){
    mode = STN;
}

void Stonewt::pds_mode(){
    mode = FLOPD;
}

void Stonewt::int_pds_mode(){
    mode = INTPD;
}

Stonewt::operator int() const{
    return int(pounds + 0.5);
}

Stonewt::operator double() const{
    return pounds;
}

Stonewt Stonewt::operator+(const Stonewt & st) const{
    return Stonewt(pounds + st.pounds, st.mode);
}

Stonewt Stonewt::operator-(const Stonewt & st) const{
    return Stonewt(pounds - st.pounds, st.mode);
}

Stonewt Stonewt::operator*(double n) const{
    return Stonewt(pounds * n, mode);
}

//友元函数
Stonewt operator*(double n, Stonewt & st){
    return Stonewt(n * st.pounds, st.mode);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st){
    if (st.mode == Stonewt::STN)
    {
        os << st.stone << "stone," << st.pds_left << "pounds.\n";
    }
    else if (st.mode == Stonewt::INTPD)
    {
        os << st.pounds_int << "pounds(int).\n";
    }
    else if (st.mode == Stonewt::FLOPD)
    {
        os << st.pounds << "pounds(double).\n";
    }
    else
    {
        os << "类型错误！\n";
    }
    
    return os;
}