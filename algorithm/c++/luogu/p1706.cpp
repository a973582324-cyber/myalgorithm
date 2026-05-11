#include<iostream>
using namespace std;
const int N=20;
bool c[N];
int ans[N]={0};
int n;
string a={"    "};
void dfs(int x){
    if(x>n){
        cout<<a;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<a;
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
            c[i]=true;
            ans[x]=i;
            dfs(x+1);
            ans[x]=0;
            c[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    dfs(1);
}