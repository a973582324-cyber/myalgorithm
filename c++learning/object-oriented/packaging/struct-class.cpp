//struct默认权限是public(公共)，class默认权限是private(私有)
//这是两者唯一的区别
#include<iostream>
#include<string>
using namespace std;
class C1
{
    int m_a; //默认权限是private(私有)
};
struct S1
{
    int m_a; //默认权限是public(公共)
    private:
    int m_b; //访问权限是private(私有)，不能访问
};
int main()
{
    C1 c1;
    //c1.m_a = 10; //错误，访问权限是private(私有)，不能访问
    S1 s1;
    s1.m_a = 10; //正确，访问权限是public(公共)，可以访问
    cout<<"s1.m_a = "<<s1.m_a<<endl;
    c1.m_a = 20; //错误，访问权限是private(私有)，不能访问
    s1.m_b = 20; //错误，访问权限是private(私有)，不能访问
    return 0;
}