#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int MOD = 10000;
const int minn = -1e7;
//0xcf = 207用于初始化最小值，-1e7更大，可以避免溢出
//这道题由于只有加法和乘法，可以先把第一个放入栈顶，之后依次读入数字和运算符
//先判断运算符是否是乘法，如果是乘就将栈顶元素乘新数，不是就把数字入栈，
//读完之后，建立一个ans，把ans加上栈的每个元素，也可以将栈顶元素两两相加后再入栈
//但是第二种方法相对麻烦，第一种简便
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int>q;
    char ch;
    int ans = 0,num;
    cin>>num;
    q.push(num);
    while(cin>>ch>>num)
    {
        if(ch=='*')
        {
            int x = q.top();
            q.pop();
            q.push(x * num % MOD);
        }
        else
            q.push(num % MOD);
    }
    while(!q.empty())
    {
        ans = ans + q.top()%MOD;
        ans %= MOD;
        q.pop();
    }
    cout<<ans%MOD<<endl;
    return 0;
}