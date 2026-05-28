#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    int *p = &a;
    cout<<"sizeof(int *) = "<<sizeof(int *)<<endl;
    //常量指针
    const int *p1 = &a;//指针的指向可以修改，但是指针指向的值不能改
    cout<<p1<<' ';
    cout<<*p1<<endl;
    p1 = &b;
    cout<<p1<<' ';   
    //指针常量
    int *const p2 = &a;
    *p = 20;//指针的指向不能修改，指向的值可以改
    const int *const p3 = &a;
}