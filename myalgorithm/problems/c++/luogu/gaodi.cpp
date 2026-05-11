#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int b;
    int a[505];
    cin>>b;
    for(int i=0;i<s.length();i++){
        a[i]=s[s.length()-i-1]-'0';
        a[i]*=b;
    }
    for(int i=0;i<s.length()+4;i++){
        if(a[i]>=10){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    int index=0;
    for(int i=s.length()+4-1;i>=0;i--){
        if(a[ i]!=0){
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;i--){
        cout<<a[i];
    }
}