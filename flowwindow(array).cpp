#include<iostream>
using namespace std;
#define N 1000005
long long a[N];
long long q[N];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int h = 1,t = 0;
    for(int i = 1;i<=n;i++){
        while(h<=t && a[q[t]]>=a[i])t--;
        q[++t] = i;
        if(q[h]<i-k+1)h++;
        if(i>=k)
        cout<<a[q[h]]<<' ';
    }
    cout<<endl;
    h=1,t=0;
    for(int i = 1;i<=n;i++){
        while(h<=t && a[q[t]]<=a[i])t--;
        q[++t] = i;
        if(q[h]<i-k+1)h++;
        if(i>=k)
        cout<<a[q[h]]<<' ';
    }
}
//单调队列：队尾进队出队，队头出队（维护子序列单调性）
//队尾出队条件：队列不空且新元素更优，队中旧元素队尾出队
//每个元素必然进队一次
//队头出队条件：队头元素滑出窗口
//注：队列中存储元素的下标 