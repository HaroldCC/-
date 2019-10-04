#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>


class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person() {lname = "", fname[0] = '\0';}
    Person(const std::string & ln, const char * fn = "Heyyou");
    void Show() const;                               //firstname, lastname格式
    void FormalShow() const;                       //lastname, firstname格式
    //~Person();
};

#endif