//链式前向星
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{int v,w,ne;};//存储第i条出边的信息
edge e[10005];
int h[1005];//存储每个节点第一条出边的编号
int idx;//边的编号
void dfs(int u)
{
    for(int i=h[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].v,w=e[i].w;
        printf("%d %d %d\n",u,v,w);
        dfs(v);
    }
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[idx]={b,c,h[a]};
        h[a]=idx++;
    }
    return 0;
}