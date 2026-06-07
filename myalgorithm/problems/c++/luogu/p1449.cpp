//本题目思路，遇见.将前面的数压入栈，遇见运算符时将栈顶的两个元素按照要求进行运算
//每次计算完一次，就将结果入栈，往复往复
//最终栈顶元素就是结果
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
    int s = 0,x = 0,y = 0;
    char ch;
    stack<int>q;
    while(ch!='@')
    {
        ch = getchar();
        switch (ch)
        {
        case '+': 
            x = q.top();
            q.pop();
            y = q.top();
            q.push(x+y);
            break;
        case '*':
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(x*y);
            break;
        case '-':
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(y-x);
            break;
        case '/':
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(y/x);
            break;
        case '.':
            q.push(s);
            s = 0;
            break;
        default:    
            s = s*10+ch-'0';
            break;
        }
    }
    cout<<q.top()<<endl;
    return 0;
}