#include<iostream>
using namespace std;
int main(){
    string a="abcbcaabcabc";
    string b="abcabc";
    int i=0;
    int j=-1;
    int next[5005];
    next[0]=-1;
    while(i<b.size()){
        if(j==-1||b[i]==b[j])next[++i]=++j;
        else
        j=next[j];
    }
    for(i=0;i<b.size();i++)
    cout<<next[i]<<' ';
    i=0,j=0;
    while(i<a.size()){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            if(j>1)
            j=next[j];
            else
            i++;
        }
        if(j==b.size())
        return 0;
    }
}