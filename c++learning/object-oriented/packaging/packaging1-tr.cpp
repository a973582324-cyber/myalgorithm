#include<iostream>
#include<string>
using namespace std;
class student{
    //属性和行为均称为成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法
    public:

    // id = "20210001"; //错误，不能在类内直接给非静态成员变量赋值,可以用函数给非静态成员变量赋值
    void setId(string newId){
        id = newId; //通过成员函数来设置id的值
    }
    void setName(string newName){
        name = newName; //通过成员函数来设置name的值
    }
    void show(){
        cout<<"姓名："<<name<<endl;
        cout<<"学号："<<id<<endl;
    }
public:
    string name;
    string id;
};
int main()
{
    string id,name;
    cin>>name>>id;
    student s1;
    s1.name = name; //直接访问成员变量来设置name的值
    s1.name ="张三"; //直接访问成员变量来设置name的值
    s1.setName(name); //通过成员函数来设置name的值
    s1.setId(id); //通过成员函数来设置id的值
    s1.show();
    return 0;
}