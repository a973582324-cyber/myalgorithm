#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int minn = -1e6;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n,-1);
    for(int i=0;i<n;i++) 
    {
        
    }
    queue<int>q;
    string s1 = "push";
    string s2 = "pop";
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        if(s==s1)
        {
            int x;
            cin>>x;
            q.push(x);
        }
        else if(s==s2)
        {
            if(!q.empty()) q.pop();
        }
    }
}