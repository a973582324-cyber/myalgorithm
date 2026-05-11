#include<iostream>
using namespace std;
int main(){
    int dp[1005];
    int n,m;
    cin>>n>>m;
    int v[1005];int w[1005];
    for(int i=0;i<n;i++)
    cin>>v[i]>>w[i];
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=m;j++)
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    }
    cout<<dp[m];
}