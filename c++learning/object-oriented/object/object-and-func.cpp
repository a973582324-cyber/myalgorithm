//成员变量和成员函数分开存储
#include<iostream>
using namespace std;
class person
{
    int m_A;//在类对象上
    static int m_B;//静态变量不在类对象上
};
int person::m_B = 10;
void test1()
{
    person p;
    //c++编译器会给每个空对象分配一个字节空间，为了区分空对象占内存的位置
    //每个空对象也有一个独一无二的内存地址
    cout<<sizeof(p);
}
void test2()
{
    person p;
    cout<<sizeof(p);
}
int main()
{
    test2();
    return 0;
}