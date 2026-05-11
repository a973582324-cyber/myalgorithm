#include<iostream>
using namespace std;
#define mod 998244353
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    ll temp=(2*k+1)%mod;
    while(n>0){
        if(n%2!=0){
            ans=(ans*temp)%mod;
        }
        temp=(temp*temp)%mod;
        n/=2;
    }
    cout<<ans<<endl;
}