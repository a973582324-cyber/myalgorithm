#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int minn = -1e7;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>h(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>h[i];
    }
    vector<int>ans(n+1,INF);
    vector<int>q(n+1);
    int t = 0;
    for(int i = n ;i>0;i--)
    {
        while(t>0&&h[q[t]]<=h[i])t--;
        if(!q.empty())ans[i] = q[t];
        else ans[i] = 0;
        q[++t] = i;
    }
    for(int i = 1;i<=n;i++)
        cout<<ans[i]<<endl;
}

