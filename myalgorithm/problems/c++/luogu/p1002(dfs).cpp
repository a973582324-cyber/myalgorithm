#include<iostream>
using namespace std;
int n,m,x,y;
int fx[2]={1,0};
int fy[2]={0,1};
int a[25][25]={0};
int ans=0;
void dfs(int x1,int y1){
    if(x1==n&&y1==m){
        ans++;
        return;
    }
    for(int i=0;i<2;i++){
        x1+=fx[i];y1+=fy[i];
        if(x1>n||y1>m||a[x1][y1]==1){
            x1-=fx[i];y1-=fy[i];
            continue;
        }
        dfs(x1,y1)  ;
        x1-=fx[i];
        y1-=fy[i];
    }
}
int main(){
    cin>>n>>m>>x>>y;
    a[x][y]=1;
    if(x-1>=0&&y-2>=0)a[x-1][y-2]=1;
    if(x-1>=0&&y+2<=m)a[x-1][y+2]=1;
    if(x+1<=n&&y-2>=0)a[x+1][y-2]=1;
    if(x+1<=n&&y+2<=m)a[x+1][y+2]=1;
    if(x+2<=n&&y-1>=0)a[x+2][y-1]=1;
    if(x+2<=n&&y+1<=m)a[x+2][y+1]=1;
    if(x-2>=0&&y-1>=0)a[x-2][y-1]=1;
    if(x-2>=0&&y+1<=m)a[x-2][y+1]=1;
    dfs(0,0);
    cout<<ans<<endl;
}