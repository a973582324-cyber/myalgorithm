//分文件编写
//点和圆关系判断
//点在圆内，圆外，圆上
//圆类
//优点：
//1.代码清晰，结构清晰
//2.易于维护
//3.易于扩展，添加新功能只需要修改相关类，不需要修改其他类
//缺点：
//1.增加了类之间的依赖关系，可能会导致循环依赖
//2.增加了代码量，可能会导致代码冗长
//必须加上#pragma once，否则会导致重复包含
//必须加上#include"point.h"，否则会导致找不到point类的定义
//必须加上 Circle::，否则会导致找不到point类的成员函数
#include"circle.h"
void Circle::setR(int r)
{
    m_r = r;
}
int Circle::getR()
{
    return m_r;
}
void Circle::setcenter(point center)
{
    m_center = center;
}
point Circle::getcenter()
{
    return m_center;
}
void Circle::whereispoint(point &p)
{
    int x = p.getX()-m_center.getX();
    int y = p.getY()-m_center.getY();
    int distance = x*x+y*y;
    if(distance > m_r*m_r)
        cout<<"点在圆外"<<endl;
    else if(distance < m_r*m_r)
        cout<<"点在圆内"<<endl;
    else
        cout<<"点在圆上"<<endl;
}