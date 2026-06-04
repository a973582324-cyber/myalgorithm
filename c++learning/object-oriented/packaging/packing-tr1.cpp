#include<iostream>
#include<cmath>
using namespace std;
//设计立方体类，要求求出立方体的面积和体积
//分别利用一个成员函数和全局函数判断两个立方体是否相等
class Cube
{
public:
    void setl(double l)
    {
        m_L = l;
    }
    void seth(double h)
    {
        m_H = h;
    }
    void setw(double w)
    {
        m_W = w;
    }
    double get_l()
    {
        return m_L;
    }
    double get_h()
    {
        return m_H;
    }
    double get_w()
    {
        return m_W;
    }
    double get_s()
    {
        return ((m_L*m_W)+(m_L*m_H)+(m_W*m_H))*2;
    }
    double get_v()
    {
        return m_H*m_L*m_W;
    }
    //成员函数判断是否相等
    bool isSameByClass(Cube&c)
    {
        if(fabs(m_H-c.get_h())<1e-7&&fabs(m_L-c.get_l())<1e-7&&fabs(m_W-c.get_w())<1e-7)
            return true;
        return false;
    }
private:
    double m_H;
    double m_L;
    double m_W;
};
//利用全局函数判断两个立方体是否相等
bool jud(Cube &a,Cube &b)
{
    double a_l = a.get_l();
    double a_w = a.get_w();
    double a_h = a.get_h();
    double b_l = b.get_l();
    double b_w = b.get_w();
    double b_h = b.get_h();
    if(fabs(a_l-b_l)<1e-7&&fabs(a_h-b_h)<1e-7&&fabs(a_w-b_w)<1e-7)
    return true;
    return false;
}
int main()
{
    Cube c;
    c.seth(11);
    c.setl(20);
    c.setw(5);
    cout<<c.get_h()<<endl;
    cout<<c.get_l()<<endl;
    cout<<c.get_w()<<endl;
    cout<<c.get_s()<<endl;
    cout<<c.get_v()<<endl;
    Cube b;
    b.seth(10);
    b.setl(20);
    b.setw(5);
    if(jud(c,b))
        cout<<"两个正方体相等"<<endl;
    else
        cout<<"两个正方体不相等"<<endl;
    if(b.isSameByClass(c))
        cout<<"两个正方体相等"<<endl;
    else
        cout<<"两个正方体不相等"<<endl;
}