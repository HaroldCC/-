#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
    char name[20];
    int CI;
public:
    Plorg();
    Plorg(const char * n, int ci = 50);
    void resetCI(int ci);
    void showPlorg() const;
    ~Plorg();
};

#endif