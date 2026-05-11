#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
    return a>b;
}
struct root{
    ll l;
    ll r;
};
int main(){
    int t,n,k;
    cin>>t; 
    while(t--){
        cin>>n>>k;
        ll ans=0;
        vector<root>a(n);
        vector<ll>b(n);
        for(int i=0;i<n;i++)
            cin>>a[i].l;
        for(int i=0;i<n;i++){
            cin>>a[i].r;
            b[i]=min(a[i].r,a[i].l);
        }
        sort(b.begin(),b.end(),cmp);
        for(int i=0;i<k-1;i++){
            ans+=b[i];
        }
        for(int i=0;i<n;i++){
            ans+=max(a[i].l,a[i].r);
        }
        ans++;
        cout<<ans<<endl;
    }

    return 0;
}