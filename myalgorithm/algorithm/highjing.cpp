#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int a1[505]={0},b1[505]={0},c[505]{0};
    int len1=a.size();
    int len2=b.size();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int len=max(len1,len2);
    for(int i=0;i<len;i++){
        c[i]+=a1[i]+b1[i];
        if(c[i]>=10){
            c[i+1]+=1;
            c[i]%=10;
        }
    }
    if(c[len]!=0)
        len++;
    for(int i=len-1;i>=0;i--)
        cout<<c[i];
    
}