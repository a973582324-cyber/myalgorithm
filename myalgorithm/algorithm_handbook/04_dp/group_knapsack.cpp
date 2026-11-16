// 每组最多选一个物品，pair 是 {体积, 价值}，允许体积为 0。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll groupKnapsack(int capacity, const vector<vector<pair<int, int>>>& groups)
{
    vector<ll> dp(capacity + 1, 0);
    for (const auto& group : groups)
    {
        for (int j = capacity; j >= 0; --j)
        {
            // 先算出本组最优值再写回。这样 volume==0 时也只读到旧 dp[j]。
            ll best = dp[j];
            for (auto [volume, value] : group)
                if (j >= volume)
                    best = max(best, dp[j - volume] + value);
            dp[j] = best;
        }
    }
    return dp[capacity];
}

int main() { return 0; }
