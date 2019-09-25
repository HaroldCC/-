/*****************************第八章****************************************/
/*1*/
// #include<iostream>
// #include<string>
// using namespace std;

// void show_str(const string str_name, int n = 1){
//     cout << str_name << endl;
// }
// int main(void)
// {
//     string message = "I am a string!";

//     show_str(message, 2);
    
//     system("pause");
//     return 0;
// }
/*2*/
// #include<iostream>
// #include<cstring>
// using namespace std;

// struct CandyBar
// {
//     char brandName[20];         //品牌名称
//     double weight;
//     int heat;
// };

// //结构赋值函数声明
// void set_CandyBar_value(CandyBar & cb, const char * pBrandName = "Millennium Munch", const double weight = 2.85, const int heat = 350){
//     strcpy(cb.brandName, pBrandName);
//     cb.weight = weight;
//     cb.heat = heat;
// } 

// void show_CandyBar(const CandyBar & cb){
//     cout << "品牌名称：" << cb.brandName << endl;
//     cout << "重量：" << cb.weight << endl;
//     cout << "热量：" << cb.heat << endl;
// }

// int main(void)
// {
//     CandyBar cb;

//     cout << "原内容：" << endl;
//     set_CandyBar_value(cb);
//     show_CandyBar(cb);

//     cout << "修改后：\n";
//     char pBrandName[10] = "munch";
//     double weight = 5.91;
//     int heat = 698;
//     set_CandyBar_value(cb, pBrandName, weight, heat);
//     show_CandyBar(cb);
    
//     system("pause");
//     return 0;
// }
/*3*/
// #include<iostream>
// #include<cstring>
// using namespace std;

// //小写字符串转大写
// void str_to_STR(string & str){
//     for (int i = 0; i < str.size(); i++)
//     {
//         //挨个判断字符串中每个是否为字母，然后将其转换为大写
//         if (isalpha(str[i]))
//         {
//             str[i] = toupper(str[i]);
//         }
//     }
    
// }

// int main(void)
// {
//     string str;
//     cout << "输入一串字符串进行转换（q退出）：";
//     getline(cin, str);
//     while (str != "q")
//     {
//          str_to_STR(str);
//         cout << str << endl;
//         cout << "输入一串字符串进行转换（q退出）：";
//         getline(cin, str);
//     }
    
//     system("pause");
//     return 0;
// }
/*4*/
// #include<iostream>
// #include<cstring>
// using namespace std;

// struct stringy
// {
//     char * str;           //指向一个字符串的指针
//     int ct;              //字符串的长度（不包含'\0'）
// };

// void set(stringy & reBeany, char * pTesting){
//     reBeany.ct = strlen(pTesting);
//     reBeany.str = new char [reBeany.ct];
//     strcpy(reBeany.str, pTesting);
// }

// void show(const stringy & reBeany, int n = 1){
//     while (n-- > 0)
//     {
//         cout << reBeany.str << endl;
//     }
    
// }

// void show(const char * pTesting, int n = 1){
//     while (n-- > 0)
//     {
//         cout << pTesting << endl;
//     }
    
// }

// int main(void)
// {
//     stringy beany;
//     char testing[] = "Reality isn't what it used to be.";

//     set(beany, testing);
//     show(beany);
//     show(beany, 2);
//     testing[0] = 'D';
//     testing[1] = 'u';
//     show(testing);
//     show(testing, 3);
    
//     system("pause");
//     return 0;
// }
/*5*/
// #include<iostream>
// using namespace std;

// //创建模板函数
// template <typename T>
// T max5(T * arr){
//     T max = arr[0];
//     for (int i = 0; i < 5; i++)
//     {
//          if (arr[i] > max)
//          {
//              max = arr[i];
//          }
//     }
//     return max;
// }

// int main(void)
// {
//     int array_int[5] = {1,2,3,4,5};
//     double array_double[5] = {1.1,2.2,3.3,4.4,5.5};
//     std::cout << "max int = " << max5(array_int) << std::endl;
//     std::cout << "max double = " << max5(array_double) << std::endl;
    
//     system("pause");
//     return 0;
// }
/*6*/
// #include<iostream>
// #include<cstring>

// //模板函数声明
// template <typename T>
// T maxn(T * arr, const int n){
//     T max = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// //具体化声明
// template <> char * maxn <char *>(char * arr[], const int n){
//     char * temp = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if((strlen(arr[i])) > (strlen(temp)))
//         {
//             temp = arr[i];
//         }
//     }
//     return temp;
// }

// int main(void)
// {
//     int array1[6] = {1,2,3,4,5,6};
//     double array2[4] = {1.1,2.2,3.3,4.4,};
//     //调用模板函数
//     int max1 = maxn(array1,6);
//     double max2 = maxn(array2,4);
//     std::cout << "max int = " << max1 << std::endl;
//     std::cout << "max double = " << max2 << std::endl;

//     char * array_str[5] = {"st","str","stri","strin","string"};
//     //具体化调用
//     char * max_str;
//     max_str = maxn(array_str,5);
//     std::cout << "max string = " << max_str << std::endl;
    
//     system("pause");
//     return 0;
// }
/*7*/
#include<iostream>

//模板函数，接受数组名和数组大小两个参数，返回数组的和
template <typename T>
T SumArray(T arr[], int n){
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T * arr[], int n){
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *arr[i];
    }
    return sum;
}

struct debts
{
    char name[50];
    double amount;
};


int main(void)
{
    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
     double * pd[3];

     for (int i = 0; i < 3; i++)
     {
         pd[i] = &mr_E[i].amount;
     }
     
     std::cout << "sum int = " << SumArray(things, 6) << std::endl;

     std::cout << "sum double = " << SumArray(pd, 3) << std::endl;
    
    system("pause");
    return 0;
}