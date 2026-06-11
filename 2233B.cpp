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
    int n;
    cin>>n;
    vector<int>ans(4*n);
    for(int i = 1;i<=n;i++)
    {
        unordered_map<int,int>hs;
        int pos = 0;
        int pre = 0;
        while(ans[pos]!=0)pos++;
        ans[pos] = i;
        pre = pos;
        hs[0] = 1;
        for(int t = 0;t<3;t++)
        {
            while((ans[pos]!=0||hs[pos - pre])&&pos<4*n)pos++;
            hs[pos - pre] = 1;
            ans[pos] = i;
            pre = pos;
        }
    }
    cout<<n<<' ';
    for(int i = 0;i<4*n-1;i++)
        cout<<ans[i]<<' ';
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
    return 0;
}