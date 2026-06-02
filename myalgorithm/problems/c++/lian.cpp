#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>a(2*n+1),b(2*n+1);
    vector<int>q(2*n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=n)
        a[i+n] = a[i];
    }
    for(int i = 1;i<=2*n-1;i++)
        b[i] = b[i-1]+a[i];
    ll ans = 0;
    int h = 1,t = 0;
    for(int i = 1;i<=2*n-1;i++)
    {
        while(h<=t&&b[q[t]]>=b[i])t--;
        q[++t] = i;
        while(h<=t&&q[h]<i-n+1)h++;
        if(i>=n&&b[q[h]]-b[i-n]>=0)ans++;
    }
    cout<<ans<<endl;
}