#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int temp=0;
        while(n>0){
            if(n%10==5||n%10==0){
                temp=1;
                break;
            }
            n/=10;
        }
        if(temp)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}