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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int num;
    unordered_map<int,int>hs;
    for(int i = 0;i<7;i++)
    {
        cin>>num;
        hs[num] = 1;
    }
    vector<int>ans(8);
    for(int i = 0;i<n;i++)
    {
        int cnt = 0;
        for(int i = 0;i<7;i++)
        {
            cin>>num;
            if(hs[num])
                cnt++;
        }
        ans[cnt]++;
    }
    for(int i = 7;i>0;i--)
    {
        cout<<ans[i]<<(i != 1 ? ' ':'\n');
    }
}