// P1175 表达式的转换 —— 表达式树实现
// 用二叉树表示表达式：叶子是数字，内部节点是运算符
// 后序遍历树 = 后缀表达式
#include <bits/stdc++.h>
using namespace std;

// ============ 表达式树节点 ============
struct Node {
    char op;         // 运算符，0 表示是数字叶子
    int val;         // 数字的值（op==0 时有效）
    Node *l, *r;     // 左右子树

    Node(char _op, int _val = 0) : op(_op), val(_val), l(nullptr), r(nullptr) {}
    Node(int _val) : op(0), val(_val), l(nullptr), r(nullptr) {}

    bool isLeaf() { return op == 0; }
};

// ========== 1. 运算符优先级 ==========
int prio(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ========== 2. 中缀 → 后缀 ==========
vector<string> infix2postfix(const string &s) {
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
        } else {  // 运算符
            while (!st.empty() && st.top() != '(') {
                if (c == '^' && st.top() == '^') break;     // ^ 右结合
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

// ========== 3. 从后缀表达式建表达式树 ==========
// 栈中存放节点指针
//   数字 → new 叶子节点，入栈
//   运算符 → 弹出右孩子、左孩子，new 内部节点，入栈
Node* buildTree(const vector<string> &post) {
    stack<Node*> st;
    for (const string &s : post) {
        if (isdigit(s[0])) {
            st.push(new Node(s[0] - '0'));        // 叶子节点
        } else {
            Node *node = new Node(s[0]);           // 运算符节点
            node->r = st.top(); st.pop();          // 注意：先弹出的是右孩子
            node->l = st.top(); st.pop();          // 后弹出的是左孩子
            st.push(node);
        }
    }
    return st.top();   // 最后栈顶就是树根
}

// ========== 4. 后序遍历：输出后缀表达式 ==========
void postorder(Node *root, vector<string> &out) {
    if (!root) return;
    postorder(root->l, out);
    postorder(root->r, out);
    if (root->isLeaf())
        out.push_back(to_string(root->val));
    else
        out.push_back(string(1, root->op));
}

// 打印树当前对应的后缀表达式
void printTree(Node *root) {
    vector<string> v;
    postorder(root, v);
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

// ========== 5. 计算两数运算 ==========
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

// ========== 6. 在树上做一步归约 ==========
// 后序遍历，找到第一个"左右子树都是叶子"的运算符节点，计算它并替换成一个数字叶子
// 返回 true 表示做了归约，false 表示整棵树已经是一个数字（计算完毕）
bool reduceStep(Node *root) {
    if (!root || root->isLeaf()) return false;

    // 后序遍历：先左后右再根
    if (reduceStep(root->l)) return true;
    if (reduceStep(root->r)) return true;

    // 当前节点是运算符，且左右都是叶子 → 可以归约
    if (!root->isLeaf() && root->l->isLeaf() && root->r->isLeaf()) {
        int a = root->l->val;
        int b = root->r->val;
        int res = calc(a, b, root->op);

        // 释放旧的子节点
        delete root->l;
        delete root->r;

        // 当前节点变成数字叶子
        root->op = 0;
        root->val = res;
        root->l = root->r = nullptr;

        return true;   // 只做一步就返回
    }
    return false;
}

// ========== 7. 主函数 ==========
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // ① 中缀 → 后缀
    vector<string> post = infix2postfix(s);

    // ② 建表达式树
    Node *root = buildTree(post);

    // ③ 输出后缀表达式（后序遍历）
    printTree(root);

    // ④ 逐步归约，每步输出
    while (reduceStep(root)) {
        printTree(root);
    }

    return 0;
}