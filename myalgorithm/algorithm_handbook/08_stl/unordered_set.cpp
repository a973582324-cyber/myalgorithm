// unordered_set 保存不重复元素，平均插入、查找和删除复杂度为 O(1)。
// 遍历顺序不稳定，不能依赖输出顺序表达大小关系或插入顺序。
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int>a;
    a.insert(1);
    for(auto b :a )
    cout<<b<<endl;
    a.erase(1);
    cout<<a.empty();
}
