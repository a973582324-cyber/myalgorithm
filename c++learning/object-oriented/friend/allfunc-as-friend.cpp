//全局函数做友元
#include<iostream>
#include<string>
using namespace std;
class building
{
    friend void goodfriend(building &build);//告诉编译器goodfriend
    //可以访问building的私有内容
public:
    building()//构造函数
    {
        m_bedroom ="卧室";
        m_sittingroom = "客厅";
    }
public:
    string m_sittingroom;
private:
    string m_bedroom;
};
void goodfriend(building &build)
{
    cout<<"全局函数正在访问： "<<build.m_bedroom<<endl;

}
void test1()
{
    building build;
    goodfriend(build);
}
int main()
{
    test1();
    return 0;
}