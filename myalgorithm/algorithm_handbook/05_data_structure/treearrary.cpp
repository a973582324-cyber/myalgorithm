// 树状数组：单点加、前缀和、闭区间求和，每次 O(log n)，空间 O(n)。
// 数据从 1 开始编号，query(0) 表示空前缀。累计值需能用 ll 表示。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick
{
    int n;
    vector<ll> tree;

    explicit Fenwick(int n) : n(n), tree(n + 1, 0) {}

    static int lowbit(int x) { return x & -x; }

    void change(int x, ll delta)
    {
        assert(1 <= x && x <= n);
        for (; x > 0 && x <= n; x += lowbit(x))
            tree[x] += delta;
    }

    ll query(int x) const
    {
        assert(0 <= x && x <= n);
        ll sum = 0;
        for (; x > 0; x -= lowbit(x))
            sum += tree[x];
        return sum;
    }

    ll rangeSum(int l, int r) const
    {
        assert(1 <= l && l <= r && r <= n);
        return query(r) - query(l - 1);
    }
};
