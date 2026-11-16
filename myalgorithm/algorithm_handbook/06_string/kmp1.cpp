// KMP：pi[i] 是 pattern[0..i] 最长相等真前缀与真后缀的长度。
// 输入主串、模式串（均非空）；先输出每个匹配的 1-based 起点，再输出 pi。
// O(n+m) 时间；仅统计或输出时不必额外存储匹配位置。
#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(const string& pattern)
{
    int m = static_cast<int>(pattern.size());
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    if (!(cin >> text >> pattern)) return 0;

    auto pi = prefixFunction(pattern);
    int n = static_cast<int>(text.size()), m = static_cast<int>(pattern.size());
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) ++j;
        if (j == m)
        {
            cout << i - m + 2 << '\n';
            j = pi[j - 1]; // 当前匹配的后缀可能又是下一次匹配的前缀。
        }
    }
    for (int i = 0; i < m; ++i)
        cout << pi[i] << (i + 1 == m ? '\n' : ' ');
}
