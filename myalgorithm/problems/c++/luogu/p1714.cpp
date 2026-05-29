#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<ll>a(n+1),b(n+1);
    deque<int>q;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    q.push_back(0);
    ll ans = -1e7;
    for(int i = 1;i<=n;i++)
    {
        while(!q.empty()&&q.front()<i-m)q.pop_front();
        ans = max(ans,b[i]-b[q.front()]);
        while(!q.empty()&&b[i]<=b[q.back()])q.pop_back();
        q.push_back(i); 
    }
    cout<<ans<<endl;
}