#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve()
{
    int n;
    int jud = 0;
    cin>>n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int>ans;
    for(int i = n;i>0;i--)
    {
        if(jud == 1)
            a[i] = -a[i];
        if(a[i]>0)
        {
            ans.push_back(i);
            jud^=1;
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
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