// 常用二维序列 DP：最长公共子序列和编辑距离。
// dp[i][j] 都只依赖更短前缀，时间与空间复杂度均为 O(n*m)。
// 常用二维序列 DP：最长公共子序列和编辑距离。
// dp[i][j] 都只依赖更短前缀，时间与空间复杂度均为 O(n*m)。
#include<bits/stdc++.h>
using namespace std;

//最长公共子序列，时间复杂度O(n*m)
int lcs(string a,string b)
{
    int n = a.size(),m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

//编辑距离
int editDistance(string a,string b)
{
    int n = a.size(),m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i = 0;i<=n;i++)dp[i][0] = i;
    for(int j = 0;j<=m;j++)dp[0][j] = j;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            if(a[i-1]==b[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    return dp[n][m];
}

int main(){return 0;}
