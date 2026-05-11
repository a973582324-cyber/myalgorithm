#include<iostream>
using namespace std;
int ans=0,n;int a[10000][15];int c[11];
void dfs(int x,int m){
    if(x>10){
    if(m==n){
        ans++;
        for(int i=1;i<=10;i++){
            a[ans][i]=c[i];
         }
    }
            return;

    }
    for(int i=1;i<=3;i++){
        if(m+i>n)
            break;
        c[x]=i;
        dfs(x+1,m+i);
        c[x]=0;
    }
}
int main(){
    cin>>n;
    if(n>=10&&n<=30)
        dfs(1,0);
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        for(int j=1;j<=10;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}