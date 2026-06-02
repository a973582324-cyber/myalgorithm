//类在设计时，可以打属性和行为放在不同权限下，加以控制
//权限分为三种：public、protected、private
//public：公共权限，成员，类内外都可以访问
//protected：保护权限，成员，类内和子类可以访问，类外不可以访问
//private：私有权限，成员，只有类内可以访问，类外和子类都
//不可以访问
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
    //公共成员，类内外都可以访问
    string name;
    string id;
protected:
    //保护成员，类内和子类可以访问，类外不可以访问
        string car;
private:
    //私有成员，只有类内可以访问，类外和子类都不可以访问
        string idcard;
public:
    void setName(string newName){
        name = newName; //通过成员函数来设置name的值
    }
    void setId(string newId){
        id = newId; //通过成员函数来设置id的值
    }
    void set()
    {
        car = "1";
        idcard = "1000";
    }
    void show(){
        cout<<"姓名："<<name<<endl;
        cout<<"学号："<<id<<endl;
        cout<<car<<endl;
        cout<<idcard<<endl;
    }
};
int main()
{
    person p1;
    //p1.name = "路悠扬";
    //p1.id = "2025017541";
    //p1.car = "111";//访问受保护成员，错误，不能访问
    //p1.idcard = "100000000000000000";//访问私有成员，错误，不能访问
    cin>>p1.name>>p1.id;
    p1.set();
    p1.show();
    return 0;
}