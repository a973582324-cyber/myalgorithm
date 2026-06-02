//成员属性设置为私有
//优点：
//1.封装性：将成员属性设置为私有，可以隐藏内部实现细节，保护数据的安全性，防止外部直接访问和修改成员属性，增强了类的封装性。
//2.数据完整性：通过成员函数来访问和修改私有成员属性，可以在函数内部进行数据验证和约束，确保成员属性的值合法，维护数据的完整性。
//3.灵活性：将成员属性设置为私有，可以在类内部进行修改和优化成员属性的实现，而不影响外部代码的使用，提高了类的灵活性和可维护性。
//4.接口设计：通过成员函数来访问和修改私有成员属性，可以设计清晰的接口，提供必要的功能和操作，而不暴露内部实现细节，使得类的使用更加简单和直观。
//缺点：
//1.增加代码复杂度：将成员属性设置为私有，需要编写额外的成员函数来访问和修改私有成员属性，增加了代码的复杂度和工作量。
//2.性能开销：通过成员函数来访问和修改私有成员属性，可能会引入额外的函数调用开销，尤其是在频繁访问和修改成员属性的情况下，可能会影响性能。
#include<iostream>
#include<string>
using namespace std;
class person
{
private:
//对成员进行编辑操作，自己控制读写权限
    string m_Name;//可读可写
    int m_Age;//只读
    string m_Idol;//只写
public:
    //设置姓名：写
    void setname(string name)
    {
        m_Name = name;
    }
    //获取姓名：读
    string getname()
    {
        return m_Name;
    }
    //获取年龄，只可以读
    int getage()
    {
        return m_Age;
    }
    //设置偶像，只可以写
    void setidol(string idol)
    {
        m_Idol = idol;
    }
};
int main()
{
    person p;
    p.setname("张三");
    //p.setage("18");//不可写
    p.setidol("11");
    cout<<p.getname()<<endl;
    cout<<p.getage()<<endl;
    cout<<p.getidol()<<endl;//不可读
    return 0;
}
