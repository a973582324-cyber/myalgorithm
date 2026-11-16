// Kahn 拓扑排序：有向图，顶点 1..n。有环时返回 nullopt。
// 入度每次重新计算，不修改输入；时间 O(n+m)。
#include <bits/stdc++.h>
using namespace std;

optional<vector<int>> topsort(const vector<vector<int>>& graph)
{
    int n = static_cast<int>(graph.size()) - 1;
    vector<int> indegree(n + 1, 0), order;
    for (int u = 1; u <= n; ++u)
        for (int v : graph[u]) ++indegree[v];
    queue<int> q;
    for (int u = 1; u <= n; ++u)
        if (indegree[u] == 0) q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u])
            if (--indegree[v] == 0) q.push(v);
    }
    if (static_cast<int>(order.size()) != n) return nullopt;
    return order;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0; // n 个点，m 条有向边。
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    auto order = topsort(graph);
    if (!order) cout << "-1\n";
    else
        for (int i = 0; i < n; ++i)
            cout << (*order)[i] << (i + 1 == n ? '\n' : ' ');
}
