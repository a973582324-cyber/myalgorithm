//空指针调用成员函数
#include<iostream>
using namespace std;
class person
{
public:
    void showname()
    {
        cout<<"age = "<<m_age<<endl;;
    }
    void showclassname()
    {
        cout<<"person"<<endl;
    }
    person(int age)
    {
        m_age = age;
    }
    int m_age;
};
void test1()
{
    person *p = NULL;
    p->showclassname();
    p->showname();

}
int main()
{
    test1();
    return 0;
}