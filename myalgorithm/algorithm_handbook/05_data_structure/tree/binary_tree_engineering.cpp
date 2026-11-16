/**
 * 二叉树 —— 工程代码写法
 *
 * 和你之前的竞赛写法对比着看，核心区别：
 *   1. 没有全局变量 — 所有状态封装在类内部
 *   2. 构造/析构自动管理内存 — 不会泄漏
 *   3. public/private 控制访问 — 不暴露内部细节
 *   4. 接口清晰 — 外部只需知道"建树"和"遍历"
 */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class BinaryTree {
private:
    // ============= 节点定义（内部使用，外部不需要知道）=============
    struct Node {
        char data;
        Node* left;
        Node* right;

        Node(char ch) : data(ch), left(nullptr), right(nullptr) {}
    };

    Node* root;          // 树根，唯一暴露状态的入口
    int nodeCount;       // 节点个数（附加功能）

public:
    // ==================== 构造与析构 ====================
    BinaryTree() : root(nullptr), nodeCount(0) {}

    ~BinaryTree() {
        destroy(root);   // RAII：对象销毁时自动释放所有节点
    }

    // ==================== 建树（公有接口）====================
    // 从前序序列建树（# 表示空节点）
    // 用户只需要传字符串，不需要管 index 之类的东西
    void buildFromPreorder(const string& str) {
        int index = 0;               // 局部变量，不是全局变量！
        root = buildRecursive(str, index);
    }

    // 从层序序列建树（# 表示空节点）— 非递归，用队列
    void buildFromLevelOrder(const string& str) {
        if (str.empty() || str[0] == '#') {
            root = nullptr;
            return;
        }

        root = new Node(str[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;                   // 局部变量！

        while (!q.empty() && i < (int)str.size()) {
            Node* cur = q.front();
            q.pop();

            // 左孩子
            if (i < (int)str.size() && str[i] != '#') {
                cur->left = new Node(str[i]);
                q.push(cur->left);
            }
            i++;

            // 右孩子
            if (i < (int)str.size() && str[i] != '#') {
                cur->right = new Node(str[i]);
                q.push(cur->right);
            }
            i++;
        }
    }

    // ==================== 四种遍历（公有接口）====================
    void preorder() {
        cout << "前序遍历: ";
        preorderRecursive(root);
        cout << endl;
    }

    void inorder() {
        cout << "中序遍历: ";
        inorderRecursive(root);
        cout << endl;
    }

    void postorder() {
        cout << "后序遍历: ";
        postorderRecursive(root);
        cout << endl;
    }

    void levelOrder() {
        cout << "层序遍历: ";
        if (root == nullptr) {
            cout << "(空树)" << endl;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            cout << cur->data << ' ';
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }

    // ==================== 其他查询 ====================
    int size() const{
        return nodeCount;
    }

    int height() {
        return heightRecursive(root);
    }

    int leafCount() {
        return leafCountRecursive(root);
    }

private:
    // ==================== 私有辅助函数（外部不可见）====================

    // 递归建树
    Node* buildRecursive(const string& str, int& index) {
        if (index >= (int)str.size()) return nullptr;

        char ch = str[index++];
        if (ch == '#') return nullptr;

        Node* node = new Node(ch);
        nodeCount++;
        node->left  = buildRecursive(str, index);
        node->right = buildRecursive(str, index);
        return node;
    }

    // 递归销毁所有节点（后序遍历思路：先删孩子，再删自己）
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    // 四种遍历的递归实现
    void preorderRecursive(Node* node) {
        if (node == nullptr) return;
        cout << node->data << ' ';       // 根
        preorderRecursive(node->left);   // 左
        preorderRecursive(node->right);  // 右
    }

    void inorderRecursive(Node* node) {
        if (node == nullptr) return;
        inorderRecursive(node->left);    // 左
        cout << node->data << ' ';       // 根
        inorderRecursive(node->right);   // 右
    }

    void postorderRecursive(Node* node) {
        if (node == nullptr) return;
        postorderRecursive(node->left);   // 左
        postorderRecursive(node->right);  // 右
        cout << node->data << ' ';        // 根
    }

    int heightRecursive(Node* node) {
        if (node == nullptr) return 0;
        int leftH  = heightRecursive(node->left);
        int rightH = heightRecursive(node->right);
        return max(leftH, rightH) + 1;
    }

    int leafCountRecursive(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return leafCountRecursive(node->left) + leafCountRecursive(node->right);
    }
};

// ==================== 测试 ====================
int main() {
    // 前序序列：# 代表空节点（和你的竞赛代码一样的格式）
    string preorderStr = "ABDH#K###E##CFI###G#J##";

    BinaryTree tree;
    tree.buildFromPreorder(preorderStr);

    // 四种遍历
    tree.preorder();     // 前序: A B D H K E C F I G J
    tree.inorder();      // 中序: H K D B E A I F C G J
    tree.postorder();    // 后序: K H D E B I F J G C A
    tree.levelOrder();   // 层序: A B C D E F G H I J K

    cout << "节点总数: " << tree.size() << endl;
    cout << "树的高度: " << tree.height() << endl;
    cout << "叶子数量: " << tree.leafCount() << endl;

    return 0;
}
