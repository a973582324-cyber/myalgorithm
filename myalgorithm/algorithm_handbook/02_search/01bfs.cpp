// 0-1 BFS：状态是 (格子, 朝向)，向同一方向移动代价 0，换方向代价 1。
// 输入 n m、起终点的 1-based 坐标和网格；'#' 是墙，不可达输出 -1。
// 起步不计转向，起点四种朝向的距离均为 0。时间和空间 O(n*m)。
#include <bits/stdc++.h>
using namespace std;

int minTurns(const vector<string>& grid, int sx, int sy, int tx, int ty)
{
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
    if (grid[sx][sy] == '#' || grid[tx][ty] == '#') return -1;
    const int INF = numeric_limits<int>::max();
    const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    vector<vector<array<int, 4>>> dist(n, vector<array<int, 4>>(m, {INF, INF, INF, INF}));
    struct State { int x, y, dir, cost; };
    deque<State> q;
    for (int dir = 0; dir < 4; ++dir)
    {
        dist[sx][sy][dir] = 0;
        q.push_back({sx, sy, dir, 0});
    }
    while (!q.empty())
    {
        auto [x, y, dir, cost] = q.front();
        q.pop_front();
        if (cost != dist[x][y][dir]) continue;
        if (x == tx && y == ty) return cost;
        for (int nd = 0; nd < 4; ++nd)
        {
            int nx = x + dx[nd], ny = y + dy[nd];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
            int w = (nd != dir);
            if (cost + w >= dist[nx][ny][nd]) continue;
            dist[nx][ny][nd] = cost + w;
            State next{nx, ny, nd, cost + w};
            if (w == 0) q.push_front(next);
            else q.push_back(next);
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, sx, sy, tx, ty;
    if (!(cin >> n >> m >> sx >> sy >> tx >> ty)) return 0;
    vector<string> grid(n, string(m, '.'));
    for (auto& row : grid)
        for (char& cell : row) cin >> cell;
    cout << minTurns(grid, sx - 1, sy - 1, tx - 1, ty - 1) << '\n';
}
