#include<iostream>
using namespace std;
const int MOD = 1e9+7;
int dp[10005];
int main(){
    int a[1005];
    int n,m;
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 0;i < n;i++)
    cin >> a[i];
    for(int i = 0;i < n;i++){
        for(int j=a[i];j<=m;j++){
            dp[j]=dp[j]+dp[j-a[i]];
            dp[j]%=MOD;
        }
    }
    cout<<dp[m];
}