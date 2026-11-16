// 后缀表达式求值：每个数字占一个字符，可带空白，支持 + - * / %。
// 先弹右操作数，再弹左操作数。表达式非法、除零或 ll 溢出返回 nullopt。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

optional<ll> eval(const string& expression)
{
    vector<ll> values;
    for (unsigned char ch : expression)
    {
        if (isspace(ch)) continue;
        if ('0' <= ch && ch <= '9')
        {
            values.push_back(ch - '0');
            continue;
        }
        if (values.size() < 2) return nullopt;
        ll right = values.back();
        values.pop_back();
        ll left = values.back();
        values.pop_back();

        // 用 GNU C++17 的 __int128 检查中间结果。
        __int128 a = left, b = right, result;
        if (ch == '+') result = a + b;
        else if (ch == '-') result = a - b;
        else if (ch == '*') result = a * b;
        else if (ch == '/' && b != 0) result = a / b;
        else if (ch == '%' && b != 0) result = a % b;
        else return nullopt;

        if (result < LLONG_MIN || result > LLONG_MAX) return nullopt;
        values.push_back(static_cast<ll>(result));
    }
    if (values.size() != 1) return nullopt;
    return values.back();
}

int main()
{
    string expression;
    if (!getline(cin, expression)) expression = "82/2+56*-";
    if (auto result = eval(expression)) cout << *result << '\n';
    else cout << "INVALID\n";
}
