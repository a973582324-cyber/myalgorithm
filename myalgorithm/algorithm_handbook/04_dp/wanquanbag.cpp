// 完全背包：每件物品可选任意次。dp[j] 是总容量不超过 j 的最大价值。
// 输入 n, capacity，随后 n 行「体积 价值」；体积必须为正。
// 容量正序：dp[j-volume] 已经允许使用当前物品，所以能再取一件。
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
        for (int j = volume; j <= capacity; ++j)
            dp[j] = max(dp[j], dp[j - volume] + value);
    }
    cout << dp[capacity] << '\n';
}
