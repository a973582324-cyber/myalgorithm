// 顺序队列：有效数据位于半开区间 [left,right)。
// 尾部空间耗尽时，resort 把未出队元素整体前移；push/pop 用 bool 表示成功与否。
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define ElemType int

struct queueData
{
    ElemType data[MAXSIZE];
    int left;
    int right;
};

void initQueue(queueData* q)
{
    q->left = 0;
    q->right = 0;
}

//把未出队的数据搬到数组开头，腾出后面的空间
bool resort(queueData* q)
{
    if(q->left==0)return false;
    for(int i = q->left;i<q->right;i++)
        q->data[i-q->left] = q->data[i];
    q->right -= q->left;
    q->left = 0;
    return true;
}

bool push(queueData* q,ElemType value)
{
    if(q->right==MAXSIZE&&!resort(q))return false;
    q->data[q->right++] = value;
    return true;
}

bool pop(queueData* q,ElemType& value)
{
    if(q->left==q->right)return false;
    value = q->data[q->left++];
    return true;
}

int main()
{
    queueData q;
    initQueue(&q);
    return 0;
}
