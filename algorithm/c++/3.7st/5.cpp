#include<iostream>
#include<string>
using namespace std;
int main(){ 
    int n;
    string s;
    cin>>n;
    cin>>s;
    int st=0,end=1,k=1;
    int temp =1;
    for(int i=0;i<n-1;i++)
        if(s[i]!=s[i+1]){
            cout<<"yes"<<endl;
            cout<<s[i]<<s[i+1];
            temp=0;
            break;
        }
    if(temp==1)
        cout<<"no";
    return 0;
}