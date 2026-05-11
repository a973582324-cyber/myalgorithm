#include<iostream>
using namespace std;
#define ll long long
ll a[100005];
int main(){
    ll n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]+a[i-1]>x){
            ans+=a[i]+a[i-1]-x;
            a[i]=a[i]-(a[i]+a[i-1]-x);
        }
    }
    cout<<ans<<endl;
}