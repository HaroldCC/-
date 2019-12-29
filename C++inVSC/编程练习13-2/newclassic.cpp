#include "classic.h"
#include <iostream>
#include <cstring>

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[std::strlen(s1) + 1];
    std::strcpy(performers, s1);
    label = new char[std::strlen(s2) + 1];
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[std::strlen("none" + 1)];
    std::strcpy(performers, "none"); 
    label = new char(std::strlen("none") + 1);
    std::strcpy(label, "none");
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    std::cout << "Performers:" << performers << std::endl;
    std::cout << "Label:" << label << std::endl;
    std::cout << "Selections:" << selections << std::endl;
    std::cout << "Playtime:" << playtime << std::endl; 
}

Cd & Cd::operator= (const Cd & d)
{
    if (this == & d )
    {
        return *this;
    }
    delete [] performers;
    delete [] label;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}





Classic::Classic(const char * ptr, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    str = new char[std::strlen(ptr) + 1];
    std::strcpy(str, ptr);
}

Classic::Classic(const Classic & cl) : Cd(cl)
{
    str = new char[std::strlen(cl.str) + 1];
    std::strcpy(str, cl.str);
}

Classic::Classic() : Cd()
{
    str = new char[std::strlen("none") + 1];
    std::strcpy(str, "none");
}

Classic::~Classic()
{
    delete [] str;
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Str:" << str << std::endl;
}

Classic & Classic::operator= (const Classic & cl)
{
    if (this == & cl)
    {
        return *this;
    }
    Cd::operator=(cl);
    delete [] str;
    str = new char[std::strlen(cl.str) + 1];
    std::strcpy(str, cl.str);
    return *this;
}