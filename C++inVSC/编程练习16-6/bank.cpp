#include "queue.h"
#include<iostream>
#include<queue>
#include<cstdlib>                      //for rand() and scrand()
#include<ctime>                        // for time()

const int MIN_PRE_HR = 60;

// x =客户之间的平均时间（以分钟为单位） 
// 如果客户在这一分钟出现，则返回值为true
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;

    std::srand(std::time(0));
    
    cout << "案例研究：希瑟银行自动柜员机\n";
    cout << "输入队列的最大大小：";
    int qs;
    cin >> qs;
    queue<Item> line;

    cout << "输入模拟小时数：";
    int hours;
    cin >> hours;

    // 仿真将每分钟运行1个周期
    long cyclelimit = MIN_PRE_HR * hours;

    cout <<  "输入每小时的平均客户数：";
    double perhour;               // 每小时平均到达次数
    cin >> perhour;
    double min_per_cust;            // 平均到达时间
    min_per_cust = MIN_PRE_HR / perhour;

    Item temp;            // 新客户数据
    long turnaways = 0;    //被完整队列拒之门外
    long customers = 0;     // 加入队列
    long served = 0;      
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    // 开始模拟
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))                   // 新客户
        {
            if (line.size() == qs)
                turnaways++;
            else 
                {
                    customers++;
                    temp.set(cycle);     // 周期=到达时间
                    line.push(temp);        //添加新人
                }
        }
        if (wait_time <= 0 && !line.empty())
        {
            line.pop();
            wait_time = temp.ptime();          //等待wait_time分钟
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }


    // 显示结果
    if (customers > 0)
    {
        cout << "customers accepted: " << customers <<endl;
        cout <<     "customers served: " << served << endl;
        cout << "           turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait tiem: " 
             << (double) line_wait / served << " minutes\n";
    }
    else    
        cout << "No customers!\n";

    cout << "Done!\n";
    
    return 0;
}