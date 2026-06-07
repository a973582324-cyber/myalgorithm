#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int minn = -1e7;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char>q;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == ')')
        {
            if(q.empty())
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else 
            {
                q.pop();
            }
        }
        else if(s[i] == '(')
        {
            q.push('(');
        }
    }
    if(!q.empty())cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}