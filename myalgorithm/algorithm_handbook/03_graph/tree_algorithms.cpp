// 倍增 LCA：输入是一棵连通无向树，顶点 1..n。0 表示没有祖先。
// BFS 预处理，避免链形树递归过深；构建 O(n log n)，查询 O(log n)。
#include <bits/stdc++.h>
using namespace std;

struct LCA
{
    vector<int> depth;
    vector<vector<int>> up; // up[j][u]：u 的第 2^j 级祖先。

    LCA(const vector<vector<int>>& tree, int root)
    {
        int n = static_cast<int>(tree.size()) - 1;
        int levels = 1;
        while ((1LL << levels) <= n) ++levels;
        depth.assign(n + 1, -1);
        up.assign(levels, vector<int>(n + 1, 0));

        queue<int> q;
        depth[root] = 0;
        q.push(root);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : tree[u])
            {
                if (depth[v] != -1) continue;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                q.push(v);
            }
        }
        for (int j = 1; j < levels; ++j)
            for (int u = 1; u <= n; ++u)
                up[j][u] = up[j - 1][up[j - 1][u]];
    }

    // 要求 k >= 0；超出根时返回 0。
    int ancestor(int u, int k) const
    {
        if (k > depth[u]) return 0;
        for (int j = 0; k > 0; ++j, k >>= 1)
            if (k & 1) u = up[j][u];
        return u;
    }

    int lca(int u, int v) const
    {
        if (depth[u] < depth[v]) swap(u, v);
        u = ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int j = static_cast<int>(up.size()) - 1; j >= 0; --j)
        {
            if (up[j][u] == up[j][v]) continue;
            u = up[j][u];
            v = up[j][v];
        }
        return up[0][u];
    }
};

int main() { return 0; }
