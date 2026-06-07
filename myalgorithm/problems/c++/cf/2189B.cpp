#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
const int minn = -1e7;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
//尽可能用没到达限定次数的方式走，之后找最大的可以到达的方式走，可以尽可能减少后退的次数，最后向上取整
//如果最大的小于0，则输出-1，不可能到达
void solve()
{
    int n;
    ll x;
    cin>>n>>x;
    vector<ll>a(n),b(n),c(n);
    ll maxx =-1e18;
    ll l = 0;
    for(int i = 0 ;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        maxx = max(maxx,a[i]*b[i]-c[i]);
        l += a[i]*(b[i]-1);
    }
    x -= l;
    if(x<=0)
    {
        cout<<0<<endl;
        return;
    }
    if(maxx<=0)
    {
        cout<<-1<<endl;
        return;
    }
    cout << (x + maxx-1)/maxx<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}