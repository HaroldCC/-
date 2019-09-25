// //函数按值传递
// //  * 按值传递到函数传递的是原始数据的副本，并不能通过函数调用来修改数据
// // 例：输入一个平面直角坐标系坐标，转换为极坐标
// #include<iostream>
// #include<cmath>

// //创建直角坐标系结构
// struct rect
// {
//     double x;
//     double y;
// };

// //创建极坐标系结构
// struct polar
// {
//     double distance;
//     double angle;
// };

// //直角坐标转换为极坐标函数声明:函数的返回值类型是一个极坐标系结构,参数是一个直角坐标系结构
// polar rect_to_polar(rect xypos){
//     polar answer;

//     answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
//     //函数atan2()可以根据x和y的值计算角度
//     answer.angle = atan2(xypos.y, xypos.x);

//     return answer;    //返回结构
// }

// //显示极坐标函数声明：函数无返回值，参数是一个极坐标系坐标
// void show_polar(polar dapos){
//     // 数学库中角度的单位为弧度，为将弧度值转换为角度值，
//     //要将弧度值乘以 180/∏ 结果约为57.29577951
//     const double Rad_to_deg = 57.29577951;

//     std::cout << "距离 = " << dapos.distance;
//     std::cout << "，角度 = " << dapos.angle * Rad_to_deg;
//     std::cout << "度\n";
// }

// int main(void)
// {
//     rect rplace;
//     polar pplace;

//     std::cout << "输入坐标x和y：";
//     while (std::cin >> rplace.x >> rplace.y)
//     {
//         pplace = rect_to_polar(rplace);
//         show_polar(pplace);
//         std::cout << "输入下一组坐标(q退出)：";
//     }
    
    
//     system("pause");
//     return 0;
// }


//按地址传递
#include<iostream>
#include<cmath>

//创建直角坐标系结构
struct rect
{
    double x;
    double y;
};

//创建极坐标系结构
struct polar
{
    double distance;
    double angle;
};

//直角坐标转换为极坐标函数声明：参数为直角坐标与极坐标的地址
//因为函数接收rect结构的指针，但不修改rect，
//而极坐标指针将会直接修改值
void rect_to_polar(const rect * pxy, polar * pda){
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}

//显示极坐标函数证明
void show_polar(const polar * pda){
    const double Rad_to_deg = 57.29577951;

    std::cout << "距离 = " << pda->distance;
    std::cout << "，角度 = " << pda->angle * Rad_to_deg;
    std::cout << "度\n";
}

int main(void)
{
    rect rplace;
    polar pplace;

    std::cout << "输入x，y坐标：" ;
    while (std::cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        std::cout << "输入下一组坐标(q退出)：";
    }
    
    
    system("pause");
    return 0;
}