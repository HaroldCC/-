#include "vector.h"
#include<ctime>
#include<iostream>

int main(void)
{
    using VECTOR::Vector;
    srand(time(0));

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    double numbers, N, Min, Max, Sum, Average;

    std::cout << "输入目标距离（q退出）：";
    std::cin >> target;
    std::cout << "输入步长：";
    std::cin >> dstep;
    std::cout << "输入测试数：";
    std::cin >> numbers;
    N = numbers;
    Min = Max = Sum = Average = 0.0;
    while (numbers)
    {
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        std::cout << "经过" << steps << "后，产生以下位置结果:\n";
        if (Min == 0 || Max == 0)
        {
            Min = Max = steps;
        }
        if (Min > steps)
        {
            Min = steps;
        }
        if (Max < steps)
        {
            Max = steps;
        }
        Sum += steps;
        numbers--;
        steps = 0;
        result.reset(0.0, 0.0);
    }
    Average = Sum / N;
    std::cout << "最大步为：" << Max << std::endl;
    std::cout << "最小步为：" << Min << std::endl;
    std::cout << "平均步数为： " << Average << std::endl;
    std::cout << "结束！\n";

    std::cin.clear(); while (std::cin.get() != '\n') continue;
    
    system("pause");
    return 0;
}