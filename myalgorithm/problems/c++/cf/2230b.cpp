#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int minn = -1e7;
void solve()
{
    string s;
    cin>>s;
    ll ans = 0;
    int n = s.size();
    vector<ll>pre(n+1);
    s = '_'+s;
    for(int i = 1;i<=n;i++)
    {
        pre[i] = pre[i-1];
        if(s[i]=='1'||s[i]=='3')
            pre[i]++;
        else if(s[i]=='4')
            ans++;
        else
        {
            if(pre[i]>0)
            {
                pre[i]--;
                ans++;
            }
        }
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
}