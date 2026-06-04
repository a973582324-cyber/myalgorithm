#pragma once
#include<iostream>
#include"point.h"
using namespace std;
class Circle
{
public:
    void setR(int r);
    int getR();
    void setcenter(point center);
    point getcenter();
    void whereispoint(point &p);
private:
    int m_r;
    point m_center;  
};