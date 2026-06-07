#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
const int minn = INF;
string ans[5];
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> d[10] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},  // 0
        {"..X", "..X", "..X", "..X", "..X"},  // 1
        {"XXX", "..X", "XXX", "X..", "XXX"},  // 2
        {"XXX", "..X", "XXX", "..X", "XXX"},  // 3
        {"X.X", "X.X", "XXX", "..X", "..X"},  // 4
        {"XXX", "X..", "XXX", "..X", "XXX"},  // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"},  // 6
        {"XXX", "..X", "..X", "..X", "..X"},  // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"},  // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"},  // 9
    };
    string s;
    cin>>s;
    for(int i = 0;i < 5;i++)//控制行数
    {
        for(int j = 0;j < n;j++)//输出第i+1行的第j+1个字母的第i+1行的字符串
        {
            int t = s[j] - '0';
            cout<<d[t][i];
            if(j < n-1)cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}