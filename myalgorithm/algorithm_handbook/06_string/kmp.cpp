// KMP 的 next[0]=-1 写法；日常比赛推荐 kmp1.cpp 的前缀函数写法。
#include <bits/stdc++.h>
using namespace std;

// 非空模式串；返回所有匹配的 1-based 起点，包括重叠匹配。
vector<int> kmp(const string& text, const string& pattern)
{
    int n = static_cast<int>(text.size()), m = static_cast<int>(pattern.size());
    if (m == 0) return {};
    vector<int> next(m + 1, -1), positions;
    for (int i = 0, j = -1; i < m;)
    {
        while (j >= 0 && pattern[i] != pattern[j]) j = next[j];
        next[++i] = ++j;
    }
    for (int i = 0, j = 0; i < n;)
    {
        while (j >= 0 && text[i] != pattern[j]) j = next[j];
        ++i;
        ++j;
        if (j == m)
        {
            positions.push_back(i - m + 1);
            j = next[j];
        }
    }
    return positions;
}

int main()
{
    // 预期为 1 2 3。
    for (int pos : kmp("aaaaa", "aaa")) cout << pos << ' ';
    cout << '\n';
}
