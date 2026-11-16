// 手写双指针反转 string：交换首尾字符并向中间收缩，时间 O(n)、空间 O(1)。
// 该循环等价于 reverse(s.begin(),s.end()) 的核心过程。
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    //reverse的底层实现
    string s="hello world";
    int l = 0,r = s.size()-1;
    while(l<r)
    {
        swap(s[l],s[r]);
        l++;
        r--;
    }
}
