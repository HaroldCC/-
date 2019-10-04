#include "vector.h"
#include<iostream>
#include<fstream>
#include<ctime>

int main(void)
{
    using namespace std;
    using VECTOR::Vector;
    
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    ofstream fout;
    fout.open("walk.txt");

    cout << "输入目标距离（q退出）：";
    while (cin >> target)
    {
        cout << "输入步长：";
        if (!(cin >> dstep))
            break;
        
        //将结果写入文件
        fout << "目标距离：" << target << ",";
        fout << "步长：" << dstep << endl;

        while (result.magval() < target)
        {
            fout << steps << ":" << result << endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "经过" << steps << "后，产生以下位置结果:\n";
        cout << result << endl;

        fout << "经过" << steps << "步后，产生以下位置结果:\n";
        fout << result << endl;

        result.polar_mode();
        cout << "或者为：\n";
        cout << result << endl;
        cout << "每一步经过的平均距离为 = ";
        cout << result.magval() / steps << endl;

        fout << "或者为：\n";
        fout << result << endl;
        fout << "每一步经过的平均距离为 = ";
        fout << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "输入目标距离（q退出）：";
    }
    cout << "Bye!\n";
    
    system("pause");
    return 0;
}