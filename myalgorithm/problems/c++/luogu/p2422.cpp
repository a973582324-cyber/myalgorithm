#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>a(n+2),b(n+2),f(n+2);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        b[i] = a[i] + b[i-1];
    }
    n++;
    a[n] = 0,b[n] = b[n-1];
    int t = 0;
    vector<int>q(n+1);
    for(int i = 1;i<=n;i++)
    {
        while(a[q[t]]>a[i])
        {
            f[q[t]] += (b[i-1]-b[q[t]]);
            t--;
        }
        f[i] = b[i] - b[q[t]];
        q[++t] = i;
    }
    ll ans = 0;
    for(int i = 1;i<=n-1;i++)
        ans = max(ans,f[i]*a[i]);
    cout<<ans<<endl;
}
//本质是一个单调栈的问题，维护一个单调递增的栈，每次入栈时，如果当前元素比栈顶元素小，就说明栈顶元素的右边第一个比它小的元素就是当前元素，而它的左边第一个比它小的元素就是栈顶元素下面的元素，所以可以计算出以栈顶元素为高度的矩形面积，并更新答案。最后还要处理一下剩余的栈中的元素。