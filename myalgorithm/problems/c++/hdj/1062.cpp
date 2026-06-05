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
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char c;
        stack<char>q;
        while((c = getchar())!='\n')
        {
            if(c == ' ')
            {
                while(!q.empty())
                {
                    cout<<q.top();
                    q.pop();
                }
                cout<<' ';
            }
            else
            {
                q.push(c);
            }
        }
        while(!q.empty())
        {
            cout<<q.top();
            q.pop();
        }
        cout<<endl;
    }
}