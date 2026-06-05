//深拷贝和浅拷贝
//浅拷贝的问题会带来堆区的内存重复释放
//深拷贝可以解决
#include<iostream>
using namespace std;
class person
{
public:
    person()
    {

    }
    person(int age,int h)
    {
        height = new int(h);
        m_age = age;
        cout<<"person的有参函数的调用"<<endl;
    }
    person(const person &p)
    {
        cout<<"person的拷贝构造函数的调用"<<endl;
        m_age = p.m_age;
        height = new int(*p.height);//深拷贝，解决释放问题
    }
    ~person()
    {
        //析构代码，将堆区的数据释放
        if(height!=nullptr)
        {
           delete height; 
           height = nullptr;
        }
        cout<<"析构函数的调用"<<endl;
    }
    int m_age;
    int *height;
};
void test()
{
    person p1(18,150);
    person p2(p1);
    cout<<"身高为："<<*p2.height<<' '<<"年龄为: "<<p2.m_age<<endl;
}
int main()
{
    test();
    return 0;
}