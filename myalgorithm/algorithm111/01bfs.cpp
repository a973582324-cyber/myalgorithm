#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII tuple<int,int,int>
char a[5005][5005]={0};
int dist[5005][5005][4];
int fx[4]={1,0,-1,0};
int	fy[4]={0,1,0,-1};
const int INF=1e9;
struct NODE{
	int xx;
	int yy;
	int dd;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++){
			cin>>a[i][j];
			dist[i][j][0] = INF;
			dist[i][j][1] = INF; 
			dist[i][j][2] = INF; 
			dist[i][j][3] = INF;  
		}
	deque<NODE>q;
	for(int i = 0;i<4;i++) {
		dist[sx][sy][i]=0;
		q.push_front({sx,sy,i});
	}
	int w = 0;
	int x,y,d; 
	while(q.size())
	{
		auto t = q.front();
		x = t.xx;y = t.yy;d=t.dd;
		q.pop_front();
		for(int i = 0;i<4;i++)
		{
			int nx = x+fx[i],ny = y+fy[i];
			if(nx>n||ny>m||nx<1||ny<1||a[nx][ny]=='#')continue;
			if(i==d) w = 0;
			else
			w = 1;
			if(dist[nx][ny][i]>dist[x][y][d]+w)
			{
				dist[nx][ny][i] = dist[x][y][d] + w;
				if(w==0)
					q.push_front({nx,ny,i});
				else
					q.push_back({nx,ny,i});
			}
		}			
	}
		int ans = INF;
		for(int i = 0;i<4;i++)
		{  
			ans = min(dist[tx][ty][i],ans);			
		}
		if(ans!=INF)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
}		
