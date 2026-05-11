#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int a[2005]={0};
    int b[2005]={0};
    int c[4004]={0};
    for(int i=0;i<s1.length();i++)
        a[i]=s1[s1.length()-i-1]-'0';
    for(int i=0;i<s2.length();i++)
        b[i]=s2[s2.length()-i-1]-'0';
    for(int i=0;i<s2.length();i++){
        for(int j=0,index=i;j<s1.length();j++){
            c[j+i]+=a[j]*b[i];
            if(c[j+i]>=10){
                c[j+i+1]+=c[j+i]/10;
                c[j+i]%=10;
            }
        }
    }
    int len=s1.length()+s2.length();
    int index=0;
    for(int i=len-1;i>=0;i--){
        if(c[i]!=0){
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;i--){
        cout<<c[i];
    }
}