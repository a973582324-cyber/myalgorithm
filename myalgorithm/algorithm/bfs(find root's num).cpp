#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>
int x2,y2;
int ans;
int v[10][10],cnt[10][10]={0};
int fx[8] = {2,2,1,-1,-2,-2,1,-1};
int fy[8] = {-1,1,2,2,1,-1,-2,-2};
void bfs(int x,int y)
{
	queue<PII>q;
	q.push({x,y});
	int temp=0;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int xx = t.first,yy = t.second;
		for(int i = 0;i<8;i++)
		{
			int m = xx+fx[i],n=yy+fy[i];	
			if(m <= 0||n <= 0||m >= 9||n >= 9)
			continue;
			if(v[m][n]==-1)
			{
				q.push({m,n});
				v[m][n]=v[xx][yy]+1;
				cnt[m][n] = cnt[xx][yy];
			}
			else if(v[m][n]==v[xx][yy]+1)
			{
				cnt[m][n]+=cnt[xx][yy];
			}
		}	
	} 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a,b;
	while(cin>>a>>b)
	{
		for(int i = 1;i<=8;i++)
			for(int j = 1;j<=8;j++)
				v[i][j]=-1;
		memset(cnt,-1,sizeof(cnt));
		int x1 =(int)a[1]-'0';
		int y1 =(int)a[0]-'a'+1;
		x2 =(int)b[1]-'0';
		y2 =(int)b[0]-'a'+1;
		ans = 0;
		v[x1][y1]=0;
		cnt[x1][y1]=1;
		bfs(x1,y1); 
		if(a==b)
			v[x2][y2] = 0;
		printf("To get from %c%c to %c%c takes %d knight moves.\n",a[0],a[1],b[0],b[1],v[x2][y2]);
	}
}
