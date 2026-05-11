#include<iostream>
using namespace std;
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    long long a1=a,b1=b;
    long long ans=1;
    while(b1){
        if(b1&1){
            ans=(ans*a1)%p;
        }
        a1=(a1*a1)%p;
        b1/=2;
    }
    cout<<a<<'^'<<b<<' '<<"mod"<<' '<<p<<'='<<ans;
}