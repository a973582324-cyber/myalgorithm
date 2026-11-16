// 网格多源 BFS：所有起点同时入队，可得到每个格子到最近起点的距离。
// 每个可达格子至多入队一次，时间和空间复杂度都是 O(n*m)。
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

int fx[4] = {1,-1,0,0};
int fy[4] = {0,0,1,-1};

//网格多源BFS，墙用#表示，距离无法到达时为-1
vector<vector<int>> bfs(vector<string>&map,vector<PII>&starts)
{
    int n = map.size(),m = map[0].size();
    vector<vector<int>>distance(n,vector<int>(m,-1));
    queue<PII>q;
    for(auto start:starts)
    {
        distance[start.first][start.second] = 0;
        q.push(start);
    }
    while(q.size())
    {
        auto now = q.front();q.pop();
        int x = now.first,y = now.second;
        for(int i = 0;i<4;i++)
        {
            int nx = x+fx[i],ny = y+fy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(map[nx][ny]=='#'||distance[nx][ny]!=-1)continue;
            distance[nx][ny] = distance[x][y]+1;
            q.push({nx,ny});
        }
    }
    return distance;
}

int main()
{
    return 0;
}
