#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int v[105];
    int w[105];
    int num[105];
    int dp[105]={0};
    dp[0]=0;
    for(int i=0;i<n;i++)
        cin>>v[i]>>w[i]>>num[i];
    for(int i=0;i<n;i++){
        for(int j=m;j>=v[i];j--)
            for(int k=0;k<=num[i]&&k*v[i]<=j;k++)
                dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
    }
    cout<<dp[m]<<endl;
}