// 数论模板：快速幂、埃氏筛和扩展欧几里得算法。
// quickPower 在 O(log b) 内计算模幂；exgcd 同时求 gcd 与一组贝祖系数。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll quickPower(ll a,ll b,ll mod)
{
    // 要求 b >= 0、mod > 0；用 __int128 避免模乘的中间结果溢出。
    ll ans = 1 % mod;
    a %= mod;
    if(a<0)a += mod;
    while(b)
    {
        if(b&1)ans = static_cast<__int128>(ans) * a % mod;
        a = static_cast<__int128>(a) * a % mod;
        b >>= 1;
    }
    return ans;
}

//埃氏筛，时间复杂度O(n log log n)
vector<int> getPrime(int n)
{
    if(n<2)return {};
    vector<bool>isPrime(n+1,true);
    vector<int>prime;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<=n;i++)
    {
        if(!isPrime[i])continue;
        prime.push_back(i);
        if((ll)i*i>n)continue;
        for(ll j = 1LL * i * i;j<=n;j+=i)isPrime[j] = false;
    }
    return prime;
}

ll exgcd(ll a,ll b,ll&x,ll&y)
{
    if(b==0){x = 1;y = 0;return a;}
    ll x1,y1;
    ll gcd = exgcd(b,a%b,x1,y1);
    x = y1;
    y = x1-a/b*y1;
    return gcd;
}

int main(){return 0;}
