// /////////////////////第七章/////////////
// /*1*/
// #include<iostream>

// //求调和平均数
// double SumAvg(double a, double b)
// {
//     double avg = 0;

//     avg = 2.0 * a * b / (a + b);

//     return avg;
// }

// int main(void)
// {
//     using namespace std;

//     cout << "输入两个数，求它们的调和平均数！\n";
//     cout << "输入第一个数：";
//     double a;
//     cin >> a;
//     cout << "输入第二个数：";
//     double b;
//     cin >> b;

//     //函数调用
//     //声明一个数来接收函数返回的值
//     double sumAvg = SumAvg(a, b);

//     cout << "调和平均数为：" << sumAvg <<endl;
//     system("pause");
//     return 0;
// }
/*2*/
// #include<iostream>

// //数组赋值
// int InputArray(double* array){
//     std::cout << "输入多个高尔夫成绩：\n";
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         double score;
//         std::cin >> score;
//         array[i] = score;
//         if(std::cin.get() == '\n')
//             break;
//     }
//     return i+1;
// }

// //计算平均成绩
// double GradeAvg(double* array, int size){
//     double sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += array[i];
//     }
    
//     double avg = 0;
//     avg = sum / size;
//     return avg;
// }

// //显示结果
// void ShowGrade(double* array, int size, double avg){
//     std::cout << "成绩为：";
//     for (int i = 0; i < size; i++)
//     {
//         std::cout << array[i] << " ";
//     }
    
//     std::cout << std::endl;
//     std::cout << "平均成绩为：" << avg << std::endl;
// }

// int main(void)
// {
//     double array[10] = {0.0};
    
//     //输入数组元素并返回个数
//     int n = InputArray(array);

//     //计算平均值
//     double avg = GradeAvg(array, n);

//     //输出结果
//     ShowGrade(array, n, avg);
    
//     system("pause");
//     return 0;
// }
/*3*/
// #include<iostream>
// using namespace std;

// //结构声明
// struct box
// {
//     char maker[40];
//     float height;
//     float width;
//     float length;
//     float volume;
// };

// //按值传递box结构函数声明
// void trans_value_show_box(box valuebox){
//     cout << "制造商 : " << valuebox.maker << endl;
//     cout << "高 = " << valuebox.height << endl;
//     cout << "宽 = " << valuebox.width << endl;
//     cout << "长 = " << valuebox.length << endl;
//     cout << "体积 = " << valuebox.volume << endl;
// }

// //按地址传递box结构函数声明
// void trans_pos_box(box* bpos){
//     bpos->volume = bpos->length * bpos->width * bpos->height;
// }

// int main(void)
// {
//     box aBox = {"张三纸箱厂", 5.5, 6.6, 7.7, 0};

//     trans_pos_box(&aBox);
//     trans_value_show_box(aBox);
    
//     system("pause");
//     return 0;
// }
/*4*/
// #include<iostream>

// //中奖概率
// long double probability(unsigned number1, unsigned pick1, unsigned number2, unsigned pick2){
//     long double result = 1.0;
//     unsigned i, p;
//     for (i = number1, p = pick1; p > 0; i--, p--)
//     {
//         result = result * i / p;
//     }

//     for ( i = number2, p = pick2; p > 0; i--, p--)
//     {
//         result = result * i / p;
//     }
//     return result;
// }
// int main(void)
// {
//     using namespace std;

//     double total1, choice1;
//     double total2, choice2;

//     cout << "输入域号码总数和要选择号码的数量:";
//     cin >> total1 >> choice1;
//     cout << "输入特选号码的总数和要选择的数量：";
//     cin >> total2 >> choice2;
//     while (!(cin.fail()) && choice1 <= total1 && choice2 <= total2)
//     {
//         cout << "你获奖的机率为：";
//         cout << probability(total1, choice1, total2, choice2) << endl;
//         cout << "继续输入4组数据进行预测(非数字退出):";
//         cin >> total1 >> choice1;
//         cin >> total2 >> choice2;
//     }
    
//     system("pause");
//     return 0;
// }
/*5*/
// #include<iostream>

// //递归求阶乘
// unsigned long Factorial(int num){
//         unsigned long factorial;
//         if (num > 0)
//         {
//             factorial = num * Factorial(num - 1);
//         }
//         else
//         {
//             factorial = 1;
//         }
        
//         return factorial;
// }

// int main(void)
// {
//     using namespace std;

//     cout << "输入一个正整数，求它的阶乘：";
//     int num;
//     unsigned long factorial;
//     while (cin >> num)
//     {
//         factorial = Factorial(num);
//         cout << num << "! = " << factorial << endl;
//         cout << "输入一个正整数，求它的阶乘：";
//     }
    
//     system("pause");
//     return 0;
// }
// /*6*/
// #include<iostream>

// using namespace std;

// int Fill_array(double *array, int size){
//     int count = 0;
//     cout << "请输入一些数值：";
//     for (int i = 0; i < size; i++)
//     {
//         if (!(cin >> array[i]))                 //处理非法输入
//         {
//             cout << "非数值输入，程序退出！";
//             break;
//         }
//         count++;
//     }
    
//     return count;
// }

// void Show_array(double *array, int size){
//     cout << "数组中存储的数字有：" << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }

// void Reverse_array(double *array, int size){
//     int i = 0, j = size - 1;             //数组的第一个和最后一个下标
//     double temp;                         //中间量

//     while (i < j)
//     {
//         temp = array[i];
//         array[i] = array[j];
//         array[j] = temp;
//         i++;
//         j--;
//     }
    
// }

// int main(void)
// {
//     //填充数组并显示数组
//     double number[10];        //数组声明
//     int real_input_count;      //实际输入元素个数
//     real_input_count = Fill_array(number, 10);
//     Show_array(number, real_input_count);

//     //反转数组然后显示
//     Reverse_array(number, real_input_count);
//     Show_array(number, real_input_count);

//     //反转数组中除第一个和最后一个之外的所有元素，然后显示
//     Reverse_array(number+1, real_input_count-2);
//     Show_array(number, real_input_count);

//     system("pause");
//     return 0;
// }
/*7*/
// #include<iostream>
// using namespace std;
// const int Max = 5;

// double * fill_array(double * pf, double * pl){
//     double temp;
//     double * i;
//     int j = 0;
//     for (i = pf; i < pl; i++, j++)
//     {
//         cout << "输入值#" << j + 1 << ":";
//         cin >> temp;

//         if (!cin)
//         {
//             cin.clear();
//             while (cin.get() != '\n')
//             {
//                 continue;
//             }
//             cout << "非法输入，输入将终止！" << endl;
//             break;
//         }
//         else if (temp < 0)
//             break;
//         *i = temp;
//     }
//     return i;
// }

// void show_array(const double * pf, const double * pl){
//     const double * i;
//     int j = 0;
//     for ( i = pf; i < pl; i++, j++)
//     {
//         cout << "房地产#" << j + 1 << "$:";
//         cout << *i << endl;
//     }
    
// }

// void revalue(double r, double * pf, double * pl){
//     double * i;
//     for ( i = pf; i < pl; i++)
//     {
//         (*i) *= r;
//     }
// }

// int main(void)
// {
//     double properties[Max];

//     double * end = fill_array(properties, properties+Max);
//     show_array(properties, end);

//     if (end > properties)
//     {
//         cout << "输入重估值：";
//         double factor;

//         while (!(cin >> factor))                //处理非法输入
//         {
//             cin.clear();
//             while (cin.get() != '\n')
//             {
//                 continue;
//             }
//             cout << "非法输入，输入将终止！" << endl;
//         }
        
//         revalue(factor, properties, end);
//         show_array(properties, end);
//     }
    
//     system("pause");
//     return 0;
// } 
/*8*/
/*a*/
// #include<iostream>
// #include<string>
// const int Seasons = 4;
// const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

// void fill(double *pa){
//     for (int i = 0; i < Seasons; i++)
//     {
//         std::cout << "输入" << Snames[i] << "的开支：";
//         std::cin >> pa[i];
//     }
// }

// void show(double * da){
//     double total = 0;
//     std::cout << "\n支出\n";
//     for (int i = 0; i < Seasons; i++)
//     {
//         std::cout << Snames[i] << ":$" << da[i] << std::endl;
//         total += da[i];
//     }
//     std::cout << "总支出：$" << total << std::endl;
// }

// int main(void)
// {
//     double expenses[Seasons];
//     fill(expenses);
//     show(expenses);
    
//     system("pause");
//     return 0;
// }
/*b*/
// #include<iostream>
// #include<string>
// const int Seasons = 4;
// const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

// struct expenses
// {
//     double expenses;
// };

// void fill(expenses * pa){
//     for (int i = 0; i < Seasons; i++)
//     {
//         std::cout << "输入" << Snames[i] << "的支出：";
//         std::cin >> pa[i].expenses;
//     }
    
// }

// void show(expenses * da){
//     double total = 0;
//     std::cout << "\n支出\n";
//     for (int i = 0; i < Seasons; i++)
//     {
//         std::cout << Snames[i] << ":$" << da[i].expenses << std::endl;
//         total += da[i].expenses;
//     }
//     std::cout << "总支出：$" << total <<std::endl;
// }

// int main(void)
// {
//     expenses * cost = new expenses[Seasons];

//     fill(cost);
//     show(cost);
    
//     system("pause");
//     return 0;
// }

/*9*/
// #include<iostream>
// using namespace std;
// const int SLEN = 30;

// struct student
// {
//     char fullname[SLEN];
//     char hobby[SLEN];
//     int ooplevel;
// };

// int getinfo(student pa[], int n){
//     int j = 1;                      //学生编号索引
//     int i;
//     for (i = 0; i < n; i++, j++)
//     {
//         cout << "输入学生#" << j << "的全名：";
//         cin.getline(pa[i].fullname, SLEN);
//         if (pa->fullname[0] == ' ')
//         {
//             break;
//         }
//         cout << "输入学生#" << j << "的爱好：";
//         cin.getline(pa[i].hobby, SLEN);
//         cout << "输入学生#" << j << "的ooplevel:";
//         cin >> pa[i].ooplevel;
//         cin.get();                        //清空缓冲区
//     }
//     return i;
// }

// void display1(student st){
//     cout << st.fullname << "的爱好是" << st.hobby;
//     cout << "他的oop水平是" << st.ooplevel << "级。\n";
// }

// void display2(const student * ps){
//     cout << ps->fullname << "的爱好是" << ps->hobby;
//     cout << "他的oop水平是" << ps->ooplevel << "级。\n";
// }

// void display3(const student pa[], int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout << pa[i].fullname << "的爱好是" << pa[i].hobby;
//         cout << "他的oop水平是" << pa[i].ooplevel << "级。\n";
//     }
    
// }

// int main(void)
// {
//     cout << "输入班级人数：";
//     int class_size;
//     cin >> class_size;
//     while (cin.get() != '\n')
//     {
//         continue;
//     }
    
//     student * ptr_stu = new student[class_size];
//     int entered = getinfo(ptr_stu, class_size);
//     for (int i = 0; i < entered; i++)
//     {
//         display1(ptr_stu[i]);
//         display2(&ptr_stu[i]);
//     }
//     display3(ptr_stu, entered);
//     delete [] ptr_stu;
    
//     system("pause");
//     return 0;
// }
/*10*/
#include<iostream>
using namespace std;

double add(double x, double y){
    return x + y;
}

double sub(double x, double y){
    return x - y;
}

double calculate(double x, double y, double cal(double, double)){
    return cal(x, y); 
}

int main(void)
{
    cout << "请输入2个值：";
    double x, y;
    double sum = 0, diff = 0;
    while ((cin >> x) && (cin >> y))
    {
        sum = calculate(x, y, add);
        diff = calculate(x, y, sub);
        cout << "计算的结果为" << sum << "和" << diff << endl;
        cout << "再次输入2个值进行计算（非数字退出）：";
    }
    
    
    system("pause");
    return 0;
}