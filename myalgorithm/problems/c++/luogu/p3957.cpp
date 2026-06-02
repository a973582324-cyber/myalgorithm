#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=5e5+5;
struct node
{
    ll lo;
    ll w;
};
ll n,d,k;
ll dp[N]; 
node a[N];
bool check(ll g)
{
    ll l = max(d-g,(ll)1);
    ll r = d+g;
    memset(dp,-127,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i-1;j>=0;j--)
        {
            if(l > a[i].lo - a[j].lo)continue;
            if(r < a[i].lo - a[j].lo)break;
            dp[i] = max(dp[i],dp[j] + a[i].w);
            if(dp[i]>=k)
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>d>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i].lo>>a[i].w;
    }
    ll l = 0,r = 1e5+5;
    while(l<=r)
    {
        ll mid = r+(l-r)/2;
        if(check(mid))r = mid - 1;
        else 
        l = mid + 1;
    }
    if(r == 1e5+5)
        cout<<-1<<endl;
    else
        cout<<l<<endl;
}