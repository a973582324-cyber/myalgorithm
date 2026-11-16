// 堆优化 Dijkstra：有向图，顶点 1..n，边权非负。
// 输入 n m s，随后 m 行 u v w；输出各点距离（不可达为 -1）。
// 懒删除堆最多存 O(m) 条记录，时间 O(n + m log(m+1))。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();

struct Edge { int v; ll w; };

vector<ll> dijkstra(const vector<vector<Edge>>& graph, int s)
{
    vector<ll> dist(graph.size(), INF);
    using State = pair<ll, int>;
    priority_queue<State, vector<State>, greater<State>> q;
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (d != dist[u]) continue; // 这条堆记录已被更短的距离替代。
        for (auto [v, w] : graph[u])
        {
            // 可表示的有限距离必须小于 INF；先比较再相加。
            if (w < dist[v] - d)
            {
                dist[v] = d + w;
                q.push({dist[v], v});
            }
        }
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
