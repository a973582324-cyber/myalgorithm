#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve()
{
    int n;
    cin>>n;
    vector<ll>a(n+1),b(n+1);
    int index = 1;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>b[i];
    }
    ll sum = 0;
    for(int i = 1;i<=n;i++)
        sum+=max(a[i],b[i]);
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans = max(ans,sum + min(a[i],b[i]));
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
}//贪心，尽可能的把大的放到b中，从a，b中找到最大的最小相加