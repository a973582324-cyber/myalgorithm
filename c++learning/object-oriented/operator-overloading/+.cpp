//加号运算符重载
//通过成员函数重载+ 和 通过全局函数重载+
#include<iostream>
using namespace std;
class person
{
public:
    int m_a;
    int m_b;
    person(){};
    person (int a)
    {
        m_a = a;        
    }
    person (const person & p)
    {
        this->m_a = p.m_a;
        this->m_b = p.m_b;
    }
    person add(person p)//成员函数
    {
        person t;
        t.m_a = p.m_a + this->m_a;
        t.m_b = p.m_b + this->m_b;
        return t;
    }
    person operator+(person p)//运算符重载
    {
        person t;
        t.m_a = p.m_a + this->m_a;
        t.m_b = p.m_b + this->m_b;
        return t;
    }
};
// person operator+(person &p1,person &p2)
// {
//     person t;
//     t.m_a = p1.m_a + p2.m_a;
//     t.m_b = p1.m_b + p2.m_b;
// }//实现person+person
person operator+(person &p1,int &num)
{
    person t;
    t.m_a = p1.m_a + num;
    t.m_b = p1.m_b + num;
    return t;
}//实现person+int
void test()
{
    person p1;
    p1.m_a = 10;
    p1.m_b = 20;

    person p2;
    p2.m_a = 10;
    p2.m_b = 20;

    person p3 = p2.add(p1);//未重载写法
    person p4 = p2 + p1;//重载的简化写法

    p3 = p1.operator+(p2);//成员函数重载的本质调用
    //p3 = operator+(p1,p2);//全局函数的本质调用

    cout<<p3.m_a<<' '<<p3.m_b<<endl;

    int a = 10;
    int b = 20;
    int c = a + b;//重载不会影响正常的+，只会影响相应类型的运算
}
int main()
{
    test();
    
    return 0;
}