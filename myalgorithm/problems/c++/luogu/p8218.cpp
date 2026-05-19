#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int>a(n+1),b(n+1,0);
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        b[i] = b[i-1] + a[i];
    }
    cin>>m;
    int l,r;
    for(int i = 0;i<m;i++)
    {
        cin>>l>>r;
        cout<<b[r]-b[l-1]<<endl;
    }
}