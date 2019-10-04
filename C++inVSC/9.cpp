/****************************第九章******************/
/*1*/
//main.cpp
//与golf.cpp一起运行
// #include<iostream>
// #include"golf.h"

// int main(void)
// {
//     golf gf[10];
//     int i;
//     for ( i = 0; i < 10; i++)
//     {
//         if (setgolf(gf[i]) == 0)
//             break;
//     }
//     for (int j = 0; j < i; j++)
//     {
//         showgolf(gf[j]);
//     }
    
//     golf ann;
//     setgolf(ann, "Ann Birdfree", 24);
//     showgolf(ann);

//     handicap(ann, 4);
//     showgolf(ann);
    
//     system("pause");
//     return 0;
// }
/*2*/
//#include<iostream>
// #include<string>
// const int AiSize = 10;

// void strcount(const std::string str){
//     //本地静态变量
//     static int total = 0;
//     int count  = 0;
//     std::cout << "\"" << str << "\" 包含";
//     count = str.size();                    //计算字符串中的元素个数
//     total += count;
//     std::cout << count << "个字符。\n";
//     std::cout << total << "个字符总共。\n";
// }

// int main(void)
// {
//     std::string input;
    
//     std::cout << "输入一行：\n";
//     getline(std::cin, input);
//     while (input != "")
//     {
//         strcount(input);
//         std::cout << "再次输入一行（空行退出）：\n";
//         getline(std::cin, input);
//     }
    
//     system("pause");
//     return 0;
// }
/*3*/
// #include<iostream>
// #include<cstring>
// #include<new>

// struct chaff
// {
//     char dross[20];
//     int slag;
// };


// int main(void)
// {
//     chaff * p = new chaff[2];
//     strcpy(p[0].dross, "piffa like");
//     p[0].slag = 5;
//     strcpy(p[1].dross, "an example");
//     p[1].slag = 10;

//     for (int i = 0; i < 2; i++)
//     {
//         std::cout << p[i].dross << " " << p[i].slag << std::endl;
//     }
    
//     system("pause");
//     return 0;
// }
/*4*/
// #include<iostream>
// #include "sales.h"

// int main(void)
// {
//     using namespace SALES;

//     Sales s1, s2;

//     setSales(s1);

//     double ar[3] =  {3.1,3.2,4.5};
//     setSales(s2, ar, 3);

//     showSales(s1);
//     showSales(s2);
    
//     system("pause");
//     return 0;
// }