//赋值运算符重载
//c++编译器至少给一个类添加四个函数
//1默认构造函数（无参）
//2默认析构函数
//3默认拷贝构造函数
//4赋值运算符operator=，对属性进行拷贝
#include<iostream>
using namespace std;
class person
{
friend ostream& operator<<(ostream&out,person&p);
friend void test();
public:
    person(int a)
    {
        m_a = new int (a);
    }
    person& operator=(person &p)//重载运算符=深拷贝
    {
        if(m_a !=nullptr)
        {
            delete m_a;
            m_a = nullptr;
        }
        m_a = new int (*p.m_a);
        return *this;
    }
private:
    int* m_a;
};
ostream& operator<<(ostream &out,person &p)
{
    out<<*p.m_a;
    return out;
}
void test()
{
    person p1(18);

    person p2(20);

    person p3(30);
    p3 = p2 = p1;//如果把成员开辟在堆区，编译器直接赋值会造成地址变换
    //造成浅拷贝内存重复释放
    cout<<"p1的年龄为: "<<p1<<endl;
    cout<<"p2的年龄为: "<<p2<<endl;
}
int main()
{
    test();

    return 0;
}
