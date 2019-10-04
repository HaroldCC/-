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

    std::cout << "����Ŀ����루q�˳�����";
    std::cin >> target;
    std::cout << "���벽����";
    std::cin >> dstep;
    std::cout << "�����������";
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
        std::cout << "����" << steps << "�󣬲�������λ�ý��:\n";
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
    std::cout << "���Ϊ��" << Max << std::endl;
    std::cout << "��С��Ϊ��" << Min << std::endl;
    std::cout << "ƽ������Ϊ�� " << Average << std::endl;
    std::cout << "������\n";

    std::cin.clear(); while (std::cin.get() != '\n') continue;
    
    system("pause");
    return 0;
}