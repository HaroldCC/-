#include "plorg.h"
#include<iostream>
#include<cstring>

Plorg::Plorg(){
    strcpy(name, "Plorga");
    CI = 0;
}

Plorg::Plorg(const char * n, int ci){
    strcpy(name, n);
    CI = ci;
}

void Plorg::resetCI(int ci){
    CI = ci;
}

void Plorg::showPlorg() const{
    std::cout << "plorg's name:" << name << std::endl;
    std::cout << "CI:" << CI << std::endl;
}

Plorg::~Plorg(){

}