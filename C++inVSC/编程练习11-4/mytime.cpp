#include "mytime.h"
#include<iostream>

Time::Time(){
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::AddMin(int m){
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h){
    hours += h;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time::~Time(){

}

Time Time::operator*(double n) const{
    Time result;
    long totalMinutes = hours * n * 60 + minutes * n;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

Time operator+(const Time & t1, const Time & t2){
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time & t1, const Time & t2){
    Time diff;
    int total1, total2;
    total1 = t1.minutes + 60 * t1.hours;
    total2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (total1 - total2) % 60;
    diff.hours = (total1 - total2) / 60;
    return diff;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os << t.hours << "Ð¡Ê±£¬" << t.minutes << "·ÖÖÓ";
    return os;
}