#include <iostream>
using namespace std;

// =============================================
// 堆排序 (Heap Sort) — 大顶堆，升序排列
// 使用 1-based 下标（0号位置暂存/哨兵）
// =============================================

// 调整以 root 为根的子树为大顶堆
// arr[0] 用于暂存，实际数据从 arr[1] 开始
void heapify(int arr[], int n, int root) {
    arr[0] = arr[root];        // 暂存根节点 (arr[0] 作哨兵)
    int i = root;
    int j = 2 * i;             // 左孩子 (1-based)

    while (j <= n) {
        // 如果右孩子更大，选右孩子
        if (j < n && arr[j] < arr[j + 1])
            j++;
        // 如果孩子不大于根，停止
        if (arr[0] >= arr[j])
            break;
        // 孩子上移
        arr[i] = arr[j];
        i = j;
        j = 2 * i;             // 继续向下
    }
    arr[i] = arr[0];           // 根落到最终位置
}

// 堆排序主函数
// arr[1..n] 存数据，arr[0] 用作哨兵
void heapSort(int arr[], int n) {
    // 第1步：建堆 — 从最后一个非叶节点 n/2 开始，自下而上
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);

    // 第2步：排序 — 反复交换堆顶(1)和末尾(i)
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);      // 堆顶(最大值)扔到末尾
        heapify(arr, i - 1, 1);    // 对前 i-1 个元素重新调整
    }
}

void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 打印堆的树形结构
void printTree(int arr[], int n) {
    if (n < 1) return;
    cout << "         " << arr[1] << endl;
    if (n >= 2) cout << "      /    \\" << endl;
    if (n >= 3) cout << "    " << arr[2] << "        " << arr[3] << endl;
    if (n >= 4) cout << "   /  \\    /  \\" << endl;
    if (n >= 7) cout << " " << arr[4] << "   " << arr[5] << "  " << arr[6] << "   " << arr[7];
    if (n >= 8) {
        cout << endl << "/ \\  / \\";
        cout << endl << arr[8] << " " << arr[9] << " " << arr[10] << " " << arr[11];
    }
    if (n >= 12) {
        cout << " " << arr[12];
    }
    cout << endl;
}

int main() {
    // 原始数据 (共12个)
    int raw[] = {83, 40, 63, 13, 84, 35, 96, 57, 39, 79, 61, 15};
    int n = sizeof(raw) / sizeof(raw[0]);

    // arr[0] 用作哨兵，arr[1..n] 存数据
    // 多开一个位置，索引 0 不用
    int arr[20] = {0};  // 足够大
    for (int i = 0; i < n; i++)
        arr[i + 1] = raw[i];   // 搬到 1-based

    cout << "初始序列 (1-based): ";
    printArray(arr, n);

    // 建堆
    cout << "\n建堆过程 (自下而上):" << endl;
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
        cout << "  调整 " << i << " 号节点后: ";
        printArray(arr, n);
    }

    cout << "\n建好的大顶堆 (树形):" << endl;
    printTree(arr, n);
    cout << "数组形式: ";
    printArray(arr, n);

    // 逐趟排序
    cout << "\n排序过程:" << endl;
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
        cout << "第" << n - i + 1 << "趟 (交换" << arr[i] << "到末尾, 调整剩余" << i-1 << "个): ";
        for (int k = 1; k <= n; k++) {
            if (k == i) cout << "| ";  // 已排序区分界线
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "\n最终结果: ";
    printArray(arr, n);

    return 0;
}
