#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
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
        int n;
        cin>>n;
        vector<int>cnt(n+1);
        int num;
        for(int i = 0;i<n;i++)
        {
            cin>>num;
            cnt[num]++;
        }
        if(cnt[0] == 0)cout<<"no"<<endl;
        else if(cnt[1] > 0)cout<<"yes"<<endl;
        else
        {
            if(cnt[0] == 1)
            {
                cout<<"yes"<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}