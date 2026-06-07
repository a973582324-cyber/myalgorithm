// P1175 表达式的转换 —— 数组模拟法（更简单的写法）
// 不需要建树，直接用 vector<string> 模拟后缀表达式的逐步归约
#include <bits/stdc++.h>
using namespace std;

// 优先级
int prio(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 中缀 → 后缀
vector<string> toPost(const string &s) {
    vector<string> res;
    stack<char> st;
    for (char c : s) {
        if (isdigit(c)) {
            res.push_back(string(1, c));
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && st.top() != '(') {
                if (c == '^' && st.top() == '^') break;
                if (prio(st.top()) < prio(c)) break;
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res.push_back(string(1, st.top()));
        st.pop();
    }
    return res;
}

// 打印数组
void print(const vector<string> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

// 计算
int calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<string> v = toPost(s);   // ① 转后缀
    print(v);                        // ② 输出后缀

    // ③ 逐步归约：每次找第一个运算符，它前面两个数就是操作数
    while (v.size() > 1) {
        int i = 0;
        while (i < (int)v.size()) {
            if (v[i].size() == 1 && !isdigit(v[i][0])) break;
            i++;
        }
        // v[i] 是运算符，v[i-2] 和 v[i-1] 是操作数
        int b = stoi(v[i - 1]);
        int a = stoi(v[i - 2]);
        int res = calc(a, b, v[i][0]);

        // 用结果替换掉三个元素
        v[i - 2] = to_string(res);
        v.erase(v.begin() + i - 1, v.begin() + i + 1);

        print(v);
    }

    return 0;
}
