#include<iostream>
using namespace std;
int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9,};
    int *p = a;//指针指向数组
    for(int i = 0;i<10;i++)//遍历数组
    {
        cout<<*p<<' ';
        p++;//指针偏移4个字节
        cout<<p<<' ';
    }
    cout<<p<<endl;
}