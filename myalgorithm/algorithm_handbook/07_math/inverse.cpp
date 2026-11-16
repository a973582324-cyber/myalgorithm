// 模逆元：求 x 使 a*x 与 1 模 mod 同余。
// 逆元存在当且仅当 gcd(a,mod)=1；模意义下除以 a 相当于乘 a 的逆元。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 本文件约定 2<=mod<=10^9，调用前将 a 规范到 [0,mod)。
ll exgcd(ll a,ll b,ll&x,ll&y)
{
    if(b==0){x = 1;y = 0;return a;}
    ll x1,y1;
    ll d = exgcd(b,a%b,x1,y1);
    // 把 b*x1+(a%b)*y1=d 展开，得到当前层的系数。
    x = y1;
    y = x1-a/b*y1;
    return d;
}

// 扩展欧几里得法：模数不必是质数。不存在时返回 -1，时间 O(log mod)。
ll getInverse(ll a,ll mod)
{
    a = (a%mod+mod)%mod;
    ll x,y;
    if(exgcd(a,mod,x,y)!=1)return -1;
    return (x%mod+mod)%mod;
}

ll quickPower(ll a,ll b,ll mod)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

// 费马小定理法：仅当 mod 是质数且 a 不是 mod 的倍数时成立。
// 调用方保证 mod 为质数，本函数不负责判素；时间 O(log mod)。
ll getInversePrime(ll a,ll mod)
{
    a = (a%mod+mod)%mod;
    if(a==0)return -1;
    return quickPower(a,mod-2,mod);
}

// 输入 a mod；例如 3 11 输出 4，6 9 输出 -1，3 8 输出 3。
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,mod;
    if(!(cin>>a>>mod)||mod<2||mod>1000000000)return 0;
    cout<<getInverse(a,mod)<<'\n';
    return 0;
}
