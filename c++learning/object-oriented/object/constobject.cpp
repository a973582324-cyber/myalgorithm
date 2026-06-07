//静态成员
//静态成员变量和静态成员函数
//静态成员变量
//所有对象共享同一份数据,在编译时分配内存，类内声明，类外初始化
//静态成员函数
//所有对象共享一个函数，静态成员函数只能访问静态成员变量
#include<iostream>
using namespace std;
class person
{
public:
    static int m_A;
private:
    static int m_B;
};
class person1
{
public:
    static void func()
    {
        cout<<m_A<<endl;//m_b会报错
    }
    static int m_A;
    int m_b;
}; 
int person::m_A = 100;
int person::m_B = 200;
int person1::m_A = 10;
void test1()
{
    person p1;
    person p2;
    cout<<p1.m_A<<endl;
    p2.m_A = 200;
    cout<<p1.m_A<<endl;
}
//静态成员变量有两种访问方式
//1.通过类名访问，2.通过对象访问
//静态成员变量也有访问权限
void test2()
{
    person p1;
    cout<<p1.m_A;//报错
}
void test3()
{
    //1.通过对象访问静态成员函数
    person1 p;
    p.func();
    //2.通过类名访问函数
    person1::func();
}
int main()
{
    test3();
    return 0;
}