//++运算符的重载
//前置递增
//后置递增
#include<iostream>
using namespace std;
//重载递增运算符
class person
{
    friend ostream& operator<<(ostream &out,const person &p);
public:
    person()
    {
        m_a = 0;
    }
    //重载前置++
    person& operator++()
    {
        m_a++;   
        return *this;
    }
    //重载后置++,int 为占位参数，用来区分前置和后置递增

    person operator++(int)
    {
        person t = *this;
        m_a++;
        return t;
    }
private:
    int m_a;
};
ostream& operator<<(ostream &out,const person &p)//后置++返回的是临时拷贝的值，必须用const接受这个右值
{
    out<<p.m_a;
    return out;
}
void test()
{
   person p;
   cout<<++p<<endl; 
   cout<<p++<<endl;
   cout<<p<<endl;
}
int main()
{
    test();
    return 0;
}