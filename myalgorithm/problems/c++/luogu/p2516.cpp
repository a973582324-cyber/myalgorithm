#include<iostream>
using namespace std;
long long dp[5005][5005];
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    for(int i=1;i<=x.size()-1;i++){
        for(int j=1;j<=y.size()-1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=(dp[i-1][j-1]+1)%100000000;
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])%100000000;
        }
    }
    cout<<dp[x.size()-1][y.size()-1];
}
//最长公共子序列的长度（求个数我还不会）