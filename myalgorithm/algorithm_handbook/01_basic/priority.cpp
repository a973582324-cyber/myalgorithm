/**
 * 堆的底层实现 —— 数组模拟完全二叉树
 *
 * 核心公式（下标从 1 开始）：
 *   父 = i / 2      左孩子 = i * 2      右孩子 = i * 2 + 1
 *
 * 两个核心操作足以实现全部功能：
 *   siftDown(i)：节点 i 和它的两个孩子比较，不满足堆性质就下沉
 *   siftUp(i)：  节点 i 和父节点比较，不满足堆性质就上浮
 */

#include <iostream>
using namespace std;

const int N = 10000;
int heap[N];     // 堆数组，下标从 1 开始
int len;         // 堆的当前大小

// ===================== 向下调整（堆的核心）=====================
// 假设 i 的左右子树都已经是大根堆，把 i 下沉到正确位置
void siftDown(int i) {
    while (i * 2 <= len) {                    // 只要有左孩子
        int child = i * 2;                    // 先假定左孩子更大
        if (child + 1 <= len && heap[child + 1] > heap[child])
            child = child + 1;                // 右孩子更大就选右孩子
        if (heap[i] >= heap[child]) break;    // 满足大根堆性质，停
        swap(heap[i], heap[child]);
        i = child;                            // 继续向下
    }
}

// ===================== 向上调整（插入时用）=====================
void siftUp(int i) {
    while (i > 1 && heap[i] > heap[i / 2]) {  // 比父节点大就上浮
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// ===================== 三个基本操作 =====================

// 1. 插入
void push(int x) {
    heap[++len] = x;      // 放到末尾
    siftUp(len);          // 向上调整
}

// 2. 取堆顶
int top() {
    return heap[1];
}

// 3. 删除堆顶
void pop() {
    heap[1] = heap[len--];  // 末尾元素覆盖堆顶
    siftDown(1);            // 向下调整
}

// ===================== O(n) 建堆（Floyd 法）=====================
// 从最后一个非叶节点开始，依次向下调整
void buildHeap(int a[], int n) {
    len = n;
    for (int i = 1; i <= n; i++) heap[i] = a[i];
    for (int i = n / 2; i >= 1; i--) siftDown(i);
}

// ===================== 堆排序 =====================
// 大根堆 → 升序：每次把堆顶（最大）换到末尾，len--，再 siftDown
void heapSort(int a[], int n) {
    buildHeap(a, n);                           // 先建大根堆
    for (int i = n; i >= 2; i--) {
        swap(heap[1], heap[i]);                // 堆顶（最大）放到末尾
        len--;                                  // 堆缩小
        siftDown(1);                           // 重新调整
    }
    // 此时 heap[1..n] 就是升序排列
}

// ===================== 测试 =====================
int main() {
    // ===== 建堆 =====
    int a[] = {0, 3, 1, 4, 1, 5, 9, 2, 6};    // a[0] 占位不用
    int n = 8;
    buildHeap(a, n);

    cout << "大根堆数组: ";
    for (int i = 1; i <= len; i++) cout << heap[i] << " ";
    cout << "\n堆顶: " << top() << endl;
    cout << endl;

    // ===== 逐个弹出堆顶（降序）=====
    cout << "依次弹出堆顶（降序）: ";
    while (len > 0) {
        cout << top() << " ";
        pop();
    }
    cout << endl << endl;

    // ===== 堆排序（升序）=====
    int b[] = {0, 3, 1, 4, 1, 5, 9, 2, 6};
    heapSort(b, 8);
    cout << "堆排序结果（升序）: ";
    for (int i = 1; i <= 8; i++) cout << heap[i] << " ";
    cout << endl;

    return 0;
}
