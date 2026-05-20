#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;

    // 3个一组的最优单价
    ll cost3 = min(b, 3 * a);
    // 剩下 0/1/2 个的最优单价
    ll cost1 = a;
    ll cost2 = min(2 * a, b);

    // 先尽可能多买 3 个一组
    ans += (n / 3) * cost3;
    ll rem = n % 3;

    // 处理余数
    if (rem == 1) ans += min(cost1, b);  // 剩1个：买1个 或 硬买3个
    if (rem == 2) ans += cost2;          // 剩2个：买2个 或 硬买3个

    cout << ans << endl;
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