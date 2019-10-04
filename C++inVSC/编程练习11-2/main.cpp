#include "vector.h"
#include<ctime>

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
    std::cout << "����Ŀ����루q�˳�����";
    while (std::cin >> target)
    {
        std::cout << "���벽����";
        if (!(std::cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        std::cout << "����" <<  steps << "���󣬲�������λ�ý����\n";
        std::cout << result <<std::endl;
        result.polar_mode();
        std::cout << "����Ϊ��\n";
        std::cout << result << std::endl;

        std::cout << "ÿһ��������ƽ������ = " << result.magval() / steps <<std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "����Ŀ����루q�˳�����";
    }
    std::cout<< "Bye!\n";// std::cin.clear(); while (std::cin.get() != '\n') continue; std::cin.get();
    
    system("pause");
    return 0;
}