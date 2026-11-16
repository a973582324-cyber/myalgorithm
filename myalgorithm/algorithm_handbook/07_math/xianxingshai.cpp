// 线性筛求 [2,n] 的质数和最小质因数；时间与空间 O(n)。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void linear_sieve(int n, vector<int>& primes, vector<int>& spf)
{
    primes.clear();
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes)
        {
            if (p > spf[i] || 1LL * i * p > n) break;
            spf[i * p] = p;
        }
    }
}

// 分段筛求 [l,r] 的质数。范围：0 <= l <= r <= INT_MAX，区间长度需能放进内存。
vector<int> segmented_sieve(int l, int r)
{
    int limit = static_cast<int>(sqrt(static_cast<long double>(r)));
    while (1LL * (limit + 1) * (limit + 1) <= r) ++limit;
    while (1LL * limit * limit > r) --limit;

    vector<int> primes, spf;
    linear_sieve(limit, primes, spf);
    vector<bool> isPrime(1LL * r - l + 1, true);
    for (int p : primes)
    {
        // 第一项既要落在区间内，也要 >= p*p，否则可能把 p 自己筛掉。
        ll start = max(1LL * p * p, (1LL * l + p - 1) / p * p);
        for (ll x = start; x <= r; x += p) isPrime[x - l] = false;
    }
    vector<int> result;
    for (ll x = max(2, l); x <= r; ++x)
        if (isPrime[x - l]) result.push_back(static_cast<int>(x));
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    if (!(cin >> l >> r)) return 0;
    auto primes = segmented_sieve(l, r);
    for (size_t i = 0; i < primes.size(); ++i)
        cout << (i == 0 ? "" : " ") << primes[i];
    cout << '\n';
}
