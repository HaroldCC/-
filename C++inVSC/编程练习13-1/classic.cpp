#include "classic.h"
#include <iostream>
#include <cstring>

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    std::strncpy(performers, s1, 49);
    performers[49] = '\0';
    std::strncpy(label, s2, 19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    std::strcpy(performers, "none");
    std::strcpy(label, "none");
    selections = 0;
    playtime = 0;
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
    if (this == & d)
    {
        return *this;
    }
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}





Classic::Classic(const char * ptr, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    std::strncpy(str, ptr, 49);
    str[49] = '\0';
}

Classic::Classic(const Classic & cl) : Cd(cl)
{
    std::strcpy(str, cl.str);
}

Classic::Classic() : Cd()
{
    std::strcpy(str, "none");
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
    std::strcpy(str, cl.str);
    return *this;
}