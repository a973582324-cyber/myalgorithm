#include<iostream>
using namespace std;
int n;
int a[5];
int b[1005]={6,2,5,5,4,5,6,3,7,6};
int ans=0;
void dfs(int x,int sum){
    if(sum>n)
        return;
    if(x>3){
        if(sum==n&&a[1]+a[2]==a[3]){
            ans++;
        }
        return;
    }
    for(int i=0;i<1000;i++){
        a[x]=i;
        dfs(x+1,sum+b[i]);
        a[x]=0;
    }
}
int main(){
    cin>>n;
    n-=4;
    for(int i=10;i<1000;i++){
        b[i]=b[i%10]+b[i/10];
    }
    dfs(1,0);
    cout<<ans;
}