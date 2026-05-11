#include<iostream>
#include<cmath>
using namespace std;
int a[25];int n;
int ans=0;
int k;
bool issu(int x){
    if(x<2)
    return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)
        return false;
    }
    return true;
}
void dfs(int num,int sum,int index){
    if(num==k){
        if(issu(sum)){
        ans++;
        }
        return;
    }
    for(int i=index;i<n;i++){
        dfs(num+1,sum+a[i],i+1);
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans<<endl;
}