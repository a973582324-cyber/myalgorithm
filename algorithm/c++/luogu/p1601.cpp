#include<iostream>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int a1[505]={0},b1[505]={0},c[505]{0};
    int len1=a.length();
    int len2=b.length();
    for(int i=0;i<a.length();i++)
        a1[i]=a[len1-1-i]-'0';
    for(int i=0;i<b.length();i++)
        b1[i]=b[len2-1-i]-'0';
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