#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n + 1, 0);
    int min_p = 0;
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + (s[i] == '(' ? 1 : -1);
        min_p = min(min_p, p[i + 1]);
    }
    int R = 0;
    for (int i = 0; i <= n; ++i) {
        if (p[i] == min_p) {
            R = i;
        }
    }
    string ans(n, '0');
    int marked = 0;
    for (int i = 0; i < R && marked < k; ++i) {
        if (s[i] == '(') {
            ans[i] = '1';
            marked++;
        }
    }
    for (int i = R; i < n && marked < k; ++i) {
        if (s[i] == ')') {
            ans[i] = '1';
            marked++;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}