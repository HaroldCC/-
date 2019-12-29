/*************************************************************************
    > File Name       : main.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-25 15:30:55
 ************************************************************************/
#include<iostream>
#include "queue.h"
#include<ctime>

using namespace std;
const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main(int argc,char *argv[])
{
	std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximun size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);
    Queue line2(qs);

    // 直接将测试时间设置为100好了
    cout << "Simulation hours: 100" << endl;
    int hours = 100;

    long cyclelimit = MIN_PER_HR * hours;

    cItem temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0;
    int wait_time2 = 0;
    int line1_size = 0;
    int line2_size = 0;
    long line_wait = 0;
    double avg_wait_time = 0.0;

    // 每小时使用人数初始值为15，之后进行+1枚举测试
    double perhour = 15;
    double min_per_cust;

    do {
        min_per_cust = MIN_PER_HR / perhour;
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line1_size = 0;
        line2_size = 0;
        line_wait = 0;
        avg_wait_time = 0;

        // 需要清空队列
        while (!line1.isempty())
        {
            line1.dequeue(temp);
        }

        while (!line2.isempty())
        {
            line2.dequeue(temp);
        }

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                {
                    turnaways++;
                }
                else if (line1_size > line2_size)
                {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                    line2_size++;
                } 
                else
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                    line1_size++;
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                line1_size--;
                wait_time1 = temp.ptime();
                line_wait += (cycle - temp.when());
                served++;
            }
            if (wait_time2 <=0 && !line2.isempty())
            {
                line2.dequeue(temp);
                line2_size--;
                wait_time2 = temp.ptime();
                line_wait += (cycle - temp.when());
                served++;
            }
            if (wait_time1 > 0)
            {
                wait_time1--;
            }
            if (wait_time2 > 0)
            {
                wait_time2--;
            }
            sum_line += line1.queuecount();
            sum_line += line2.queuecount();
        }

        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double)sum_line / cyclelimit << endl;
            avg_wait_time = (double)line_wait / served;
            cout << " average wait time: "
                << avg_wait_time << " minutes\n" << endl;;
        }
        else
            cout << "No customers!\n" << endl;
        // 平均等待时间不一定刚好是1，设置在一个区间内
    } while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));

    cout << "When perhour = " << perhour << " , the average wait time"
        " will be about 1 minute\n" << endl;

    cout << "Done!\n";
    return 0;
}

