// 前缀和负责静态区间查询，差分数组负责批量区间修改。
// 两种模板都采用 1-based 下标，调用 add 时 difference 需要预留 r+1。
// 前缀和负责静态区间查询，差分数组负责批量区间修改。
// 两种模板都采用 1-based 下标，调用 add 时 difference 需要预留 r+1。
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

// 前缀和负责静态区间查询，差分数组负责批量区间修改。
// 两种模板都采用 1-based 下标，调用 add 时 difference 需要预留 r+1。

//一维前缀和，下标从1开始
vector<ll> getPrefix(vector<ll>&a)
{
    int n = a.size()-1;
    vector<ll>prefix(n+1,0);
    for(int i = 1;i<=n;i++)
        prefix[i] = prefix[i-1]+a[i];
    return prefix;
}

//查询区间[l,r]的和
ll query(vector<ll>&prefix,int l,int r)
{
    return prefix[r]-prefix[l-1];
}

//一维差分区间加
void add(vector<ll>&difference,int l,int r,ll value)
{
    difference[l] += value;
    difference[r+1] -= value;
}

int main()
{
    return 0;
}
