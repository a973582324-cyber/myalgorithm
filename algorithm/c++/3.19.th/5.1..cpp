#include<iostream>
using namespace std;
#define MOD 998244353
int main(){
    long long n,k;
    cin>>n>>k;
    long long temp=(2*k+1)%MOD;
    long long ans=1;
    while(n>0){
        if(n%2!=0){
            ans=(ans*temp)%MOD;
        }
        temp=(temp*temp)%MOD;
        n/=2;
    }
    cout<<ans<<endl;
}