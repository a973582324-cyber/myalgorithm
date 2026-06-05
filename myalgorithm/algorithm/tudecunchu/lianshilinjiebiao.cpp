//链式邻接表的存储和遍历
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{int u,v,w;};
vector<edge>e;
vector<int>h[1005];
void add(int a,int b,int c)
{
    e.push_back({a,b,c});//存储出边的信息
    h[a].push_back(e.size()-1);//存储边的编号
}
void dfs(int u,int fa)//遍历以fa为父节点的点u的所有出边
{
    for(int i = 0;i<h[u].size();i++)
    {
        int j = h[u][i];//找到边的编号
        int v = e[j].v,w = e[j].w;
        if(v==fa)continue;
        printf("%d %d %d\n",u,v,w);
        dfs(v,u);
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    return 0;
}