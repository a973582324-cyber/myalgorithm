//类对象作为类成员
#include<iostream>
#include<string>
using namespace std;
class phone
{
public:
    phone(string name)
    {
        m_name = name;
        cout<<"手机"<<endl;
    }
    string m_name;
};
class person
{
public:
    //利用隐式转换法初始化phone
    person(string name,string pname):m_name(name),m_phone(pname){cout<<"人"<<endl;}
    string m_name;

    phone m_phone;
};
//当其他类的对象作为本类的成员，在构造的时候先构造类再构造自身，在析构的时候先调用本类后调用成员类
void test()
{
    person p("路悠扬","8848");
    cout<<"用户名字： "<<p.m_name<<endl;
    cout<<"用户手机名字: "<<p.m_phone.m_name<<endl;
}
int main()
{
    test();
    return 0;
}