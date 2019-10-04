#include "person.h"
#include<cstring>
#include<iostream>

//Person::Person() {lname = "", fname[0] = '\0';}
Person::Person(const std::string & ln, const char * fn = "Heyyou"){
    lname = ln;
    strcpy(fname, fn);
}
void Person::Show() const{                              //firstname, lastname格式
    std::cout << "first-last全名为：" << fname << " " << lname << std::endl;
}
void Person::FormalShow() const{                       //lastname, firstname格式
    std::cout << "last-first全名为：" << lname << " " << fname << std::endl;
}