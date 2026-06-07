#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
//本题从后到前维护一个单调递减栈（下标），到一个位置将该位置元素与栈顶元素作比较
//如果大于栈顶元素则出栈，小于先更新答案再入栈
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>a(n);
    vector<int>q(n);
    vector<int>ans(n);
    for(int i = 0;i<n;i++)
        cin>>a[i];
    int t = 0;
    for(int i = n-1;i>=0;i--)
    {
        while(t>0&&a[i]>=a[q[t]])t--;
        if(t==0)ans[i] = 0;
        else
            ans[i] = q[t];
        q[++t] = i;
    }
    for(auto t:ans)
    {
        cout<<(t==0?0:t+1)<<' ';
    }
    return 0;
}