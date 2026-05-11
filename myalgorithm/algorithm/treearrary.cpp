#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
int n;
int tree[MAX];
int lowbit(int x)
{
    return (x&-x);
}
void change(int x,int k)
{
    while(x<=n)tree[x]+=k,x+=lowbit(x);
}
int query(int x)
{
    int t = 0;
    while(x)t+=tree[x],x-=lowbit(x);//获得前缀和
    return t;
}