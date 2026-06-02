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
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1,0),dp(n+1,-1e7);
    for(int i = 0;i<=n;i++)
    {
        cin>>a[i];
    }
    /*for(int i = 1;i<=n+1;i++)
    { 
        for(int j = i - 1;j>=0;j--)
        {
            if(i - j < l)continue;
            if(i - j > r)break;
            dp[i] = max(dp[i],dp[j]+a[i]);
        }
    }*/
    int h = 1,t = 0;
    vector<int>q(n+1);
    int ans = dp[0];
    dp[0] = 0;
    int p = 0;
    for(int i = l;i<=n;i++)
    {
        while(h<=t&&dp[q[t]]<=dp[p])t--;
        q[++t] = p;
        while(h<=t&&q[h] + r < i)h++;
        dp[i] = dp[q[h]] + a[i];
        p++;
    }
    for(int i = n + 1 - r;i<= n;i++)
    {
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
}