#include<iostream>
using namespace std;
int a[30005];
void solve(){
    int n;
    cin >> n;
    long long ans=n;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        if(a[i]==ans-i+1)
            ans+=i-1;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}