// 并查集：路径压缩配合集合大小合并，单次操作的均摊复杂度接近 O(1)。
// 节点编号采用 [1,n]，调用 find 或 unite 前必须先 init。
#include<iostream>
#include<vector>
using namespace std;

vector<int>father;
vector<int>setSize;

void init(int n)
{
    father.resize(n+1);
    setSize.assign(n+1,1);
    for(int i = 1;i<=n;i++)father[i] = i;
}

//路径压缩查找根节点
int find(int x)
{
    if(father[x]==x)return x;
    return father[x] = find(father[x]);
}

//按集合大小合并，返回false说明已经在同一集合
bool unite(int x,int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if(rootX==rootY)return false;

    if(setSize[rootX]<setSize[rootY])swap(rootX,rootY);
    father[rootY] = rootX;
    setSize[rootX] += setSize[rootY];
    return true;
}   

int main()
{
    return 0;
}
