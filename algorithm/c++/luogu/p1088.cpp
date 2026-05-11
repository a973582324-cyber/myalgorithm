#include<iostream>
using namespace std;
int n;
int mar[100005];
int m;
int c[100005];
int ans[100005];
int k=0;
bool temp=false;
void dfs(int x){
    if(temp)
    return;
    if(x>n){
        k++;
        if(k==m+1){
            temp=true;
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<' ';
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!k)
            i=mar[x];
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
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>mar[i];
    }
    dfs(1);
  
}