//封装的意义：
//将属性和行为作为一个整体，表现生活中的事物
//将属性和行为加以权限控制
#include <iostream>
using namespace std;
const double PI = 3.14;

//设计一个圆类，求圆的周长
//公式：周长=2 * PI * 半径

//class代表要设计一个类
class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    double m_r; //半径
    //行为：通常用函数来表现
    double calculateZC() //求周长
    {
        return 2 * PI * m_r;
    }

};
int main()
{
    //实例化（通过一个类 创建对象的过程）
    Circle c1; //创建圆的对象
    c1.m_r = 5.0; //给半径赋值
    cout << "圆的周长是：" << c1.calculateZC() << endl; //调用函数求周长
    return 0;
}