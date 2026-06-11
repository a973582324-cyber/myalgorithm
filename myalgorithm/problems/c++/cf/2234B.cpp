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
    ll n;
    cin>>n;
    if(n%12==10)
    {   
        if(n == 10)
        cout<<-1<<endl;
        else
        {
            ll ans1 = 22;
            ll ans2 = n - 22;
            cout<<ans1<<' '<<ans2<<endl;
        }
        return;
    }
    ll t = n / 12;
    ll ans2 = t * 12;
    ll ans1 = n - ans2;
    cout<<ans1<<' '<<ans2<<endl;
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
    return 0;
}