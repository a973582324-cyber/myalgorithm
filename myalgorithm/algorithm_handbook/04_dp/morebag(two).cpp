// 多重背包二进制拆分：每个拆出的物品组做一次 01 背包。
// 输入 n, capacity，随后 n 行「体积 价值 数量」；体积为正。
// 先把数量截到 capacity/volume。时间 O(capacity * sum(log(count+1)))，空间 O(capacity)。
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
        count = min(count, capacity / volume);
        for (ll block = 1; count > 0; block *= 2)
        {
            int take = static_cast<int>(min<ll>(block, count));
            count -= take;
            int totalVolume = take * volume;
            ll totalValue = take * value;
            for (int j = capacity; j >= totalVolume; --j)
                dp[j] = max(dp[j], dp[j - totalVolume] + totalValue);
        }
    }
    cout << dp[capacity] << '\n';
}
