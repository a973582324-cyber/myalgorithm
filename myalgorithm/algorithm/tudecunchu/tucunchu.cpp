//邻接矩阵：w[i][j]表示从i到j的边权，INF表示无穷大
//邻接表：出边数组e[u][i]存储u点的所有出变得终点v和权重w，不能处理反向边
//边集数组：edges数组存储所有边的信息，通常包含起点、终点和权重
//链式前向星：head[i]表示以i为起点的边的链表头结点，edge数组存储边的信息，next数组存储链表的下一个节点，适用于稀疏图
//链式邻接表：h[u][i]存储u点的所有出边的编号（编号！），e[j]存储第j条边的信息;可以处理反向边
#include<bits/stdc++.h>
using namespace std;
struct edge{int v,w;};
vector<edge>e[1005];
int n,m;
//邻接表的遍历和存储
void dfs(int u,int fa)
{
    for(auto [v,w]:e[u])
    {
        if(v==fa)continue;
        printf("%d %d %d\n",u,v,w);
        dfs(v,u);
    }
}
//
int main()
{
    cin>>n>>m;
    int a,b,c;
    for(int i = 1;i<=m;i++)
    {
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    dfs(1,0);
    return 0;
}