//利用单调队列求连续子序列的最大和
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define N 1000005
long long a[N];
long long b[N];
long long q[N];
int main(){
    int n,k;
    cin >> n >> k;
    long long max_=0;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    b[0]=0;
    for(int i = 1;i <= n;i++)
        b[i] = b[i-1] + a[i];
    int h = 0,t = 0;
    for(int i = 1;i <= n;i++){
        if(q[h] < i-k)h++;
        max_= max (max_ , b[i] - b[q[h]]);
        while(h <= t && b[i] <= b[q[t]])t--;
        q[++t] = i;
    }
    cout << max_ << endl;
}
//单调队列：队尾进队出队，队头出队（维护子序列单调性）
//队尾出队条件：队列不空且新元素更优，队中旧元素队尾出队
//每个元素必然进队一次
//队头出队条件：队头元素滑出窗口
//注：队列中存储元素的下标 