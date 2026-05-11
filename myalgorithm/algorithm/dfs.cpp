#include<bits/stdc++.h>
using namespace std;
const int MAX = 505;
int a[MAX][MAX];
int fx[4] = {0,0,1,-1};
int fy[4] = {1,-1,0,0};
int n;
void dfs(int x,int y)
{
    a[x][y] = 3;//对当前点变性，表示当前点会被淹没
    for(int i = 0;i<4;i++)
    {
        int nx = x + fx[i],ny = y + fy[i];//枚举的下一个点的坐标
        if(nx < 1||nx > n||ny < 1||ny > n)continue;//越界不搜
        if(a[nx][ny]==1||a[nx][ny]==3)continue;//如果被淹没则不搜素
        dfs(nx,ny);//继续搜索下一个点
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    char c;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)
        {
           cin>>a[i][j];
        }
    }
    for(int i = 1 ;i<=n;i++)//搜第一列和最后一列
    {
        if(a[i][1]==0)dfs(i,1);
        if(a[i][n]==0)dfs(i,n);
    }
    for(int i = 1;i<=n;i++)//搜第一行和最后一行
    {
        if(a[1][i]==0)dfs(1,i);
        if(a[n][i]==0)dfs(n,i);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)
        {
            if(a[i][j] == 0)
            a[i][j] = 2;
            if(a[i][j] == 3)
            a[i][j] = 0;
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}