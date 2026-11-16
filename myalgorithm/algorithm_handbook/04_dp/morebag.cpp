// 多重背包朴素版：第 i 种物品最多取 count 次。
// 输入 n, capacity，随后 n 行「体积 价值 数量」；体积为正。
// dp[j] 是总容量不超过 j 的最大价值；用于小数据或给优化版做对拍。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, capacity;
    if (!(cin >> n >> capacity)) return 0;
    vector<ll> dp(capacity + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int volume, count;
        ll value;
        cin >> volume >> value >> count;
        for (int j = capacity; j >= volume; --j)
            for (int k = 1; k <= min(count, j / volume); ++k)
                dp[j] = max(dp[j], dp[j - k * volume] + k * value);
    }
    cout << dp[capacity] << '\n';
}
