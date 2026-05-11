#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int MAX = 5e5+5;
struct node{
    int index;
    ll x;
    ll w;
};
node a[MAX];
ll tree[MAX];
int n,m;
ll lowbit(int x)
{
    return (x&-x);
}
void change(int x,ll k)
{
    while(x<=n)tree[x]+=k,x+=lowbit(x);
}
ll query(int x)
{
    ll t = 0;
    while(x)t+=tree[x],x-=lowbit(x);
    return t;
}
bool cmp(const node &xx,const node &y)
{
    if(xx.x==y.x)
    return xx.index<y.index;
    return xx.x<y.x;
}
bool cmp1(const node &xx,const node &y)
{
    return xx.index<y.index;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;   
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i].x;
        a[i].index = i;
    }
    sort(a+1,a+n+1,cmp);
    ll sum = 0;
    for(int i = 1;i<=n;i++)
    {
        a[i].w = a[i].x*(ll)(i-1)-sum;
        sum+=a[i].x;
    }
    memset(tree, 0, sizeof tree);
    for(int i = 1;i<=n;i++)
    {
        ll cnt = query(a[i].index-1);
        a[i].w +=cnt;
        change(a[i].index,1);
    }
    sort(a+1,a+1+n,cmp1);
    for(int i = 1;i<=n;i++)
    {
        if(a[i].w>m-2)
            cout<<-1<<endl;
        else
            cout<<a[i].w<<endl;
    }
}
