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
        double mag;             //向量长度
        double ang;             //矢量方向（以度为单位）
        Mode mode;             //选择表示方法（直角坐标表示法，极坐标表示法）

        //设置值的私有方法
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
        
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;};
        double magval() const {return mag;};
        double angval() const {return ang;};
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