//类做友元
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
    person();
    void visit();
    string phone;
    int age;
    building* build;
};
class building
{
    friend person;
public:
    building()
    {
        m_bedroom = "卧室";
        m_sittingroom = "客厅";
    }
public:
    string m_sittingroom;

private:
    string m_bedroom;
};
person::person()
{
    build = new building;
    age = 18;
    phone = "114514";
}
void person::visit()
{
    cout<<"正在访问："<<build->m_sittingroom<<endl;
}
void test()
{
    person p;
    building p;
}
int main()
{
    test();
    return 0;
}