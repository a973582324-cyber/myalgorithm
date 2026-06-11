#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
const int minn = INF;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
void solve()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int ans = INF,t1,t2,sum;
    t1 = (n + x + y - 1)/(x + y);
    sum = z * x;
    if(sum>=n)
    {
        ans = t1;
    }
    else
    {
        t2 = z;
        t2 += (n - sum + x + 10 * y - 1)/(x + 10 * y);
        ans = min(t1,t2);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}