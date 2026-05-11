#include<iostream>
#include<cstring>
using namespace std;
long long dp[10005];
long long a[1005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<10005;i++)
        dp[i] = 1e9;
    for(int i = 0;i < n;i++)
    cin>>a[i];
    dp[0]=0;
    for(int i = 0;i < n;i++){
        for(int j = a[i];j <= m;j++)
            dp[j]=min(dp[j],dp[j-a[i]]+1);
    }   
    cout<<dp[m]<<endl;
}
