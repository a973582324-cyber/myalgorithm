#include<iostream>
using namespace std;
//实现两数交换
//声明
void swap (int a,int b);
//定义
void swap(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<' '<<b;
}