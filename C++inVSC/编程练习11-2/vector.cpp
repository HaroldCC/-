#include "vector.h"
#include<cmath>

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    double Vector::set_mag() const{
        return sqrt(x * x + y * y);
    }

    double Vector::set_ang() const{
        if (x == 0.0 && y == 0.0)
        {
            return 0;
        }
        else
        {
            return atan2(y, x);
        }
        
    }

    void Vector::set_x(double mag, double ang){
        x = mag * cos(ang);
    }

    void Vector::set_y(double mag, double ang){
        y = mag * sin(ang);
    }

    //公有方法
    Vector::Vector(){
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        }
        else
        {
            std::cout << "Vector()方法的第三个参数不正确 --";
            std::cout << "vector设置为0.\n";
            x = y = 0.0;
            mode = RECT; 
        }
        
    }

    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        }
        else
        {
            std::cout << "Vector()方法的第三个参数不正确 --";
            std::cout << "vector设置为0.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector(){

    }

    void Vector::polar_mode() //设置极坐标表示
    {
        mode = POL;
    }

    void Vector::rect_mode()  //设置直角坐标表示
    {
        mode = RECT;
    }

    //运算符重载
    Vector Vector::operator+(const Vector & b) const{
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const{
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const{
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const{
        return Vector(x * n, y * n);
    }

    //友元函数
    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == Vector::RECT)
        {
            os << "(x,y) = (" << v.x << "," << v.y << ")";
        }
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << "," << v.angval() * Rad_to_deg << ")";
        }
        else
        {
            os << "Vector对象模式无效！\n";
        }
        return os;
    }
} // namespace VECTOR
