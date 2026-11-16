// 二分答案：先证明判定函数单调，再找真假分界。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ok(x) 先假后真。返回第一个真；[lo, hi] 都为假时返回 nullopt。
template<class Predicate>
optional<ll> firstTrue(ll lo, ll hi, Predicate ok)
{
    if (lo > hi || !ok(hi)) return nullopt;
    while (lo < hi)
    {
        ll mid = lo + static_cast<ll>((static_cast<__int128>(hi) - lo) / 2);
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// ok(x) 先真后假。返回最后一个真；[lo, hi] 都为假时返回 nullopt。
template<class Predicate>
optional<ll> lastTrue(ll lo, ll hi, Predicate ok)
{
    if (lo > hi || !ok(lo)) return nullopt;
    while (lo < hi)
    {
        // 取上中位，保证 lo 与 hi 相邻时 lo=mid 仍能推进。
        ll mid = static_cast<ll>(lo + (static_cast<__int128>(hi) - lo + 1) / 2);
        if (ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 例：切割高度升高，得到的木材只会减少，因此找最后一个可行高度。
    int n;
    ll need;
    if (!(cin >> n >> need)) return 0;
    vector<int> height(n);
    for (int& h : height) cin >> h;

    auto ok = [&](ll cut)
    {
        ll remaining = need;
        for (int h : height)
        {
            if (h > cut) remaining -= h - cut;
            if (remaining <= 0) return true;
        }
        return remaining <= 0;
    };
    auto answer = lastTrue(0, *max_element(height.begin(), height.end()), ok); // n >= 1
    cout << answer.value_or(-1) << '\n';
}
