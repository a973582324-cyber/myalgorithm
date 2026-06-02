#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_calls = n; // 初始化为一个足够大的值，最多不会超过 n 次

    // 枚举每一个朋友所在的位置作为最终的集合点 target
    for (int i = 0; i < n; ++i) {
        int target = a[i];
        int left_count = 0;  // 记录在 target 左边的人数
        int right_count = 0; // 记录在 target 右边的人数

        for (int j = 0; j < n; ++j) {
            if (a[j] < target) {
                left_count++;
            } else if (a[j] > target) {
                right_count++;
            }
        }

        // 以当前 target 为集合点所需的最小通话次数为 max(left_count, right_count)
        int current_calls = max(left_count, right_count);
        min_calls = min(min_calls, current_calls);
    }

    cout << min_calls << "\n";
}

int main() {
    // 优化标准输入输出流以提高执行速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}