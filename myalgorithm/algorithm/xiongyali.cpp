#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 505;
int k,n,m;
int ma[N],u[N];
vector<int>l[N];
int dfs(int v)
{
	for(auto a:l[v])
    {
		if(u[a])continue;
        u[a] = 1;
        if(!ma[a]||dfs(ma[a]))
        {
			ma[a] = v;
            return 1;
        }
    }
    return 0;
}
int main()
{
	while(cin>>k)
    {
        if(k==0)
            break;
		cin>>m>>n;
        int a,b;
        memset(ma,0,sizeof ma);
        for(int i = 1;i<=m;i++)l[i].clear();
        for(int i = 1;i<=k;i++)
        {
            cin>>a>>b;
			l[a].push_back(b);
        }
        int ans = 0;
		for(int i = 1;i<=m;i++)
        {
			memset(u,0,sizeof u);
            if(dfs(i))ans++;
        }
        cout<<ans<<endl;
    }

}