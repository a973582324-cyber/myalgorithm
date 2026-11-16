// 线段树维护区间和，lazy[p] 表示节点 p 覆盖区间尚未下传的统一增量。
// 建树 O(n)，区间加和区间查询均为 O(log n)，tree 需要约 4*n 空间。
// 使用闭区间、1-based 下标，初始化调用 build(1,1,n)，要求 1 <= n < N。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

ll a[N],tree[N*4],lazy[N*4];

void build(int p,int l,int r)
{
    lazy[p] = 0; // 复用这棵树时清除上一次的标记。
    if(l==r){tree[p] = a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p] = tree[p*2]+tree[p*2+1];
}

void pushdown(int p,int l,int r)
{
    if(lazy[p]==0)return;
    int mid = (l+r)/2;
    tree[p*2] += lazy[p]*(mid-l+1);
    tree[p*2+1] += lazy[p]*(r-mid);
    lazy[p*2] += lazy[p];
    lazy[p*2+1] += lazy[p];
    lazy[p] = 0;
}

void change(int p,int l,int r,int x,int y,ll value)
{
    if(x<=l&&r<=y){tree[p] += value*(r-l+1);lazy[p] += value;return;}
    pushdown(p,l,r);
    int mid = (l+r)/2;
    if(x<=mid)change(p*2,l,mid,x,y,value);
    if(y>mid)change(p*2+1,mid+1,r,x,y,value);
    tree[p] = tree[p*2]+tree[p*2+1];
}

ll query(int p,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return tree[p];
    pushdown(p,l,r);
    int mid = (l+r)/2;ll ans = 0;
    if(x<=mid)ans += query(p*2,l,mid,x,y);
    if(y>mid)ans += query(p*2+1,mid+1,r,x,y);
    return ans;
}

int main(){return 0;}
