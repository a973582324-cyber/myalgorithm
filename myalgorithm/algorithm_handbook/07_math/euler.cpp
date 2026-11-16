// 欧拉函数 phi(n)：1..n 中与 n 互质的整数个数，约定 phi(1)=1。
// 公式：phi(n)=n * 连乘(1-1/p)，其中 p 遍历 n 的不同质因数。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 试除法求单个欧拉函数，n>=1，时间 O(sqrt(n))，额外空间 O(1)。
ll getPhi(ll n)
{
    ll ans = n;
    for(ll i = 2;i<=n/i;i++)
    {
        if(n%i!=0)continue;
        // 先除后乘，避免中间乘积溢出；每种质因数只贡献一次。
        ans = ans/i*(i-1);
        while(n%i==0)n /= i;
    }
    if(n>1)ans = ans/n*(n-1);
    return ans;
}

// 线性筛求 phi[1..n]；n>=1，时间和空间均为 O(n)。
vector<int> getPhiTable(int n)
{
    vector<int>phi(n+1),prime;
    vector<bool>v(n+1,false);
    phi[1] = 1;
    for(int i = 2;i<=n;i++)
    {
        if(!v[i])
        {
            prime.push_back(i);
            phi[i] = i-1;
        }
        for(int p:prime)
        {
            if(p * i > n)break;
            v[i*p] = true;
            if(i%p==0)
            {
                // p 已经是 i 的质因数，只提高它的指数。
                phi[i*p] = phi[i]*p;
                break;
            }
            // p 是新增质因数，phi(i*p)=phi(i)*(p-1)。
            phi[i*p] = phi[i]*(p-1);
        }
    }
    return phi;
}

// 输入 10；输出 4，以及 phi[1..10]：1 1 2 2 4 2 6 4 6 4。
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)||n<1||n>1000000)return 0;
    cout<<getPhi(n)<<'\n';
    vector<int>phi = getPhiTable(n);
    for(int i = 1;i<=n;i++)cout<<phi[i]<<(i==n?'\n':' ');
    return 0;
}
