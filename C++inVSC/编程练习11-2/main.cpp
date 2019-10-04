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
    std::cout << "输入目标距离（q退出）：";
    while (std::cin >> target)
    {
        std::cout << "输入步长：";
        if (!(std::cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        std::cout << "经过" <<  steps << "步后，产生以下位置结果：\n";
        std::cout << result <<std::endl;
        result.polar_mode();
        std::cout << "或者为：\n";
        std::cout << result << std::endl;

        std::cout << "每一步经过的平均距离 = " << result.magval() / steps <<std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "输入目标距离（q退出）：";
    }
    std::cout<< "Bye!\n";// std::cin.clear(); while (std::cin.get() != '\n') continue; std::cin.get();
    
    system("pause");
    return 0;
}