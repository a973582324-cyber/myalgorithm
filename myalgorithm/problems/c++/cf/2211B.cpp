#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
const int minn = -1e7;
const int mod = 676767677;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        vector<int>a;
        for(int i = 0;i<x;i++)
            a.push_back(1);
        for(int i = 0;i<y;i++)
            a.push_back(-1);
        int v = x-y;
        int ans = 0;
        for(int i = 1;i<=abs(x-y);i++)
        {
            if(v%i == 0)
                ans = (ans+1)%mod;
        }
        if(x-y==0)
        ans = 1;
        cout<<ans<<endl;
        for(auto &b:a)
        {
            cout<<b<<' ';
        }
        cout<<endl;
    }
}