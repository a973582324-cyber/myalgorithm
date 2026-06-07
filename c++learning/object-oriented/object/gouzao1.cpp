//构造函数的分类和应用
//构造函数的两种分类方式和三种调用方式
//按参数分为：有参构造和无参构造
//按类型分为：普通构造和拷贝构造
//调用方式：
//括号法，显示法，隐式转换法
#include<iostream>
using namespace std;
class person
{
public:
    //1.构造函数
    person()//无参，默认构造
    {
        cout<<"无参构造函数的调用"<<endl;
    }
    person(int a)//有参，
    {
        age = a;
        cout<<"有参构造函数的调用"<<endl;
    }
    person(const person &p)//拷贝构造，
    {
        //将传入的所有的属性拷贝过来
        age = p.age;
        cout<<"拷贝构造的调用"<<endl;
    }
    //2析构函数
    ~person()
    {
        cout<<"析构函数调用"<<endl;
    }
    int age;
};
//调用
void test1()
{
    //括号法
    //person p1;//默认构造函数的调用//调用默认构造函数的时候不能加括号
  ////person p1();//编译器会认为是一个函数的声明
    //person p2(18);
    //person p3(p2);
    //cout<<"p2的年龄为: "<<p2.age<<' '<<p3.age<<endl;
    //显示法
    person p1;
    person p2 = person(10);
    person p3 = person(p2);
    //person(10);//匿名对象,特点：当前行执行结束后，系统会立刻回收掉匿名对象
    //不要利用拷贝构造函数初始化匿名对象
    //person(p3);//编译器会认为person(p3) == person p3;
    //隐式转换法
    person p4 = 10;//相当于 = person(10);
    person p5 = p3;
}
int main()
{
    test1();
    return 0;
}