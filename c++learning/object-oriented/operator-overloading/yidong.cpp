//<<的重载
//应用于cout打印时
//这个应用只能在全局函数实现
#include<iostream>
using namespace std;
class person
{
public:
    int m_a;
    int m_b;
    void operator<<(person &p)
    {        
        cout<<p.m_a<<' '<<p.m_b;
    }
};
ostream& operator<<(ostream &out,person p)
{
    cout<<p.m_a<<' '<<p.m_b;
    return out;
}
void test()
{
    person p;
    p.m_a = 10;
    p.m_b = 20;
    cout<<p<<endl;
    //cout是输出流对象，属于ostream如果要实现链式输出，就要返回cout从左向右走
}
int main()
{
    test();
    return 0;
}