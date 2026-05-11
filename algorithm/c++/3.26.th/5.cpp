#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    long long x,y,k;
    cin>>x>>y>>k;
    while(k>0&&x!=1){
        long long a=y*(x/y+1)-x;
        a=min(k,a);
        x+=a;
        while(x%y==0){
            x/=y;
        }
        k-=a;
    }
    cout<<x+k%(y-1)<<'\n';
    }
}