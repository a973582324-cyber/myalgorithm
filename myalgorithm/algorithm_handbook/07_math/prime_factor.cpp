// 试除法分解质因数，并求正约数的个数与列表。
// 约定：1 <= n <= 10^12，使用 ll；更大的素数输入会使试除法较慢。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 返回 {质因数,指数}，如 12 = 2^2 * 3，返回 {{2,2},{3,1}}。
// 时间 O(sqrt(n))，返回值空间 O(log n)；1 的质因数列表为空。
vector<pair<ll,int>> getFactor(ll n)
{
    vector<pair<ll,int>>a;
    // 用 i<=n/i 代替 i*i<=n，避免平方溢出。
    for(ll i = 2;i<=n/i;i++)
    {
        if(n%i!=0)continue;
        int cnt = 0;
        while(n%i==0)
        {
            n /= i;
            cnt++;
        }
        a.push_back({i,cnt});
    }
    // 除完所有小质因数后，剩余的大于 1 的数一定是质数。
    if(n>1)a.push_back({n,1});
    return a;
}

// 每个质因数的指数可选 0..cnt，因此约数个数是所有 (cnt+1) 的乘积。
ll countDivisor(ll n)
{
    ll ans = 1;
    for(auto [p,cnt]:getFactor(n))ans *= cnt+1;
    return ans;
}

// 成对枚举 i 与 n/i，完全平方数的平方根只加入一次。
// 设约数个数为 d，时间 O(sqrt(n)+d log d)，空间 O(d)。
vector<ll> getDivisor(ll n)
{
    vector<ll>a;
    for(ll i = 1;i<=n/i;i++)
    {
        if(n%i!=0)continue;
        a.push_back(i);
        if(i!=n/i)a.push_back(n/i);
    }
    sort(a.begin(),a.end());
    return a;
}

// 输入 12；输出质因数、约数个数、所有正约数。
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    if(!(cin>>n)||n<1||n>1000000000000LL)return 0;
    for(auto [p,cnt]:getFactor(n))cout<<p<<'^'<<cnt<<' ';
    cout<<'\n'<<countDivisor(n)<<'\n';
    for(ll x:getDivisor(n))cout<<x<<' ';
    cout<<'\n';
    return 0;
}
