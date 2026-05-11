#include<iostream>
#include<cstring>
using namespace std;
int aa[205];
int bb[205];
int ans=1e9;
int n,a,b;
void dfs(int x,int step){
    bb[x]=step;
    int xx=x-aa[x];
    if(xx>=1&&step+1<bb[xx])
        dfs(xx,step+1);
    xx=x+aa[x];
    if(xx<=n&&step+1<bb[xx])
        dfs(xx,step+1);
    return;
}
int main(){
    cin>>n>>a>>b;
    memset(bb,0x3f,sizeof(bb));
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }
    dfs(a,0);
    cout<<bb[b]<<endl;    
}