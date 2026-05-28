#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> paths;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int dist = 0;
        while (true) {
            paths.push_back({x, dist});
            if (x == 1) {
                paths.push_back({2, dist + 1});
                break;
            }
            if (x == 2) {
                paths.push_back({1, dist + 1});
                break;
            }
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x += 1;
            }
            dist++;
        }
    }
    sort(paths.begin(), paths.end());
    int min_ = 2e9; 
    int current = paths[0].first;
    int count = 0;
    int sum = 0;
    
    for (int i = 0; i < paths.size(); i++) {
        if (paths[i].first == current) {
            count++;
            sum += paths[i].second;
        } else {

            if (count == n) {
                min_ = min(min_, sum);
            }
            current = paths[i].first;
            count = 1;
            sum = paths[i].second;
        }
    }
    if (count == n) {
        min_ = min(min_, sum);
    }

    cout << min_ << "\n";
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