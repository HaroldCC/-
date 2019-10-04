#include "sales.h"
#include<iostream>

int main(void)
{
    using SALES::Sales;

    double salesList[4] = {11.2,13.4,14.5,20.0};

    Sales salesBook(salesList, 4);
    salesBook.showSales();

    Sales salesPen;
    salesPen.setSales();
    salesPen.showSales();
    
    system("pause");
    return 0;
}