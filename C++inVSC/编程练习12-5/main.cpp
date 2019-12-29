#include "queue.h"
#include <iostream>
#include <ctime>   //for time()
#include <cstdlib> //for rand() and srand()

const int MIN_PER_HR = 60;

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

    std::srand(std::time(0));

    cout << "����������Heather�Զ���Ա������\n";
    cout << "�����������С��";
    int qs;
    cin >> qs;
    Queue line1(qs); //line �������� qs ����

    Queue line2(qs);

    // ֱ�ӽ�����ʱ������Ϊ100����
    cout << "Simulation hours: 100" << endl;
    int hours = 100;

    long cyclelimit = MIN_PER_HR * hours;

    Item temp;          //�¹˿�����
    long turnaways = 0; //������������ܾ��ĸ���
    long customers = 0; //�������
    long served = 0;    //ģ���ڼ䵣��
    long sum_line = 0;
    int wait_time1 = 0;
    int wait_time2 = 0;
    int line1_size = 0;
    int line2_size = 0;
    long line_wait = 0;
    double avg_wait_time = 0.0;

    // ÿСʱʹ��������ʼֵΪ15��֮�����+1ö�ٲ���
    double perhour = 15;
    double min_per_cust;

    do
    {
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

        // ��Ҫ��ն���
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
            if (wait_time2 <= 0 && !line2.isempty())
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
                 << avg_wait_time << " minutes\n"
                 << endl;
            ;
        }
        else
            cout << "No customers!\n"
                 << endl;
        // ƽ���ȴ�ʱ�䲻һ���պ���1��������һ��������
    } while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));

    cout << "When perhour = " << perhour << " , the average wait time"
                                            " will be about 1 minute\n"
         << endl;

    cout << "Done!\n";

    return 0;
}