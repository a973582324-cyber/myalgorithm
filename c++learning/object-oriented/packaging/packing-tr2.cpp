#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;
//分文件编写
//直接在main函数中编写代码，代码冗长，不清晰，不易维护，不易扩展
//分文件编写可以将代码分成多个文件，每个文件负责一个类的实现，代码清晰，结构清晰，易于维护，易于扩展
//点和圆关系判断
//点在圆内，圆外，圆上
// class point
// {
// public:
//     void setX(int x)
//     {
//         m_x = x;
//     }
//     void setY(int y)
//     {
//         m_y = y;
//     }
//     int getX()
//     {
//         return m_x;
//     }
//     int getY()
//     {
//         return m_y;
//     }
// private:
//     int m_x;
//     int m_y;
// };
// class Circle
// {
// public:
//     void setR(int r)
//     {
//         m_r = r;
//     }
//     int getR()
//     {
//         return m_r;
//     }
//     void setcenter(point center)
//     {
//         m_center = center;
//     }
//     point getcenter()
//     {
//         return m_center;
//     }
//     void whereispoint(point &p)
//     {
//         int x = p.getX()-m_center.getX();
//         int y = p.getY()-m_center.getY();
//         int distance = x*x+y*y;
//         if(distance > m_r*m_r)
//             cout<<"点在圆外"<<endl;
//         else if(distance < m_r*m_r)
//             cout<<"点在圆内"<<endl;
//         else
//             cout<<"点在圆上"<<endl;
//     }
// private:
//     int m_r;
//     point m_center;  
// };
void ispoint(point &p, Circle &c)
{
    int x = p.getX()-c.getcenter().getX();
    int y = p.getY()-c.getcenter().getY();
    int distance = x*x+y*y;
    if(distance > c.getR()*c.getR())
        cout << "点在圆外" << endl;
    else if(distance < c.getR()*c.getR())
        cout << "点在圆内" << endl;
    else
        cout << "点在圆上" << endl;
}
int main()
{

    //创建圆
    Circle c;
    c.setR(10);
    point center;
    center.setX(10);
    center.setY(0);
    c.setcenter(center);

    //创建点
    point p;
    p.setX(10);
    p.setY(9);

    //判断关系
    ispoint(p, c);
}