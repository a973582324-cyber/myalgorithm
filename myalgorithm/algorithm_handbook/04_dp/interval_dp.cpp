// 石子合并型区间 DP：dp[left][right] 表示合并该闭区间的最小代价。
// 前缀和 O(1) 求区间重量，总时间 O(n^3)，空间 O(n^2)。
// 石子合并型区间 DP：dp[left][right] 表示合并该闭区间的最小代价。
// 前缀和 O(1) 求区间重量，总时间 O(n^3)，空间 O(n^2)。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//石子合并型区间DP，数组下标从1开始
ll mergeStone(const vector<int>&a)
{
    if(a.size()<=1)return 0; // 空区间无需合并。
    int n = a.size()-1;
    vector<ll>prefix(n+1,0);
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    for(int i = 1;i<=n;i++)prefix[i] = prefix[i-1]+a[i];

    for(int length = 2;length<=n;length++)
    {
        for(int left = 1;left+length-1<=n;left++)
        {
            int right = left+length-1;
            dp[left][right] = 1e18;
            for(int mid = left;mid<right;mid++)
            {
                ll cost = dp[left][mid]+dp[mid+1][right];
                cost += prefix[right]-prefix[left-1];
                dp[left][right] = min(dp[left][right],cost);
            }
        }
    }
    return dp[1][n];
}

int main(){return 0;}
