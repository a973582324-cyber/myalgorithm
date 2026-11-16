// 堆优化 Prim：无向图，顶点 1..n，边权可为负。
// graph[u] 中存 {相邻点, 边权}，每条无向边要存两个方向。
// 不连通返回 nullopt；时间 O(n + m log(m+1))。总权值需能用 ll 表示。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

optional<ll> prim(const vector<vector<pair<int, ll>>>& graph)
{
    int n = static_cast<int>(graph.size()) - 1; // n >= 1
    vector<bool> visited(n + 1, false);
    using State = pair<ll, int>; // {边权, 点}
    priority_queue<State, vector<State>, greater<State>> q;
    q.push({0, 1});
    ll total = 0;
    int count = 0;
    while (!q.empty())
    {
        auto [w, u] = q.top();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total += w;
        if (++count == n) return total;

        for (auto [v, weight] : graph[u])
            if (!visited[v]) q.push({weight, v});
    }
    return nullopt;
}

int main() { return 0; }
