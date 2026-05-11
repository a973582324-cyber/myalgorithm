#include<iostream>
using namespace std;
int vv[2000005]={0};
int ww[2000005]={0};
int main(){
    int n,m;
    cin>>n>>m;
    int v,w,s;
    int num=0;
    for(int i=0;i<n;i++){
        cin>>v>>w>>s;
        for(int j=1;j<=s;j<<=1){
            vv[num]=j*v;
            ww[num++]=j*w;
            s-=j;
        }
        if(s){
            vv[num]=s*v;
            ww[num++]=s*w;
        }
    }
    int dp[2005]={0};
    for(int i=0;i<num;i++){
        for(int j=m;j>=vv[i];j--)
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
    }
    cout<<dp[m]<<endl;
}