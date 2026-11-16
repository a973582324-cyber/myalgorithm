// 朴素 Dijkstra：有向图，顶点 1..n，边权非负。时间 O(n^2 + m)。
// 输入 n m s，随后 m 行 u v w；输出各点距离（不可达为 -1）。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();

struct Edge { int v; ll w; };

vector<ll> dijkstra(const vector<vector<Edge>>& graph, int s)
{
    int n = static_cast<int>(graph.size()) - 1;
    vector<ll> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dist[s] = 0;
    for (int i = 0; i < n; ++i)
    {
        int u = 0; // 0 是哨兵点，距离恒为 INF。
        for (int v = 1; v <= n; ++v)
            if (!visited[v] && dist[v] < dist[u]) u = v;
        if (u == 0) break;
        visited[u] = true;
        for (auto [v, w] : graph[u])
            if (w < dist[v] - dist[u])
                dist[v] = dist[u] + w;
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    auto dist = dijkstra(graph, s);
    for (int i = 1; i <= n; ++i)
        cout << (dist[i] == INF ? -1 : dist[i]) << (i == n ? '\n' : ' ');
}
