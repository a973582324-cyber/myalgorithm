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
    vector<int>a(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans;
    sort(a.begin(),a.end());
    int c = (a[0]+a[n-1])/2;
    ans = max(c-a[0],a[n-1]-c);
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
}//本题目需要找出最大最小值，找到中间值，这是最优选择，之后找到最大最小值到这个点的距离的最大值即可