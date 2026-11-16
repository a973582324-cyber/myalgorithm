// 组合数 C(n,k)：从 n 个不同元素中选 k 个，不考虑顺序。
// 阶乘逆元法适合固定质数模数下的多次查询；必须满足 0<=n<MOD。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
vector<ll>fact,invFact;

ll quickPower(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans = ans*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return ans;
}

// fact[i]=i!，invFact[i] 为 i! 的模逆元。
// 时间 O(n+log MOD)，空间 O(n)，重复调用会重新初始化。
void init(int n)
{
    fact.assign(n+1,1);
    invFact.assign(n+1,1);
    for(int i = 1;i<=n;i++)fact[i] = fact[i-1]*i%MOD;
    invFact[n] = quickPower(fact[n],MOD-2);
    // 由 i!=i*(i-1)!，得到 invFact[i-1]=invFact[i]*i。
    for(int i = n;i>=1;i--)invFact[i-1] = invFact[i]*i%MOD;
}

// 查询 O(1)，要求 n 不超过已预处理的范围；非法 k 返回 0。
ll combination(int n,int k)
{
    if(k<0||k>n)return 0;
    return fact[n]*invFact[k]%MOD*invFact[n-k]%MOD;
}

// 输入 n k；例如 5 2 输出 10，0 0 输出 1。
// 学习示例限制 n<=10^6 控制内存；多次查询时对最大的 n 初始化一次即可。
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    if(!(cin>>n>>k)||n<0||n>1000000)return 0;
    init(n);
    cout<<combination(n,k)<<'\n';
    return 0;
}
