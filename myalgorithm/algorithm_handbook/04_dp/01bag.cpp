// 01 背包：dp[j] 是总容量不超过 j 时的最大价值，允许不选。
// 输入 n, capacity，随后 n 行「体积 价值」；体积为正。
// 容量倒序：dp[j-volume] 还是处理当前物品之前的值。
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
        int volume;
        ll value;
        cin >> volume >> value;
        for (int j = capacity; j >= volume; --j)
            dp[j] = max(dp[j], dp[j - volume] + value);
    }
    cout << dp[capacity] << '\n';
}
