// P1175 表达式的转换 —— 栈模拟后缀求值（边扫描边输出）
// 思路：扫描后缀表达式，数字入栈，遇运算符弹出两个计算出结果再入栈
//       每算完一步，输出【栈内(底→顶) + 剩余后缀】就是当前状态
#include <bits/stdc++.h>
using namespace std;

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
    vector<string> post = toPost(s);

    // -------- 先输出完整的后缀表达式 --------
    for (int i = 0; i < (int)post.size(); i++) {
        if (i) cout << ' ';
        cout << post[i];
    }
    cout << '\n';

    // -------- 用栈模拟后缀求值，逐步输出 --------
    stack<string> st;               // 栈中存的是"已求值部分"的字符串
    int i = 0;                      // 指向还没读的后缀位置

    while (i < (int)post.size()) {
        string &cur = post[i];

        if (isdigit(cur[0])) {
            // 数字直接入栈，继续往后读
            st.push(cur);
            i++;
        } else {
            // 遇到运算符：弹出栈顶两个数来计算
            string b_str = st.top(); st.pop();
            string a_str = st.top(); st.pop();

            int a = stoi(a_str), b = stoi(b_str);
            int res = calc(a, b, cur[0]);

            st.push(to_string(res));   // 结果入栈
            i++;                       // 运算符也消耗掉了

            // --- 输出当前状态：栈(底→顶) + 剩余后缀 ---
            // 因为 stack 只能从顶访问，先倒到 vector 里再正序输出
            vector<string> stackContent;
            stack<string> tmp = st;
            while (!tmp.empty()) {
                stackContent.push_back(tmp.top());
                tmp.pop();
            }
            reverse(stackContent.begin(), stackContent.end());

            // 输出栈内容
            for (int j = 0; j < (int)stackContent.size(); j++) {
                if (j) cout << ' ';
                cout << stackContent[j];
            }
            // 输出剩余后缀
            for (int j = i; j < (int)post.size(); j++) {
                cout << ' ' << post[j];
            }
            cout << '\n';
        }
    }

    return 0;
}
