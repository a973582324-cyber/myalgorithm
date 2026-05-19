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
    string s;
    cin>>s;
    char c;
    c = s[0];
    for(int i = 2;i>=0;i--)
    {
        for(int j = i;j>0;j--)
            cout<<' ';
        cout<<s<<endl;
        s = c+s+c;
    }
}