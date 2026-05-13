#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF = 1e9;
const int MAX = 5e5+5;
int a[MAX],tree[MAX];
int n;
int lowbit(int x)
{
    return x&-x;
}
void change(int x,int y)
{
    while(x<=n)
    {
        tree[x]+=y;
        x+=lowbit(x);
    }
}
ll query(int x)
{
    ll t = 0;
    while(x)x+=tree[x],x-=lowbit(x);
    return t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    ll ans = 0;
    for(int i = n;i>=1;i--)
    {
        ans+=query(a[i]);
        change(a[i],1);
    }
    cout<<ans<<endl;
}