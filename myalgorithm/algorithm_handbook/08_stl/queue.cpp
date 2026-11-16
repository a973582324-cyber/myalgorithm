
// queue 是先进先出容器：push 从队尾加入，pop 从队首删除。
// front/back 只能在队列非空时调用，常用操作的复杂度均为 O(1)。
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
        cout<<q.empty()<<endl;
        cout<<q.size()<<endl;
        cout<<q.front()<<" "<<q.back()<<endl;
    q.pop();
        cout<<q.front()<<endl;

    // priority_queue 默认是大根堆，top() 返回最大值。
    priority_queue<int>maxHeap;
    maxHeap.push(3);
    maxHeap.push(8);
    maxHeap.push(5);
        cout<<maxHeap.empty()<<endl;
        cout<<maxHeap.size()<<endl;
        cout<<maxHeap.top()<<endl;
    maxHeap.pop();
        cout<<maxHeap.top()<<endl;

    // 小根堆需要指定 greater<int>，top() 返回最小值。
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(5);
        cout<<minHeap.top()<<endl;
    minHeap.pop();
        cout<<minHeap.top()<<endl;

    // priority_queue 只能访问堆顶。遍历时通常不断 top() 和 pop()。
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    cout<<endl;
    return 0;
}
