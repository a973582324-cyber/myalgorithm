#include<iostream>
#include<algorithm>
using namespace std;
#define N 10000
int v[N],w[N];
int dp[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>v[i]>>w[i];
    /*
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j>=v[i])
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][m]<<endl;
    二维存储*/
    //一维存储
    int f[N];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j<v[i])
            f[j]=f[j];
            else
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
}