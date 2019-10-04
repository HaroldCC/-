#include "sales.h"
#include<iostream>

namespace SALES
{
Sales::Sales(){
    for (int i = 0; i < QUARTERS; i++)
    {
        sales[i] = 0.0;
    }

    average = 0.0;
    max = 0.0;
    min = 0.0;
}

Sales::Sales(const double ar[], int n){
    //对sales[]赋值
    for (int i = 0; i < QUARTERS; i++)
    {
        if (i <= n)
        {
            sales[i] = ar[i];
        }
        else
        {
            sales[i] = 0.0;
        }
    }

    //计算average,max, min
    double sum = 0.0;
    max = min = sales[0];
    int i;
    for ( i = 0; i < QUARTERS; i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
        }
        if (sales[i] < min)
        {
            min = sales[i];
        }
        sum += sales[i];
    }
    
    average = sum / i;
}

void Sales::setSales(){
    std::cout << "输入sales:" << std::endl;
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout << "sales[" << i << "]:";
        std::cin >> sales[i];
    }
     
    //计算average, max, min
    double sum = 0.0;
    max = min = sales[0];
    int i;
    for (i = 0; i < QUARTERS; i++)
    {
        if (sales[i] > max)
            max = sales[i];
        if (sales[i] < min)
            min = sales[i];
        sum += sales[i];
    }
    
    average = sum / i;
}

void Sales::showSales(){
    using std::cout;
    using std::endl;

    //show sales[i]
    for (int i = 0; i < QUARTERS; i++)
    {
        cout << "sales[" << i << "]:" << sales[i] << endl;;
    }
    cout << endl;

    //show average
    cout << "average:" << average << endl;

    //show max min
    cout << "max:" << max << endl;
    cout << "min:" << min << endl;
}

Sales::~Sales(){

}

}