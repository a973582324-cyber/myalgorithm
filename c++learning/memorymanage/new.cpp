#include<iostream>
using namespace std;
//动态内存分配--new和delete
//new运算符用于在堆区动态分配内存，并返回指向该内存的指针。使用new分配的内存需要手动释放，使用delete运算符来释放内存。
//在C++11及以后的版本中，可以使用智能指针（如std::unique_ptr和std::shared_ptr）来自动管理堆内存，避免内存泄漏的问题。
int *func()
{
    int * p = new int(10); //动态分配内存，存储在堆区
    return p; //返回堆区内存的地址，安全！
}
int* func2()
{
    int * p1 = new int[5]; //动态分配一个整数数组，但没有保存指针，导致内存泄漏
    return p1; //返回堆区内存的地址，安全！
}
int main()
{
    int* p = func(); //调用函数，获取堆区内存的地址
    cout << *p << endl; //输出10
    delete p; //释放内存
    cout << *p << endl; //可能会输出10，但也可能输出垃圾值，因为内存已经被释放了
    int* p1 = func2(); //调用函数，获取堆区内存的地址
    for(int i = 0; i < 5; i++)
    {
        cout << p1[i] << " ";
    }
    delete[] p1; //释放数组内存
    for(int i = 0; i < 5; i++)
    {
        cout << p1[i] << " "; //可能会输出之前的值，但也可能输出垃圾值，因为内存已经被释放了
    }
    return 0;
}