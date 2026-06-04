#pragma once
#include<iostream>
using namespace std;
class point
{
public:
    //设置x
    void setX(int x);
    //设置y
    void setY(int y);
    //获取x
    int getX();
    //获取y
    int getY();
private:
    int m_x;
    int m_y;
};