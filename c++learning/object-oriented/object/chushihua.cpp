//初始化列表
//作用：用来初始化属性
//语法：构造函数（）：属性1(值1),属性2(值2),属性3(值3){}
#include<iostream>
using namespace std;
class person
{
public:
    person(int a,int b,int c)
    {
        A = a;
        B = b;
        C = c;
    }   
    person(int a,int b,int c):A(a),B(b),C(c){}//初始化列表
    int A,B,C;
};