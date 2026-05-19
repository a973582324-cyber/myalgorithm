#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x = a*60+b;
    int y = c*60+d;
    int ans = y-x;
    cout<<ans/60<<' '<<ans%60;
}