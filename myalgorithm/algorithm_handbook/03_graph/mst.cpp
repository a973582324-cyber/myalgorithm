// Kruskal：无向图，顶点 1..n，边权可为负。不连通返回 nullopt。
// 会原地排序 edges，时间以排序 O(m log(m+1)) 为主，额外空间 O(n)。
// 累计权值需能用 ll 表示。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge { int u, v; ll w; };

optional<ll> kruskal(int n, vector<Edge>& edges)
{
    if (n == 1) return 0;
    vector<int> parent(n + 1), size(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    });
    ll total = 0;
    int used = 0;
    for (auto [u, v, w] : edges)
    {
        u = find(u);
        v = find(v);
        if (u == v) continue;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        total += w;
        if (++used == n - 1) return total;
    }
    return nullopt;
}

int main() { return 0; }
