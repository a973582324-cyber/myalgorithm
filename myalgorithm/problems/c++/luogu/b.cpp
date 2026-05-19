#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
ll n,x1,x2,k;
void solve()
{
    cin>>n>>x1>>x2>>k;
    ll q = min(abs(x2-x1),n-abs(x2-x1));
    if(k==0)
    {
        cout<<q<<endl;
        return;
    }
    ll d = n / 2;
        if(q == d)
            cout << q + max(0LL, k - 1) << '\n';
        else
            cout << q + k << '\n';
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