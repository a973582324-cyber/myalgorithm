// 64 位自然溢出的多项式字符串哈希，hashValue 与 powerValue 都采用 1-based 前缀。
// 预处理 O(n)，之后 getHash 可在 O(1) 内取得闭区间 [l,r] 的哈希值。
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull BASE = 131;

vector<ull>hashValue,powerValue;

void initHash(string s)
{
    int n = s.size();
    hashValue.resize(n+1,0);
    powerValue.resize(n+1,1);
    for(int i = 1;i<=n;i++)
    {
        hashValue[i] = hashValue[i-1]*BASE+s[i-1];
        powerValue[i] = powerValue[i-1]*BASE;
    }
}

//得到子串[l,r]的哈希值，下标从1开始
ull getHash(int l,int r)
{
    return hashValue[r]-hashValue[l-1]*powerValue[r-l+1];
}

int main(){return 0;}
