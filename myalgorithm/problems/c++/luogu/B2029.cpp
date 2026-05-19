#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const double PI = 3.14;
int r,h;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>r;
    int sum = 20000;
    double s = PI*r*r*h;
    int ans = ceil((int)sum/s);
    cout<<ans<<endl;
}