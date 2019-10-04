#include "vector.h"
#include<cmath>

namespace VECTOR
{
    //计算弧度的度数
    const double Rad_to_deg = 45.0 / atan(1.0);

    //私有方法
    //由直角坐标计算向量长度和矢量方向
    void Vector::set_mag(){
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang(){
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    //由极坐标计算x，y
    void Vector::set_x(){
        x = mag * cos(ang);
    }

    void Vector::set_y(){
        y = mag * sin(ang);
    }

    //公有方法
    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        //如果模式为RECT,就按直角坐标赋值
        if (form == RECT)
        {
            x = n1;
            y = n2;
            //同时计算极坐标表示法的值
            set_mag();
            set_ang();
        }
        //如果模式为POL，就按极坐标赋值
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            //同时计算直角坐标表示法的值
            set_x();
            set_y();
        }
        //如果两者都不是，报错提示
        else
        {
            std::cout << "Vector()方法的第三个参数不正确 --";
            std::cout << "vector设置为0.\n";
            x = y = mag = ang = 0.0;
            mode = RECT; 
        }
        
    }

    //如果表格是RECT(默认)，则从直角坐标重置矢量；
    //如果表格是POL，则从极坐标重置矢量
    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "Vector()方法的第三个参数不正确 --";
            std::cout << "vector设置为0.\n";
            x = y = mag = ang = 0.0;
            mode = RECT; 
        }
    }

    //析构函数
        Vector::~Vector(){

        }
    
    void Vector::polar_mode(){mode = POL;}
    void Vector::rect_mode(){mode = RECT;}

    //运算符重载
    //计算两个Vector类对象的和
    Vector Vector::operator+(const Vector & b) const{
        return Vector(x + b.x, y + b.y);
    }

    //计算两个Vector对象的差
    Vector Vector::operator-(const Vector & b) const{
        return Vector(x - b.x, y - b.y);
    }

    //设置负值的Vector对象
    Vector Vector::operator-() const{
        return Vector(-x, -y);
    }

    //计算Vector对象乘以n(直角坐标))
    Vector Vector::operator*(double n) const{
        return Vector(n * x, n * y);
    }

    //友元函数
    //计算Vector对象乘以n（极坐标）
    //此处使用类的友元函数来重载类对象的乘法运算符，计算极坐标乘以n
    Vector operator*(double n, const Vector & a){
        return a * n;
    }

    //重载输出运算符，使得类对象可以像普通变量那样使用“<<”运算符进行输出
    std::ostream & operator<<(std::ostream & os, const Vector & v){
        if (v.mode == Vector::RECT)
        {
            os << "(X,Y) = (" << v.x << "," << v.y << ")";
        }
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << "," << v.ang * Rad_to_deg
                << ")";
        }
        else
        {
            os << "Vector对象模式无效！\n";
        }
        return os;
    }
} // namespace VECTOR
