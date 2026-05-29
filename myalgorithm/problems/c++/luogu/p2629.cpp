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
    ll n;
    cin>>n;
    ll ans = 0;
    vector<ll>a(2*n+2);
    vector<ll>b(2*n+2);
    vector<int>q(2*n+2);
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    for(int i = 1;i<n;i++)
        a[i+n] = a[i];
    for(int i = 1;i<=2*n-1;i++)
        b[i] = a[i]+b[i-1];
    int h = 1,t = 0;
    for(int i = 1;i<=2*n-1;i++)
    {
        while(h<=t&&b[q[t]]>=b[i]) t--;   
        q[++t] = i;
        while(h<=t&&q[h]<=i-n) h++;
        if(i>=n&&b[q[h]]-b[i-n]>=0)ans++;
    }
    cout<<ans<<endl;
}