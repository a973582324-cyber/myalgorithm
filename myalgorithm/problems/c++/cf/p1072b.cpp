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
    int t;
    cin>>t;
    while(t--)
    {
        int s,k,m;
        cin>>s>>k>>m;
        if(s<=k)cout<<max(0,s - m % k)<<endl;
        else
        {
            if(m%(2*k) < k)
            {
                cout<<s - m % k<<endl;
            }
            else
            {
                cout<<k - m % k<<endl;
            }
        }
    }
}