#include<iostream>
using namespace std;
int n;
int ans[15];
int c[15];
string s="    ";
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<<s<<ans[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
        c[i]=1;
        ans[x]=i;
        dfs(x+1);
        ans[x]=0;
        c[i]=0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
}