#include<iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n){
        int i;
        for ( i = 0; i < n && i < QUARTERS; i++)            //赋值
        {
            s.sales[i] = ar[i];
        }
        for (int j = i; j < QUARTERS; j++)                //将未复制的设置为0
        {
            s.sales[j] = 0;
        }
        
        double total = 0;
        for (int j = 0; j < i; j++)                  //total为所有有效值的总和
        {
            total += s.sales[j];
        }
        
        s.average = total / i;     //平均值

        s.max = s.min = s.sales[0];                //最大最小值初始化为第一个元素

        for (int j = 0; j < i; j++)           //设置最大最小值
        {
            if (s.sales[j] > s.max)
            {
                s.max = s.sales[j];
            }
            if (s.sales[j] < s.min)
            {
                s.min = s.sales[j];
            }
        }
        
    }

    void setSales(Sales & s){
        std::cout << "输入sales:" << std::endl;
        int i;
        for (i = 0; i < QUARTERS; i++)
        {
            std::cout << "sales[" << i << "]:";
            std::cin >> s.sales[i];
        }
        
        //计算平均值，最大值和最小值
        double total = 0;
        for (int j = 0; j < i; j++)
        {
            total += s.sales[j];
        }
        s.average = total / i;
        s.max = s.min = s.sales[0];
        for (int j = 0; j < i; j++)
        {
            if (s.sales[j] > s.max)
            {
                s.max = s.sales[j];
            }
            if (s.sales[j] < s.min)
            { 
                s.min = s.sales[j];
            }
            
        }
        
    }

    void showSales(const Sales & s){
        std::cout << "sales:";
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << s.sales[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "average:" << s.average << std::endl;
        std::cout << "max：" << s.max << std::endl;
        std::cout << "min:" << s.min << std::endl;
    }
}