#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d;
    int L = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            d.push_back(i);
            L = max(L, a[i] - a[i + 1]);
        }
    }
    if (d.empty()) {
        cout << "YES" << endl;
        return;
    }
    int U = 2e9; 
    for (size_t i = 0; i < d.size() - 1; i++) {
        int l = d[i] + 1;
        int r = d[i + 1];
        if (l >= r) {
            cout << "NO" << endl;
            return;
        }
        int max_ = 0;
        for (int m = l; m < r; m++) {
            max_= max(max_, a[m + 1] - a[m]);
        }
        U = min(U, max_);
    }
    if (L <= U) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}