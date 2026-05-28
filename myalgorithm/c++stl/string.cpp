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