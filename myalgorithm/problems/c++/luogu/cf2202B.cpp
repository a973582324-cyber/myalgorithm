#include<iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    if(n%2==1){
        if(s[0]=='b'){
            cout<<"no"<<endl;
            return;
        }
        i++;
    }
    for(;i<n;i+=2){
        if(s[i]==s[i+1]&&s[i]!='?'&&s[i+1]!='?'){
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}