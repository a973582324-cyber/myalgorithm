#include<iostream>
#include<cmath>
using namespace std;
long long fastpow(int x,int y){
    int ans=1;
    x%=9;
    while(y>0){
        if(y%2!=0)
        ans=(ans*x)%9;
        x=(x*x)%9;
        y/=2;
    }
    return ans;
}
int main(){
    long long n;
    while(1)
    {
        cin>>n;
        if(n==0)
        break;
        long long num=fastpow(n,n)  ;
        if(num%9==0)
        cout<<9<<endl;
        else
        cout<<num%9<<endl;
    }
}