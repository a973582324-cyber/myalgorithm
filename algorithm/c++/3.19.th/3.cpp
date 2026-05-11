#include<iostream>
#include<vector>
using namespace std;
char a[300002][300002];
char root[300003][3]={};
int n,m;
int dfs(int x,int y,int k){
    if(x==n&&y==m){
        return 
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int ans=dfs(0,0,0);
    }


}