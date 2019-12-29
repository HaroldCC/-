#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
    private:
        long arrive;
        int processtime;
    public:
        Customer() : arrive(0), processtime(0) {}
        void set(long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};

#include<cstdlib>              // for rand()
inline void Customer::set(long when)
{
    processtime = std::rand() %3 +1;
    arrive = when;
}

typedef Customer Item;

#endif