//拷贝构造函数的调用时机
//1.对象被用来初始化另一个对象时
//2.对象以值传递的方式传递给函数参数时
//3.对象以值返回的方式从函数返回时
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
    person(const person&p)
    {
        age = p.age;
        cout<<"拷贝构造"<<endl;
    }
    ~person()
    {
        cout<<"析构函数调用"<<endl;
    }
    int age;
};
void test1()
{
    person p1(10);
    person p2(p1);
    cout<<"p2的年龄为: "<<p2.age<<endl;
}
void work(person p)//在创建形参是调用了拷贝构造
{   
    
}
void test2()
{
    person p;
    work(p);
}
int main()
{
    return 0;
}