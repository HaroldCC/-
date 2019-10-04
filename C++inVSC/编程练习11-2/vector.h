#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        //RECT为直角坐标表示法，POL为极坐标表示法
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        Mode mode;             //选择表示方法（直角坐标表示法，极坐标表示法）

        //设置值的私有方法
        double set_mag() const;
        double set_ang() const;
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);
    public:
        Vector();   
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;};
        double magval() const {return set_mag();};
        double angval() const {return set_ang();};
        void polar_mode();                             //设置极坐标表示
        void rect_mode();                              //设置直角坐标表示

        //运算符重载
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        //友元函数
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
        
    };
    
} // namespace VECTOR


#endif