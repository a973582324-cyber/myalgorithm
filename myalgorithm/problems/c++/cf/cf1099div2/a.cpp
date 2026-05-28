#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
void solve()
{  
    int n;
    cin>>n;
    unordered_map<int,int>hs;
    vector<int>a;
    int num = 1;
    int len = 0;
    while(len!=n)
    {
        if(!hs.count(num)){
            a.push_back(num);
            len++;
            hs[num]++;
            if(len>1)
            hs[num + a[len-2]]++;
        }
        num++;
    }
    for(auto b:a)
    cout<<b<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
}