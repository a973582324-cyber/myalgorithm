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
bool cmp(int x,int y)
{
    return x > y;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    if(n<=2)
    {
        cout<<a[0]<<' '<<a[1]<<endl;
        return;
    }
    int aa = a[0],bb = a[1];
    for(int i = 2;i<n;i++)
    {
        int t = aa % bb;
        if(t!=a[i])
        {
            cout<<-1<<endl;
            return;
        }
        aa = a[i-1];
        bb = a[i];
    }
    cout<<a[0]<<' '<<a[1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    } 
}