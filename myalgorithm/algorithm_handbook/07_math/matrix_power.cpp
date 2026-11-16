// 矩阵快速幂：把固定线性递推转化为矩阵乘法，适合求很远的第 n 项。
// d 阶方阵乘法 O(d^3)，快速幂 O(d^3 log n)，临时空间 O(d^2)。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007;

// a,b 必须是相同阶数的方阵，元素已规范到 [0,MOD)。
matrix mul(const matrix&a,const matrix&b)
{
    int n = (int)a.size();
    matrix c(n,vector<ll>(n,0));
    for(int i = 0;i<n;i++)
        for(int k = 0;k<n;k++)
            for(int j = 0;j<n;j++)
                // 每次加法后取模，避免累积多个乘积导致 ll 溢出。
                c[i][j] = (c[i][j]+a[i][k]*b[k][j])%MOD;
    return c;
}

// b>=0。矩阵乘法不满足交换律，快速幂中必须保留乘法顺序。
matrix quickPower(matrix a,ll b)
{
    int n = (int)a.size();
    matrix ans(n,vector<ll>(n,0));
    // 单位矩阵相当于普通乘法中的 1，保证零次幂也正确。
    for(int i = 0;i<n;i++)ans[i][i] = 1;
    while(b)
    {
        if(b&1)ans = mul(ans,a);
        a = mul(a,a);
        b >>= 1;
    }
    return ans;
}

// [F(n+1),F(n)]^T = [[1,1],[1,0]]^n * [1,0]^T。
// F(0)=0，F(1)=1；取结果矩阵 [1][0] 即可得到 F(n)。
ll fibonacci(ll n)
{
    matrix a = {{1,1},{1,0}};
    return quickPower(a,n)[1][0];
}

// 输入 n>=0，例如 10 输出 55，0 输出 0；结果对 MOD 取模。
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    if(!(cin>>n)||n<0)return 0;
    cout<<fibonacci(n)<<'\n';
    return 0;
}
