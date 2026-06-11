#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> h(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] > h[m]) {
            m = i; 
        }
    }
    vector<long long> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = h[(m + 1 + i) % n];
    }

    vector<long long> L_sum(n, 0);
    vector<long long> f(n - 1, 0);
    stack<int> st;
    for (int k = 0; k < n - 1; k++) {
        while (!st.empty() && b[st.top()] <= b[k]) {
            st.pop();
        }
        long long prev_f = st.empty() ? 0 : f[st.top()];
        int prev_idx = st.empty() ? -1 : st.top();

        f[k] = prev_f + b[k] * (k - prev_idx);
        st.push(k);
        L_sum[k + 1] = f[k];
    }

    vector<long long> R_sum(n, 0);
    vector<long long> g(n - 1, 0);
    while (!st.empty()) st.pop(); 
    for (int k = n - 2; k >= 0; k--) {
        while (!st.empty() && b[st.top()] <= b[k]) {
            st.pop();
        }
        long long next_g = st.empty() ? 0 : g[st.top()];
        int next_idx = st.empty() ? n - 1 : st.top();
        
        g[k] = next_g + b[k] * (next_idx - k);
        st.push(k);
        R_sum[k] = g[k];
    }
    vector<long long> ans(n);
    for (int l = 0; l < n; l++) {
        int orig_idx = (m + 1 + l) % n;
        ans[orig_idx] = L_sum[l] + R_sum[l];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
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