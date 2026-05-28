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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans = 0;
    sort(a.begin(),a.end());
    unordered_map<int,int> hs;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(hs.count(i-j)&&a[i]-a[j]!=a[j])
            {
                ans++;
                break;
            }
        }
        hs[i] = 1;
    }
    cout<<ans<<endl;
    return 0;
}
