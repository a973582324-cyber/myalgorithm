// 汉诺塔递归：先移动上方 n-1 个盘，再移动最大盘，最后搬回 n-1 个盘。
// 共执行 2^n-1 次移动，递归栈深度为 O(n)。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 三根柱子
vector<int> A, B, C;

void PrintState()
{
    cout << "A: [";
    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i];
        if (i < A.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "B: [";
    for (size_t i = 0; i < B.size(); i++)
    {
        cout << B[i];
        if (i < B.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "C: [";
    for (size_t i = 0; i < C.size(); i++)
    {
        cout << C[i];
        if (i < C.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "---" << endl;
}

void Hanoi(int n, vector<int>& from, vector<int>& to, vector<int>& via)
{
    if (n == 1)
    {
        // 把 from 最上面的盘子移到 to
        int disk = from.back();
        from.pop_back();
        to.push_back(disk);
        PrintState();
        return;
    }

    Hanoi(n - 1, from, via, to);   // 上面 n-1 个移到中转柱
    Hanoi(1, from, to, via);        // 最大的移到目标柱
    Hanoi(n - 1, via, to, from);   // n-1 个从中转柱移到目标柱
}

int main()
{
    // 初始化：3 最大在底，1 最小在顶
    A = { 3, 2, 1 };

    PrintState();
    Hanoi(3, A, C, B);

    return 0;
}
