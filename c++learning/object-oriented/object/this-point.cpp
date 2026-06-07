//this指针用途
//this指向本类的对象
#include<iostream>
using namespace std;
//1.来区分变量，解决名称冲突
//2. 返回对象本身用*this
class person
{
public:
    person(int age)
    {
        this->age = age;
    }
    person& addage(person &p)
    {
        this->age += p.age;
        return *this; 
    }
    int age;
};
void test1()
{
    person p(10);
    cout<<p.age<<endl;
}
void test2()
{
    person p1(10);

    person p2(10);
    p2.addage(p1).addage(p1);//链式编程

}
int main()
{
    test1();
    return 0;
}