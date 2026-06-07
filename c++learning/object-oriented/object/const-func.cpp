//const修饰成员函数
//成员函数后加const后我们称这个函数为常函数
//常函数内不可修改成员属性
//成员属性声明加关键字mutable后，在常函数中依然可以修改
//常对象:
//声明前加const的称该对象为常对象
//只能调用常函数
#include<iostream>
using namespace std;
class person
{
public:
    person():m_a(10){}//初始化列表
    void showperson()const//加上const之后就不可以修改成员属性了，this也不行
    {
        //这个const修饰了this，this是以person * const this定义的相当于在前面加const
        //this指针是指针常量，不可以修改指针指向
        cout<<m_a<<endl;
    }
    int m_b;
    mutable int m_a;//加上mutable之后就可以被修改了
};
void test1()
{
    person p;
    p.showperson();
}
void test2()
{
    const person p1;
    p1.m_a = 100;
    p1.showperson();
    //常对象只能调用常函数，
}
int main()
{
    test2();
    return 0;
}