#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int q[1005];
int main()
{
    int n,m;
    unordered_map<int,int>hs;
    queue<int>q;
    cin>>m>>n;
    int t;
    int ans = 0;
    int len = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>t;
        if(hs[t])
        {
            continue;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        else
        {
            if(q.size()!=m)
            {
                hs[t] = 1;
                q.push(t);
                ans++;
            }
            else
            {
                hs[t] = 1;
                hs[q.front()] = 0;
                q.pop();
                q.push(t);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}