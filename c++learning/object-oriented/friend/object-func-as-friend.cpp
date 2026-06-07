//成员函数做友元
#include<iostream>
using namespace std;
class building;
class person
{
public:
    person();
    void visit();
public:
    building *build;//注意用指针
};
class building
{
public:
    building();
public:
    string m_livingroom;
private:
    string m_bedroom;
};
person::person()
{
    build = new building;
}
void person::visit()
{
    cout<<"正在访问："<<build->m_livingroom<<endl;
} 
building::building()
{
    m_bedroom = "卧室";
    m_livingroom = "客厅";
}
void test()
{
    person a;
    a.visit();
}
int main()
{
    test();
    return 0;
}