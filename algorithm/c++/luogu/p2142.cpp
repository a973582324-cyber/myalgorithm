#include<iostream>
using namespace std;
int main(){
    string a,b;
    int temp=1;
    int a1[10090]={0},a2[10090]={0},a3[10090]={0};
    cin>>a>>b;
    int len1=a.length();
    int len2=b.length();
    if(len1<len2||len1==len2&&a<b){
        swap(a,b);
        swap(len1,len2);
        temp=0;
    }
    for(int i=0;i<len1;i++)
        a1[i]=a[len1-i-1]-'0';
    for(int i=0;i<len2;i++)
        a2[i]=b[len2-i-1]-'0';
    int len=max(len1,len2);
    for(int i=0;i<len;i++){
        a3[i]+=a1[i]-a2[i];
        if(a3[i]<0){
        a3[i]+=10;
        a3[i+1]-=1;  
        }  
    }
    if(!temp)
    cout<<'-';
    int index=0;
    for(int i=len-1;i>=0;i--)
        if(a3[i]!=0){
            index=i;
            break;
        }    
    for(int i=index;i>=0;i--)
        cout<<a3[i];
}