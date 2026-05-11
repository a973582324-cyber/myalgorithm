#include<iostream>
#include<cstring>
using namespace std;
long long dp[10005];
long long a[1005];
const int MOD = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    cin>>a[i];
    dp[0]=1;
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < n;j++)
            if(i-a[j]>=0)
            dp[i]=(dp[i]+dp[i-a[j]])%MOD;
    }   
    cout<<dp[m]%MOD<<endl;
}
