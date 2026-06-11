#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // ans[l] 存储当第 l 个容器为空时的最大总水量
    vector<long long> ans(n, 0);

    // 依次假设每个容器 l 为空
    for (int l = 0; l < n; l++) {
        vector<long long> maxR(n, 0);
        vector<long long> maxL(n, 0);

        // 1. 顺时针（向右）传播路径上的最大隔板高度
        long long current_max = 0;
        for (int step = 1; step < n; step++) {
            int curr = (l + step) % n;
            int prev = (l + step - 1 + n) % n; // 越过的上一个隔板
            current_max = max(current_max, h[prev]);
            maxR[curr] = current_max;
        }

        // 2. 逆时针（向左）传播路径上的最大隔板高度
        current_max = 0;
        for (int step = 1; step < n; step++) {
            int curr = (l - step + n) % n;
            int edge = curr; // 连接 curr 和 (curr+1)%n 的隔板是 h[curr]
            current_max = max(current_max, h[edge]);
            maxL[curr] = current_max;
        }

        // 3. 计算当前 l 情况下的总水量之和
        long long total_volume = 0;
        for (int i = 0; i < n; i++) {
            if (i != l) {
                total_volume += min(maxR[i], maxL[i]);
            }
        }
        ans[l] = total_volume;
    }

    // 输出当前测试用例的答案
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}