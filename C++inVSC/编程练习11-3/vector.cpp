#include "vector.h"
#include<cmath>

namespace VECTOR
{
    //���㻡�ȵĶ���
    const double Rad_to_deg = 45.0 / atan(1.0);

    //˽�з���
    //��ֱ����������������Ⱥ�ʸ������
    void Vector::set_mag(){
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang(){
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    //�ɼ��������x��y
    void Vector::set_x(){
        x = mag * cos(ang);
    }

    void Vector::set_y(){
        y = mag * sin(ang);
    }

    //���з���
    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        //���ģʽΪRECT,�Ͱ�ֱ�����긳ֵ
        if (form == RECT)
        {
            x = n1;
            y = n2;
            //ͬʱ���㼫�����ʾ����ֵ
            set_mag();
            set_ang();
        }
        //���ģʽΪPOL���Ͱ������긳ֵ
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            //ͬʱ����ֱ�������ʾ����ֵ
            set_x();
            set_y();
        }
        //������߶����ǣ�������ʾ
        else
        {
            std::cout << "Vector()�����ĵ�������������ȷ --";
            std::cout << "vector����Ϊ0.\n";
            x = y = mag = ang = 0.0;
            mode = RECT; 
        }
        
    }

    //��������RECT(Ĭ��)�����ֱ����������ʸ����
    //��������POL����Ӽ���������ʸ��
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
            std::cout << "Vector()�����ĵ�������������ȷ --";
            std::cout << "vector����Ϊ0.\n";
            x = y = mag = ang = 0.0;
            mode = RECT; 
        }
    }

    //��������
        Vector::~Vector(){

        }
    
    void Vector::polar_mode(){mode = POL;}
    void Vector::rect_mode(){mode = RECT;}

    //���������
    //��������Vector�����ĺ�
    Vector Vector::operator+(const Vector & b) const{
        return Vector(x + b.x, y + b.y);
    }

    //��������Vector����Ĳ�
    Vector Vector::operator-(const Vector & b) const{
        return Vector(x - b.x, y - b.y);
    }

    //���ø�ֵ��Vector����
    Vector Vector::operator-() const{
        return Vector(-x, -y);
    }

    //����Vector�������n(ֱ������))
    Vector Vector::operator*(double n) const{
        return Vector(n * x, n * y);
    }

    //��Ԫ����
    //����Vector�������n�������꣩
    //�˴�ʹ�������Ԫ���������������ĳ˷�����������㼫�������n
    Vector operator*(double n, const Vector & a){
        return a * n;
    }

    //��������������ʹ��������������ͨ��������ʹ�á�<<��������������
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
            os << "Vector����ģʽ��Ч��\n";
        }
        return os;
    }
} // namespace VECTOR
