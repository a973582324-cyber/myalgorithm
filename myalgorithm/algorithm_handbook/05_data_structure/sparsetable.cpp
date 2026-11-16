// ST 表：静态区间最大值，数组和查询都从 1 开始，区间为闭区间。
// 构建 O(n log n)，查询 O(1)。可将 max 换成 min/gcd；不能用重叠区间做求和。
#include <bits/stdc++.h>
using namespace std;

struct SparseTable
{
    vector<int> log2Floor;
    vector<vector<int>> st; // st[k][i]：从 i 开始，长度为 2^k 的区间最大值。

    explicit SparseTable(const vector<int>& a)
    {
        int n = static_cast<int>(a.size()) - 1; // a[0] 不使用，n >= 1。
        log2Floor.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            log2Floor[i] = log2Floor[i / 2] + 1;
        st.resize(log2Floor[n] + 1);
        st[0] = a;
        for (int k = 1; k <= log2Floor[n]; ++k)
        {
            int half = 1 << (k - 1);
            int count = n - (1 << k) + 1;
            st[k].resize(count + 1);
            for (int i = 1; i <= count; ++i)
                st[k][i] = max(st[k - 1][i], st[k - 1][i + half]);
        }
    }

    int query(int l, int r) const
    {
        int k = log2Floor[r - l + 1];
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SparseTable st(a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}
