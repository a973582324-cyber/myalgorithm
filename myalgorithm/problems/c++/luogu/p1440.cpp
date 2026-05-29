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
    ll n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>q(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<0<<endl;
    int l = 1,r = 0;
    for(int i = 1;i<n;i++)
    {
        while(l<=r&&a[q[r]]>=a[i])r--;
        q[++r] = i;
        while(l<=r&&q[l]<i-m+1)l++;
        cout<<a[q[l]]<<endl;
    }
    return 0;
}