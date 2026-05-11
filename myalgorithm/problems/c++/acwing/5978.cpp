#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define PII pair<int,int> 
int r,c;
char s[45][45];
int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1};
int ans[45][45]={-1};
int bfs(int x,int y){
    queue<PII>q;
    q.push({x,y});
    ans[x][y]=1;
    while(!q.empty()){
        PII t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
           int xx=t.first+fx[i];
           int yy=t.second+fy[i];
            if(xx<1||xx>r||yy<1||yy>c)continue;
            if(s[xx][yy]=='#')continue;
            if(ans[xx][yy]>1)continue;
            q.push({xx,yy});
            ans[xx][yy]=ans[t.first][t.second]+1;
            if(xx==r&&yy==c)
            return ans[r][c];
        }
    }
    return -1;
}
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>s[i][j];
        }
    }
    int res=bfs(1,1);
    cout<<res<<endl;
}
