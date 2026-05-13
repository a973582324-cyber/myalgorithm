#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
typedef long long ll;
int n;
ll a[MAX];ll b[MAX];
void discreat()
{
    for(int i = 1;i<=n;i++)b[i] = a[i];
    sort(b+1,b+n+1);
    int len = unique(b+1,b+n+1) - b - 1;
    for(int i = 1;i<=n;i++)
    {
        a[i] = lower_bound(b+1,b+1+len,a[i])-b;
    }
}
void discreat(vector<int>&a,vector<int>&b)
{
    b = a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i = 0;i<a.size();i++)
    {
        a[i] = lower_bound(b.begin(),b.end(),a[i])-b.begin();
    }
}