#include<iostream>
using namespace std;
int n,k;
int ans[25];
string s="   ";
void dfs(int now,int x){
    if(x>k){
        for(int i=1;i<=k;i++){
            cout<<s<<ans[i];
        }
        cout<<endl;
        return;
    }
    for(int i=now;i<=n;i++){
        ans[x]=i;
        dfs(i+1,x+1);
        ans[x]=0;
    }
}
int main(){
    cin>>n>>k;
    dfs(1,1);
    return 0;
}