// 小写英文字母 Trie：trie[u][c] 是字符 c 对应的子节点编号。
// wordCount 只统计完整单词出现次数，插入和查询均为 O(字符串长度)。
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int trie[N][26],wordCount[N],nodeCount;

void insert(string s)
{
    int now = 0;
    for(char ch:s)
    {
        int c = ch-'a';
        if(!trie[now][c])trie[now][c] = ++nodeCount;
        now = trie[now][c];
    }
    wordCount[now]++;
}

int find(string s)
{
    int now = 0;
    for(char ch:s)
    {
        int c = ch-'a';
        if(!trie[now][c])return 0;
        now = trie[now][c];
    }
    return wordCount[now];
}

int main(){return 0;}
