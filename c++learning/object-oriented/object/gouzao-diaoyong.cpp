//构造函数的调用规则
//创建一个类，c++编译器会给每个类都添加至少三个函数
//默认构造（空）
//析构函数（空）
//拷贝构造（值拷贝）
//如果我们自己写了有参构造函数，编译器就不会再添加默认构造函数了，但依然提供拷贝构造
//如果我们自己写了拷贝构造函数，编译器就不会再添加默认构造函数了，也不会提供有参构造函数了
#include<iostream>
using namespace std;
class person
{
public:
    person()
    {
        cout<<"默认构造函数调用"<<endl;
    }
    person(int a)
    {
        cout<<"有参构造"<<endl;
    }
    // person(const person&p)//
    // {
    //     age = p.age;
    //     cout<<"拷贝构造"<<endl;
    // }
    ~person()
    {
        cout<<"析构函数调用"<<endl;
    }
    int age;
};
void test1()
{
    person p1;
    p1.age = 18;
    person p2(p1);
    cout<<"p2的年龄为: "<<p2.age<<endl;
}
int main()
{
    test1();
    return 0;
}