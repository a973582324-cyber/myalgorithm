#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,n,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        int ans=n-(n/w);
        cout<<ans<<endl;
    }
}