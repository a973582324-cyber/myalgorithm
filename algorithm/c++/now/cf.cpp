#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 5e5+5;
int n,m;
int b[MAX];
int tree[MAX];
int lowbit(int x)
{
    return (x & -x);
}
void change(int x,int k)
{
    while(x<=n)tree[x]+=k,x+=lowbit(x);
}
int query(int x)
{
    int t = 0;
    while(x)t+=tree[x],x-=lowbit(x);
    return t;
}
int main()
{
    cin>>n>>m;
    int p,x,y,k;
    for(int i = 1;i<=n;i++)
    {
        cin>>b[i];
        change(i,b[i]);
    }
    for(int i = 0;i<m;i++)
    {
        cin>>p>>x>>k;
        if(p == 1)
        {
            change(x,k);
        }
        else
        {
            cout<<query(k)-query(x-1)<<endl;
        }
    }
}