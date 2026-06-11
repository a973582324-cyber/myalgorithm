#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

// ==================== 1. 数据结构定义 ====================

// 边结构体，用于 Kruskal 算法
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 邻接表节点
struct AdjListNode {
    int to;
    int weight;
};

// 并查集（Disjoint Set Union），用于 Kruskal 算法的判环
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // 路径压缩
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

// ==================== 2. 核心算法实现 ====================
// 修正后的 Prim 算法（基于邻接矩阵）
void prim(const vector<vector<int>>& graph, int n) {
    vector<int> lowcost(n, INF); 
    vector<int> parent(n, -1);   
    vector<bool> visited(n, false);

    lowcost[0] = 0;
    int total_weight = 0;

    cout << "--- Prim 算法生成的边顺序 ---\n";

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_val = INF;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && lowcost[j] < min_val) {
                min_val = lowcost[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;
        total_weight += min_val;

        // 【修正处】修复了字符拼接与括号错误，确保清晰打印
        if (parent[u] != -1) {
            char from_node = (char)('a' + parent[u]);
            char to_node = (char)('a' + u);
            cout << "(" << from_node << ", " << to_node << ") 权重: " << min_val << "\n";
        }

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] < lowcost[v]) {
                lowcost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    cout << "Prim 最小生成树总权重: " << total_weight << "\n\n";
}

// Kruskal 算法（基于边集/邻接表转换）
void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 按权重从小到大排序
    DSU dsu(n);
    
    int total_weight = 0;
    int edge_count = 0;

    cout << "--- Kruskal 算法生成的边顺序 ---\n";

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            cout << "(" << (char)('a' + edge.u) << ", " << (char)('a' + edge.v) 
                 << ") 权重: " << edge.weight << "\n";
            total_weight += edge.weight;
            edge_count++;
            if (edge_count == n - 1) break; // 边数达到 n-1 条时退出
        }
    }
    cout << "Kruskal 最小生成树总权重: " << total_weight << "\n";
}

// ==================== 3. 主函数与图的初始化 ====================

int main() {
    // 顶点映射：a->0, b->1, c->2, d->3, e->4, f->5, g->6, h->7
    int n = 8; 

    // ---- (1) 初始化并打印邻接矩阵 ----
    vector<vector<int>> adjMatrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) adjMatrix[i][i] = 0;

    // 添加无向边和权重
    auto addEdgeMatrix = [&](char u, char v, int w) {
        int idx1 = u - 'a';
        int idx2 = v - 'a';
        adjMatrix[idx1][idx2] = w;
        adjMatrix[idx2][idx1] = w;
    };

    addEdgeMatrix('a', 'b', 4); addEdgeMatrix('a', 'c', 3);
    addEdgeMatrix('b', 'c', 5); addEdgeMatrix('b', 'd', 5); addEdgeMatrix('b', 'e', 9);
    addEdgeMatrix('c', 'd', 5); addEdgeMatrix('c', 'h', 5);
    addEdgeMatrix('d', 'e', 7); addEdgeMatrix('d', 'f', 6); addEdgeMatrix('d', 'g', 5); addEdgeMatrix('d', 'h', 4);
    addEdgeMatrix('e', 'f', 3);
    addEdgeMatrix('f', 'g', 2);
    addEdgeMatrix('g', 'h', 6);

    cout << "==== 邻接矩阵 ====\n  ";
    for(int i=0; i<n; i++) cout << (char)('a'+i) << "   ";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << (char)('a' + i) << " ";
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == INF) cout << "∞  ";
            else cout << adjMatrix[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    // 执行 Prim 算法
    prim(adjMatrix, n);

    // ---- (2) 初始化并打印邻接表 ----
    vector<vector<AdjListNode>> adjList(n);
    vector<Edge> edgeList; // 专门用于 Kruskal 的边集

    auto addEdgeList = [&](char u, char v, int w) {
        int idx1 = u - 'a';
        int idx2 = v - 'a';
        adjList[idx1].push_back({idx2, w});
        adjList[idx2].push_back({idx1, w});
        edgeList.push_back({idx1, idx2, w}); // 保存单向边即可用于 Kruskal
    };

    addEdgeList('a', 'b', 4); addEdgeList('a', 'c', 3);
    addEdgeList('b', 'c', 5); addEdgeList('b', 'd', 5); addEdgeList('b', 'e', 9);
    addEdgeList('c', 'd', 5); addEdgeList('c', 'h', 5);
    addEdgeList('d', 'e', 7); addEdgeList('d', 'f', 6); addEdgeList('d', 'g', 5); addEdgeList('d', 'h', 4);
    addEdgeList('e', 'f', 3);
    addEdgeList('f', 'g', 2);
    addEdgeList('g', 'h', 6);

    cout << "==== 邻接表 ====\n";
    for (int i = 0; i < n; i++) {
        cout << (char)('a' + i);
        for (const auto& node : adjList[i]) {
            cout << " -> [" << (char)('a' + node.to) << ", " << node.weight << "]";
        }
        cout << "\n";
    }
    cout << "\n";

    // 执行 Kruskal 算法
    kruskal(n, edgeList);

    return 0;
}