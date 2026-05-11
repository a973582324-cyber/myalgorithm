#include<iostream>
using namespace std;
const int N=100005;
int a[N];
void solve(){
    int x,y,n;
    cin>>n>>x>>y;
    int tem=-1;
    for(int i=y-1;i>=1;i--)
    {
        a[i]=tem;
        tem*=-1;
    }
    tem=-1;
    for(int i=x+1;i<=n;i++){
        a[i]=tem;
        tem*=-1;
    }
    for(int i=y;i<=x;i++){
        a[i]=1;
    }
    for(int i=1;i<=n;i++)
    cout<<a[i]<<' ';
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}