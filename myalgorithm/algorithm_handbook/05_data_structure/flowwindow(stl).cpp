// STL deque 实现滑动窗口最值：队列保存下标，队首始终是当前窗口最优值。
// 第一遍求最小值，第二遍求最大值，总时间 O(n)，额外空间 O(k)。
// STL deque 实现滑动窗口最值：队列保存下标，队首始终是当前窗口最优值。
// 第一遍求最小值，第二遍求最大值，总时间 O(n)，额外空间 O(k)。
#include<iostream>
#include<queue>
using namespace std;
#define N 1000005
long long a[N];
deque<int>dq;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    for(int i = 1;i<=n;i++){
        while(dq.size() && a[i]<=a[dq.back()])dq.pop_back();
        dq.push_back(i);
        if(dq.front() < i-k+1)dq.pop_front();
        if(i>=k)
        cout<<a[dq.front()]<<' ';
    }
    cout<<endl;
    dq.clear();
    for(int i = 1;i<=n;i++){
        while(dq.size() && a[i]>=a[dq.back()])dq.pop_back();
        dq.push_back(i);
        if(dq.front() < i-k+1)dq.pop_front();
        if(i>=k)
        cout<<a[dq.front()]<<' ';
    }
}
//单调队列：队尾进队出队，队头出队（维护子序列单调性）
//队尾出队条件：队列不空且新元素更优，队中旧元素队尾出队
//每个元素必然进队一次
//队头出队条件：队头元素滑出窗口
//注：队列中存储元素的下标
