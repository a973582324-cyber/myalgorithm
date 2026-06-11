#include <iostream>
#include <algorithm>

using namespace std;

// 1. 定义孩子-兄弟链表节点结构
struct CSTreeNode {
    char data;
    CSTreeNode* firstchild;  // 指向第一个孩子
    CSTreeNode* nextsibling; // 指向下一个兄弟

    CSTreeNode(char val) : data(val), firstchild(nullptr), nextsibling(nullptr) {}
};

// 2. 计算树深度的核心算法
int getTreeDepth(CSTreeNode* root) {
    if (root == nullptr) {
        return 0; // 空树深度为 0
    }

    // 递归计算：走孩子路径深度要加 1
    int childDepth = getTreeDepth(root->firstchild) + 1;
    
    // 递归计算：走兄弟路径属于同层，深度不加 1
    int siblingDepth = getTreeDepth(root->nextsibling);

    // 原始树的深度为两者的最大值
    return max(childDepth, siblingDepth);
}