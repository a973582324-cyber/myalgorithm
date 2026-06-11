#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int INF = 0x3f3f3f3f;

// 打印当前状态行的辅助函数
void printState(int step, string u_str, const vector<bool>& visited, const vector<int>& dist, int n) {
    cout << setw(6) << step << " | " << setw(6) << u_str << " | ";
    
    // 打印已确定集合 S
    string s_str = "{";
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            if (s_str.length() > 1) s_str += ",";
            s_str += (char)('a' + i);
        }
    }
    s_str += "}";
    cout << setw(18) << left << s_str << " | ";

    // 打印各个顶点的当前距离 dist
    for (int i = 1; i < n; i++) { // 从 b 到 g 打印
        if (dist[i] == INF) {
            cout << setw(6) << "∞";
        } else {
            cout << setw(6) << dist[i];
        }
    }
    cout << "\n";
}

void dijkstra(const vector<vector<int>>& graph, int n, int src) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    // 初始状态
    dist[src] = 0;
    
    cout << "========================================= Dijkstra 算法执行状态表 =========================================\n";
    cout << setw(6) << "步骤" << " | " << setw(6) << "选定u" << " | " << setw(18) << left << "已确定集合 S" << " | ";
    for (int i = 1; i < n; i++) {
        cout << setw(4) << (char)('a' + i) << "   ";
    }
    cout << "\n-----------------------------------------------------------------------------------------------------------\n";

    // 打印初始状态（未选任何点，但 src 已初始化）
    // 此时从 a 出发更新它的邻接点
    for (int v = 0; v < n; v++) {
        if (graph[src][v] != INF && src != v) {
            dist[v] = graph[src][v];
            parent[v] = src;
        }
    }
    visited[src] = true;
    printState(0, "-", visited, dist, n);

    // 开始迭代
    for (int step = 1; step < n; step++) {
        int u = -1;
        int min_dist = INF;

        // 寻找当前未访问的距离最小的顶点
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        // 如果找不到可达的顶点，说明剩下的点不连通
        if (u == -1) break;

        // 标记顶点 u 为已访问
        visited[u] = true;

        // 更新 u 的邻接顶点的距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        // 打印当前步骤的状态
        string u_str = "";
        u_str += (char)('a' + u);
        printState(step, u_str, visited, dist, n);
    }

    cout << "-----------------------------------------------------------------------------------------------------------\n\n";

    // 打印最终的具体路径
    cout << "==== 各顶点的最短路径及距离结果 ====\n";
    for (int i = 1; i < n; i++) {
        cout << "到顶点 " << (char)('a' + i) << " : ";
        if (dist[i] == INF) {
            cout << "不可达\n";
        } else {
            cout << "最短距离 = " << setw(2) << dist[i] << " | 路径: ";
            // 回溯路径
            vector<char> path;
            int curr = i;
            while (curr != -1) {
                path.push_back((char)('a' + curr));
                curr = parent[curr];
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                if (j > 0) cout << " -> ";
            }
            cout << "\n";
        }
    }
}

int main() {
    // 顶点映射：a->0, b->1, c->2, d->3, e->4, f->5, g->6
    int n = 7; 
    vector<vector<int>> graph(n, vector<int>(n, INF));
    
    for (int i = 0; i < n; i++) graph[i][i] = 0;

    // 录入有向图的边和权重
    graph[0][1] = 15; // a -> b
    graph[0][2] = 2;  // a -> c
    graph[0][3] = 12; // a -> d
    graph[1][4] = 6;  // b -> e
    graph[2][4] = 8;  // c -> e
    graph[2][5] = 4;  // c -> f
    graph[3][6] = 3;  // d -> g
    graph[4][6] = 9;  // e -> g
    graph[5][3] = 5;  // f -> d
    graph[5][6] = 10; // f -> g
    graph[6][1] = 4;  // g -> b

    // 运行源点为 'a' (0) 的 Dijkstra 算法
    dijkstra(graph, n, 0);

    return 0;
}