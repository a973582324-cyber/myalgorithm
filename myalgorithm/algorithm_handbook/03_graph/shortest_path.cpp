// Bellman-Ford 处理可达负环检测，Floyd 处理任意两点最短路。
// 两个模板都用 INF 表示不可达，节点编号采用 [1,n]。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct edge{int u,v;ll w;};

//Bellman-Ford，返回false说明存在从起点可达的负环
bool bellmanFord(int n,int start,vector<edge>&edges,vector<ll>&distance)
{
    distance.assign(n+1,INF);
    distance[start] = 0;
    for(int i = 1;i<=n;i++)
    {
        bool changed = false;
        for(auto e:edges)
        {
            if(distance[e.u]==INF)continue;
            if(distance[e.v]>distance[e.u]+e.w)
            {
                distance[e.v] = distance[e.u]+e.w;
                changed = true;
                if(i==n)return false;
            }
        }
        if(!changed)break;
    }
    return true;
}

//Floyd求任意两点最短路，时间复杂度O(n^3)
void floyd(int n,vector<vector<ll>>&distance)
{
    for(int k = 1;k<=n;k++)
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                if(distance[i][k]!=INF&&distance[k][j]!=INF)
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
}

int main(){return 0;}
