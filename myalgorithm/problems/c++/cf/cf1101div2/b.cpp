#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve()
{
    int n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    ll ans = 1e18;
    ll sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sum+=a[i];
        ans =min(ans,sum / i);
        cout<<ans<<' ';
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
}