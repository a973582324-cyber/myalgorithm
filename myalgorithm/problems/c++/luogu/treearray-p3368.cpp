#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 5e5+5;
int n,m;
int a[MAX];
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
    }
    a[1] = b[1];
    for(int i = 1;i<=n;i++)
    {
        a[i] = b[i] - b[i-1];
        change(i,a[i]);
    }
    for(int i = 0;i<m;i++)
    {
        cin>>p>>x;
        if(p == 1)
        {
            cin>>y>>k;
            change(x,k),change(y+1,-k);
        }
        else
        {
            cout<<query(x)<<endl;
        }
    }
}